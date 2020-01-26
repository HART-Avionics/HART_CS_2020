//
// Created by lunng on 1/26/20.
//

#include <cassert>
#include "TelemKalmanVoltage.h"

uint8_t TelemKalmanVoltage::get_state(){
    return this->state;
}
int16_t TelemKalmanVoltage::get_v_batt(){
    return this->v_batt;
}
int16_t TelemKalmanVoltage::get_v_pyro(){
    return this->v_pyro;
}
int8_t  TelemKalmanVoltage::get_sense(int index){
    assert(index >= 0 && index < 6);
    return this->sense[index];
}
int32_t TelemKalmanVoltage::get_ground_pres(){
    return this->ground_pres;
}
int16_t TelemKalmanVoltage::get_ground_accel(){
    return this->ground_accel;
}
int16_t TelemKalmanVoltage::get_accel_plus_g(){
    return this->accel_plus_g;
}
int16_t TelemKalmanVoltage::get_accel_minus_g(){
    return this->accel_minus_g;
}
int16_t TelemKalmanVoltage::get_acceleration(){
    return this->acceleration;
}
int16_t TelemKalmanVoltage::get_speed(){
    return this->speed;
}
int16_t TelemKalmanVoltage::get_height(){
    return this->height;
}