//
// Created by lunng on 1/22/20.
//

#include "TelemSensorData.h"

#include <utility>
#include <cassert>

TelemSensorData::TelemSensorData(std::string input_val) : TelemString(std::move(input_val)){
    update_values();
}

uint8_t TelemSensorData::get_orient(){
    return this->orient;
}
int16_t TelemSensorData::get_accel(){
    return this->accel;
}
int32_t TelemSensorData::get_pres(){
    return this->pres;
}
int16_t TelemSensorData::get_temp(){
    return this->temp;
}
int16_t TelemSensorData::get_accel_x(){
    return this->accel_x;
}
int16_t TelemSensorData::get_accel_y(){
    return this->accel_y;
}
int16_t TelemSensorData::get_accel_z(){
    return this->accel_z;
}
int16_t TelemSensorData::get_gyro_x(){
    return this->gyro_x;
}
int16_t TelemSensorData::get_gyro_y(){
    return this->gyro_y;
}
int16_t TelemSensorData::get_gyro_z(){
    return this->gyro_z;
}
int16_t TelemSensorData::get_mag_x(){
    return this->mag_x;
}
int16_t TelemSensorData::get_mag_y(){
    return this->mag_y;
}
int16_t TelemSensorData::get_mag_z(){
    return this->mag_z;
}

void TelemSensorData::update_values() {
    assert(this->get_mode() == MODE_SD);
    this->orient = get_uint8_val(6);
    this->accel = get_int16_val(7);
    this->pres = get_int32_val(9);
    this->temp = get_int16_val(13);
    this->accel_x = get_int16_val(15);
    this->accel_y = get_int16_val(17);
    this->accel_z = get_int16_val(19);
    this->gyro_x = get_int16_val(21);
    this->gyro_y = get_int16_val(23);
    this->gyro_z = get_int16_val(25);
    this->mag_x = get_int16_val(27);
    this->mag_y = get_int16_val(29);
    this->mag_z = get_int16_val(31);
}
