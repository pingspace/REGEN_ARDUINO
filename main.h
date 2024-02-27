/**
 * @file main.h
 * @brief main header
 * @copyright
 * @author Asril Aizal <asril.aizal@pingspace.co>
 */

#ifndef MAIN_H
#define MAIN_H

struct regen_header_st
{
    uint8_t head_byte;
    uint8_t cmd_byte;
    uint8_t data_len;
} __attribute__((__packed__));

struct regen_send_cmd_st
{
    struct regen_header_st header;
    uint8_t sensor_1;
    uint8_t sensor_2;
    uint8_t reserve[13];
    uint16_t crc_checksum;
} __attribute__((__packed__));

#endif