//
// Created by lunng on 1/21/20.
//

#include <string>
#include <iostream>
#include <utility>
#include <fstream>
#include "TelemParser.h"


bool TelemParser::telem_string_valid(std::string test_string) {
    std::string s("TELEM ");

    if(test_string.rfind(s, 0) != 0){
        return false;
    }

    test_string.erase(0, s.length());

    std::string lqi = test_string.substr(test_string.length()-4, 2);
    std::cout << "lqi: "<< std::hex << lqi << std::endl;

    if(!((unsigned short) 0b00000001 & (unsigned short) stoul(lqi, nullptr, 16))){
        return false;
    }

    ; // Placeholder in case we need to do any more work

    return true;
}

void TelemParser::Start() {
    this->running = true;
    this->file_reader = std::thread(&TelemParser::do_work, this);
}

TelemParser::TelemParser(std::string filename) : file_reader() {
    this->input_file = std::move(filename);
    this->TGPS = nullptr;
    this->TKV = nullptr;
    this->TSD = nullptr;
    this->running = false;
    this->data_valid = false;
    initialize();
}

TelemParser::~TelemParser(){
    this->running = false;
    if(this->file_reader.joinable()) this->file_reader.join();
}

void TelemParser::do_work() {
    std::ifstream fin;
    std::string lastLastLine;


    int lines_read = 0;
    while(this->running){
        fin.open(this->input_file);

        // loop is adapted from a script written for stackoverflow
        // https://stackoverflow.com/questions/11876290/c-fastest-way-to-read-only-last-line-of-text-file


        if(fin.is_open()) {
            fin.seekg(-1,std::ios_base::end);           // go to one spot before the EOF

            bool counted = false;
            int loops = 0;
            while(true) {
                char ch;
                fin.get(ch);                        // Get current byte's data

                if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
                    fin.seekg(0);                       // The first line is the last line
                    break;                              // So stop there

                }
                else if(ch == '\n') {                   // If the data was a newline
                    if(counted) break;
                    fin.seekg(-2,std::ios_base::cur);   // Move to the front of that data, then to the front of the data before it
                    counted = true;                     // Get the next to last line.
                }
                else {                                  // If the data was neither a newline nor at the 0 byte
                    fin.seekg(-2,std::ios_base::cur);   // Move to the front of that data, then to the front of the data before it
                }
            }

            std::string lastLine;
            getline(fin,lastLine);               // Read the current line
            if(lastLastLine != lastLine && !lastLine.empty()){
                std::cout << "Result: " << lastLine << '\n';     // Display it
                lastLastLine = lastLine;
                lines_read++;
            }

            fin.close();
        }
    }
}

void TelemParser::initialize() {
    std::ifstream fin;
    std::string line_in;

    fin.open(this->input_file);
    while(!fin.eof()){
        getline(fin,line_in);               // Read the current line

        if(telem_string_valid(line_in)){
            int mode = TelemString::get_mode(line_in);

            // Update the stored data
            switch(mode) {
                case MODE_GPS:
                    if (this->TGPS == nullptr) {
                        this->TGPS = new TelemGPS(line_in);
                    } else {
                        this->TGPS->update_string(line_in);
                        this->TGPS->update_values();
                    }
                    break;

                case MODE_KV:
                    if (this->TKV == nullptr) {
                        this->TKV = new TelemKalmanVoltage(line_in);
                    } else {
                        this->TKV->update_string(line_in);
                        this->TKV->update_values();
                    }
                    break;

                case MODE_SD:
                    if (this->TSD == nullptr){
                        this->TSD = new TelemSensorData(line_in);
                    } else {
                        this->TSD->update_string(line_in);
                        this->TSD->update_values();
                    }
                    break;

                default:
                    std::cout << line_in << " has unsupported mode: " << mode << std::endl;
            }
        }
    }

    this->reader_location = fin.tellg();
    fin.close();

}
