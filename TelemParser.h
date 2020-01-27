//
// Created by lunng on 1/21/20.
//

#ifndef TELEREADERPROJ_TELEMPARSER_H
#define TELEREADERPROJ_TELEMPARSER_H

#include <string>
#include <thread>
#include "TelemStringTypes/TelemGPS.h"
#include "TelemStringTypes/TelemSensorData.h"
#include "TelemStringTypes/TelemKalmanVoltage.h"


class TelemParser {
private:
    std::string lastString;
    std::string input_file;

    std::thread file_reader;

    TelemGPS *TGPS;
    TelemSensorData *TSD;
    TelemKalmanVoltage *TKV;

    bool running;
    bool data_valid;

public:
    explicit TelemParser(std::string);
    ~TelemParser();

    TelemParser(const TelemParser&) = delete;
    TelemParser& operator=(const TelemParser&) = delete;

    void do_work();

    static bool telem_string_valid(std::string);

    void Start();

};


#endif //TELEREADERPROJ_TELEMPARSER_H
