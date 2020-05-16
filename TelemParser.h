/**
 * file: TelemParser.h
 *
 * description: parser class for creating a parser thread that will read test from an altus metrum telemetry file and
 *              provide data to the user defined program. Designed as a package that can be imported to your project
 *
 * project: HART_CS_2020
 *
 * author: Grayland Lunn
 * Contact: lunng@oregonstate.edu
 *
 */

#ifndef TELEREADERPROJ_TELEMPARSER_H
#define TELEREADERPROJ_TELEMPARSER_H

#include <string>
#include <thread>
#include <mutex>

#include "TelemStringTypes/TelemGPS.h"
#include "TelemStringTypes/TelemSensorData.h"
#include "TelemStringTypes/TelemKalmanVoltage.h"


class TelemParser {
private:
    // Variables for reading the data file
    std::string input_file;
    std::streampos reader_location;

    // Data storage variables
    TelemGPS *TGPS;
    TelemSensorData *TSD;
    TelemKalmanVoltage *TKV;

    // Variables for threading
    std::thread file_reader;
    std::mutex iostream_mutex;
    bool running;

public:
    explicit TelemParser(std::string);
    ~TelemParser();

    // Get rid of default class methods that we can't have (because of the threading aspect)
    TelemParser() = delete;
    TelemParser(const TelemParser&) = delete;
    TelemParser& operator=(const TelemParser&) = delete;

    // File handlers
    void fill_data(const std::string&);
    void initialize();
    void read_new_data();

    // Thread init
    void Start();

    // Utility
    void dump_data();
    static bool telem_string_valid(std::string);

    // Getters Section, add the data types that you need, copy function template for get_acceleration()
    int16_t get_acceleration();


};


#endif //TELEREADERPROJ_TELEMPARSER_H
