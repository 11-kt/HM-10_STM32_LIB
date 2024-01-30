/*
 * AT_Command.h
 *
 *  Created on: Jan 30, 2024
 *      Author: Andrianov Vitaly
 */

#ifndef INC_AT_COMMAND_H_
#define INC_AT_COMMAND_H_

#include "stm32l1xx_hal.h"

typedef enum {
	AT,
	RESET1,
	RENEW,
	BAUD_GET,
	BAUD_SET,
	CONN,
	IMME_GET,
	IMME_SET,
	NAME_GET,
	NAME_SET,
	ROLE_GET,
	ROLE_SET,
	START
} AT_commands;

enum Baud {
	BAUD_9600,
	BAUD_19200,
	BAUD_38400,
	BAUD_57600,
	BAUD_115200
};

enum Role {
	SLAVE,
	MASTER
};

enum Imme {
	BASE,
	ONLY_AT
};

struct AT_command {
	char * command;
	int res_len;
};

uint8_t * getCommand(AT_commands command);
uint8_t getResLength(AT_commands command);

#endif /* INC_AT_COMMAND_H_ */
