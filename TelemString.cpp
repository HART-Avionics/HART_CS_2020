//
// Created by lunng on 1/21/20.
//

#include <string>
#include <cassert>
#include "TelemString.h"

#define SN_OFFSET 1
#define TICK_OFFSET 3
#define MODE_OFFSET 5



std::string TelemString::get_bytes(int first_byte, int last_byte){
    // Note: each byte is 2 characters, 0 indexed get bytes [first,last]
    assert(this->_telem_data.length() > last_byte * 2 + 1);
    return(this->_telem_data.substr(first_byte * 2, (last_byte - first_byte + 1) * 2 ));
}

TelemString::TelemString(std::string line_in) {
    std::string s("TELEM ");
    assert(line_in.rfind(s, 0) == 0);
    this->_telem_data = line_in.erase(0, s.length());

    this->serial = get_uint16_val(SN_OFFSET);
    this->tick = get_uint16_val(TICK_OFFSET);
    this->mode = get_uint8_val(MODE_OFFSET);
}

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

int16_t TelemString::get_int16_val(int byte_index) {
    std::string data = get_ordered_bytes(byte_index, byte_index + 1);
    int16_t value = std::stoi(data, nullptr, 16);
    return value;
}

int32_t TelemString::get_int32_val(int byte_index) {
    std::string data = get_ordered_bytes(byte_index, byte_index + 3);
    int32_t value = std::stoi(data, nullptr, 16);
    return value;
}

int TelemString::get_mode(std::string line_in) {
    line_in.erase(0, 6);
    std::string val = line_in.substr(MODE_OFFSET * 2, 2 );

    return std::stoi(val);
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