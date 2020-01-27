#include <iostream>
#include <fstream>
#include <sstream>

#include "TelemString.h"
#include "TelemStringTypes/TelemSensorData.h"
#include "TelemStringTypes/TelemKalmanVoltage.h"
#include "TelemStringTypes/TelemGPS.h"
#include "TelemParser.h"

using namespace std;

int main() {
//    string filename = "/home/lunng/TeleMetrum/2020-01-13-serial-3083-flight-0024-via-2881.telem";
//    ifstream fin;
//    string lastLastLine;
//
//
//    int lines_read = 0;
//    while(lines_read < 19){
//        fin.open(filename);
//
//        // loop is adapted from a script written for stackoverflow
//        // https://stackoverflow.com/questions/11876290/c-fastest-way-to-read-only-last-line-of-text-file
//
//
//        if(fin.is_open()) {
//            fin.seekg(-1,ios_base::end);                // go to one spot before the EOF
//
//            bool counted = false;
//            int loops = 0;
//            while(true) {
//                char ch;
//                fin.get(ch);                            // Get current byte's data
//
//                if((int)fin.tellg() <= 1) {             // If the data was at or before the 0th byte
//                    fin.seekg(0);                       // The first line is the last line
//                    break;                              // So stop there
//
//                }
//                else if(ch == '\n') {                   // If the data was a newline
//                    if(counted) break;
//                    fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
//                    counted = true;                     // Get the next to last line.
//                }
//                else {                                  // If the data was neither a newline nor at the 0 byte
//                    fin.seekg(-2,ios_base::cur);        // Move to the front of that data, then to the front of the data before it
//                }
//            }
//
//            string lastLine;
//            getline(fin,lastLine);               // Read the current line
//            if(lastLastLine != lastLine && !lastLine.empty()){
//                cout << "Result: " << lastLine << '\n';     // Display it
//                lastLastLine = lastLine;
//                lines_read++;
//            }
//
//            fin.close();
//        }
//    }

//    TelemString test_string("TELEM 220b0cb52805b44200b349911a33bc85b614010e00241a362527011d000f000000f485a3");
//    TelemSensorData test_data("TELEM 220b0cf4070801f607b987010099095c02af07f8fffdff1b00f6ff7b000e01c301f28733");
//    TelemKalmanVoltage test_kalman("TELEM 220b0cf7070902e10c4604000000000000c8870100f507f6071a08fefffaff0000f6868e");
//    TelemGPS test_gps("TELEM 220b0cdf0705201d23062925189a62659c14010e002302e7e7e701000000000000f687a0");
//
//    TelemParser::telem_string_valid("asjdkfhaureog");
//    cout << "test_string.mode " << test_string.get_mode() << " test_string bytes 1-3 " << test_string.get_bytes(1,3) << "\n";
//    cout << "test data orient:" << (unsigned int) test_data.get_orient() << "\n" <<
//        "test data time:" << (unsigned int) test_data.get_tick() << "\n" <<
//        "test data serial:" << (unsigned int) test_data.get_serial() << "\n" <<
//        "test data accel: " << test_data.get_accel() << "\n" <<
//        "test data mag_z: " << test_data.get_mag_z() << "\n";
//    cout << "test kalman state:" << (unsigned int) test_kalman.get_state() << "\n" <<
//         "test kalman ground pressure:" << test_kalman.get_ground_pres() << "\n" <<
//         "test kalman ground accel:" << test_kalman.get_ground_accel() << "\n" <<
//         "test kalman height: " << test_kalman.get_height() << "\n";
//    cout << "test GPS altitude:" << (unsigned int) test_gps.get_altitude() << "\n" <<
//         "test GPS latitude:" << test_gps.get_latitude() << "\n" <<
//         "test GPS ground speed:" << test_gps.get_ground_speed() << "\n" <<
//         "test GPS course: " << (unsigned int) test_gps.get_course() << "\n";
    return 0;
}