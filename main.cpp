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

    // Example for how to initialize this parser
    string filename = "../Data/2020-01-27-serial-3083-flight-0024-via-2881.telem";
    TelemParser parser(filename);
    parser.Start();

    // Getters for the parser have not yet been programmed

    parser.dump_data();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}