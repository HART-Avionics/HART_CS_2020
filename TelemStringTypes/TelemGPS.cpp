//
// Created by lunng on 1/26/20.
//

#include <cassert>
#include "TelemGPS.h"

TelemGPS::TelemGPS(std::string input_val) : TelemString(std::move(input_val)){
    update_values();
}

uint8_t TelemGPS::get_flags(){
    return this->flags;
}

int16_t TelemGPS::get_altitude(){
    return this->altitude;
}

int32_t TelemGPS::get_latitude(){
    return this->latitude;
}

int32_t TelemGPS::get_longitude(){
    return this->longitude;
}

uint8_t TelemGPS::get_year(){
    return this->year;
}

uint8_t TelemGPS::get_month(){
    return this->month;
}

uint8_t TelemGPS::get_day(){
    return this->day;
}

uint8_t TelemGPS::get_hour(){
    return this->hour;
}

uint8_t TelemGPS::get_minute(){
    return this->minute;
}

uint8_t TelemGPS::get_second(){
    return this->second;
}

uint8_t TelemGPS::get_pdop(){
    return this->pdop;
}

uint8_t TelemGPS::get_hdop(){
    return this->hdop;
}

uint8_t TelemGPS::get_vdop(){
    return this->vdop;
}

uint8_t TelemGPS::get_gps_mode(){
    return this->mode;
}

uint16_t TelemGPS::get_ground_speed(){
    return this->ground_speed;
}

int16_t TelemGPS::get_climb_rate(){
    return this->climb_rate;
}

uint8_t TelemGPS::get_course(){
    return this->course;
}

void TelemGPS::update_values() {
    assert(this->get_mode() == MODE_GPS);

    this->flags = get_uint8_val(6);
    this->altitude = get_int16_val(7);
    this->latitude = get_int32_val(9);
    this->longitude = get_int32_val(13);
    this->year = get_uint8_val(17);
    this->month = get_uint8_val(18);
    this->day = get_uint8_val(19);
    this->hour = get_uint8_val(20);
    this->minute = get_uint8_val(21);
    this->second = get_uint8_val(22);
    this->pdop = get_uint8_val(23);
    this->hdop = get_uint8_val(24);
    this->vdop = get_uint8_val(25);
    this->mode = get_uint8_val(26);
    this->ground_speed = get_uint16_val(27);
    this->climb_rate = get_int16_val(29);
    this->course = get_uint8_val(31);
}
