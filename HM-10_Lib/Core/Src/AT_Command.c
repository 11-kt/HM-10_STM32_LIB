/*
 * AT_Command.c
 *
 *  Created on: Jan 30, 2024
 *      Author: Andrianov Vitaly
 */

#include "AT_command.h"

struct AT_command AT_command_list[] = {
		{"AT\r\n", 2},
		{"AT+RESET\r\n", 8},
		{"AT+RENEW\r\n", 8},
		{"AT+BAUD?\r\n", 8},
		{"AT+BAUD", 8},
		{"AT+CO\r\n", 10},
		{"AT+IMME?\r\n", 8},
		{"AT+IMME", 8},
		{"AT+NAME?\r\n", -1},
		{"AT+NAME", -1},
		{"AT+ROLE?\r\n", 8},
		{"AT+ROLE", 8},
		{"AT+START\r\n", 8}
};

uint8_t * getCommand(AT_commands command) {
	return (uint8_t *) AT_command_list[command].command;
}

uint8_t getResLength(AT_commands command) {
	return AT_command_list[command].res_len;
}