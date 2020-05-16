cmake_minimum_required(VERSION 3.15)
project(TeleReaderProj)

set(CMAKE_CXX_STANDARD 14)
# the next "SET" is used for gcc implementations on linux
#SET(CMAKE_CXX_FLAGS -pthread)

add_executable(TeleReaderProj main.cpp TelemParser.cpp TelemParser.h TelemString.cpp TelemString.h TelemStringTypes/TelemSensorData.cpp TelemStringTypes/TelemSensorData.h TelemStringTypes/TelemKalmanVoltage.cpp TelemStringTypes/TelemKalmanVoltage.h TelemStringTypes/TelemGPS.cpp TelemStringTypes/TelemGPS.h)