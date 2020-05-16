/**
 * file: TelemString.cpp
 *
 * project: HART_CS_2020
 *
 * author: Grayland Lunn
 * Contact: lunng@oregonstate.edu
 *
 */

#include <string>
#include <cassert>
#include <iostream>
#include <utility>
#include "TelemString.h"

#define SN_OFFSET 1
#define TICK_OFFSET 3
#define MODE_OFFSET 5


// Get the bytes for a specific range of bytes in the string
std::string TelemString::get_bytes(int first_byte, int last_byte){
    // Note: each byte is 2 characters, 0 indexed get bytes [first,last]
    assert(this->_telem_data.length() > last_byte * 2 + 1);
    return(this->_telem_data.substr(first_byte * 2, (last_byte - first_byte + 1) * 2 ));
}

// Initialize a new string
TelemString::TelemString(std::string line_in) {
    update_string(std::move(line_in));
}

// Reorder the bytes from little-endian to big endian for stol and stoul
std::string TelemString::get_ordered_bytes(int first, int last) {
    std::string bytes = get_bytes(first, last);
    std::string ordered_bytes;

    for(int byte = 0; byte*2 + 1 < bytes.length(); byte++ ){
        ordered_bytes = bytes.substr(byte * 2, 2).append(ordered_bytes);
    }

    return ordered_bytes;
}

uint8_t TelemString::get_uint8_val(int byte_index) {
    std::string byte = get_ordered_bytes(byte_index, byte_index);
    uint8_t value = std::stoul(byte, nullptr, 16);
    return value;
}

uint16_t TelemString::get_uint16_val(int byte_index) {
    std::string data = get_ordered_bytes(byte_index, byte_index + 1);
    uint16_t value = std::stoul(data, nullptr, 16);
    return value;
}

int8_t TelemString::get_int8_val(int byte_index) {
    std::string data = get_ordered_bytes(byte_index, byte_index);
    int8_t value = std::stoi(data, nullptr, 16);
    return value;
}

int16_t TelemString::get_int16_val(int byte_index) {
    std::string data = get_ordered_bytes(byte_index, byte_index + 1);
    int16_t value = std::stoi(data, nullptr, 16);
    return value;
}

int32_t TelemString::get_int32_val(int byte_index) {
    std::string data = get_ordered_bytes(byte_index, byte_index + 3);
    std::cout << data.c_str() << std::endl;
    int32_t value = 0;

    value = std::stoll(data, nullptr, 16);

    return value;
}

// get the mode byte
int TelemString::get_mode(std::string line_in) {
    line_in.erase(0, 6);
    std::string val = line_in.substr(MODE_OFFSET * 2, 2 );

    return std::stoi(val, nullptr, 16);
}

unsigned int TelemString::get_mode() {
    return this->mode;
}

unsigned int TelemString::get_tick() {
    return this->tick;
}

unsigned int TelemString::get_serial() {
    return this->serial;
}

// set new data values for the new telem string
void TelemString::update_string(std::string new_data) {
    std::string s("TELEM ");
    assert(new_data.rfind(s, 0) == 0);
    this->_telem_data = new_data.erase(0, s.length());

    this->serial = get_uint16_val(SN_OFFSET);
    this->tick = get_uint16_val(TICK_OFFSET);
    this->mode = get_uint8_val(MODE_OFFSET);
}

// print all of the data for this string
void TelemString::dump_string_info() {
    std::cout << "\nTELEM " << _telem_data << std::endl;
    std::cout <<
              "\t" << "Serial: " << get_serial() << std::endl <<
              "\t" << "Tick: " << get_tick() << std::endl <<
              "\t" << "Mode: " << get_mode() << std::endl;
}
