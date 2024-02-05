/*
 * HM10_Setup.h
 *
 *  Created on: Jan 31, 2024
 *      Author: Andrianov Vitaly
 */

#ifndef INC_HM10_SETUP_H_
#define INC_HM10_SETUP_H_

#include "stm32l1xx_hal.h"
#include "AT_Command.h"
#include <string.h>
#include "stdlib.h"

typedef enum {
	OK,
	RENEW_OK,
	RESET_OK,
	LOST_AT,
	HM10_ERROR
} setup_result;

setup_result checkConnection(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);
setup_result setBaudRate(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart, hm10_baud baudrate);
setup_result setRole(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart, hm10_role role);
setup_result setImme(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart, hm10_imme imme);

hm10_baud getBaudRate(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);
hm10_role getRole(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);
hm10_imme getImme(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);

setup_result renewDevice(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);
setup_result resetDevice(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);
setup_result startHM10(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart);

char* concat_str(char * cmd, char mode);
void clearingBuf();

#endif /* INC_HM10_SETUP_H_ */
