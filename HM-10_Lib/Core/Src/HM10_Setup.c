/*
 * HM10_Setup.c
 *
 *  Created on: Jan 31, 2024
 *      Author: Andrianov Vitaly
 */

#include "HM10_Setup.h"

static char dma_res[30];

setup_result checkConnection(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart) {
	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(AT));
	HAL_UART_Transmit(huart, getCommand(AT), strlen((char *) getCommand(AT)), 0xFFFF);

	HAL_TIM_Base_Start(htim);

	if (strcmp (dma_res, "OK") != 0) return LOST_AT;

	return OK;
}

setup_result setBaudRate(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart, hm10_baud baudrate) {
	char tx_baud = baudrate + '0';
	char* tx_cmd = concat_str((char*) getCommand(BAUD_SET), tx_baud);

	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(BAUD_SET));
	HAL_UART_Transmit(huart, (uint8_t *) tx_cmd, strlen(tx_cmd), 0xFFFF);
	HAL_TIM_Base_Start(htim);

	free(tx_cmd);
	int tx_res = dma_res[getResLength(BAUD_SET) - 1] - '0';
	if (tx_res != 0 && tx_res != 1 && tx_res != 2 && tx_res != 3 && tx_res != 4 &&
		tx_res != 5 && tx_res != 6 && tx_res != 7 && tx_res != 8) return HM10_ERROR;

	return OK;
}

setup_result setRole(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart, hm10_role role) {
	char tx_role = role + '0';
	char* tx_cmd = concat_str((char*) getCommand(ROLE_SET), tx_role);

	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(ROLE_SET));
	HAL_UART_Transmit(huart, (uint8_t *) tx_cmd, strlen(tx_cmd), 0xFFFF);
	HAL_TIM_Base_Start(htim);

	free(tx_cmd);

	if (strcmp (dma_res, "OK+Set:1") != 0 && strcmp (dma_res, "OK+Set:0") != 0) return HM10_ERROR;

	return OK;
}

setup_result setImme(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart, hm10_imme imme) {
	char tx_imme = imme + '0';
	char* tx_cmd = concat_str((char*) getCommand(IMME_SET), tx_imme);

	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(IMME_SET));
	HAL_UART_Transmit(huart, (uint8_t *) tx_cmd, strlen(tx_cmd), 0xFFFF);
	HAL_TIM_Base_Start(htim);

	free(tx_cmd);

	if (strcmp (dma_res, "OK+Set:1") != 0 && strcmp (dma_res, "OK+Set:0") != 0) return HM10_ERROR;

	return OK;
}

//hm10_baud getBaudRate(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart) {
//
//}
//
hm10_role getRole(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart) {
	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(ROLE_GET));
	HAL_UART_Transmit(huart, getCommand(ROLE_GET), strlen((char *) getCommand(ROLE_GET)), 0xFFFF);

	HAL_TIM_Base_Start(htim);

	if (dma_res[getResLength(ROLE_GET) - 1] == SLAVE + '0') return SLAVE;

	return MASTER;
}

hm10_imme getImme(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart) {
	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(IMME_GET));
	HAL_UART_Transmit(huart, getCommand(IMME_GET), strlen((char *) getCommand(IMME_GET)), 0xFFFF);

	HAL_TIM_Base_Start(htim);

	if (dma_res[getResLength(IMME_GET) - 1] == BASE + '0') return BASE;

	return ONLY_AT;

}

setup_result renewDevice(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart) {
	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(RENEW));
	HAL_UART_Transmit(huart, getCommand(RENEW), strlen((char*) getCommand(RENEW)), 0xFFFF);

	HAL_TIM_Base_Start(htim);

	if (strcmp (dma_res, "OK+RENEW") != 0) return HM10_ERROR;

	return OK;
}

setup_result resetDevice(TIM_HandleTypeDef *htim, UART_HandleTypeDef *huart) {
	HAL_UART_Receive_DMA(huart, (uint8_t *) dma_res, getResLength(RESET));
	HAL_UART_Transmit(huart, getCommand(RESET), strlen((char*) getCommand(RESET)), 0xFFFF);

	HAL_TIM_Base_Start(htim);

	if (strcmp (dma_res, "OK") != 0) return HM10_ERROR;

	return OK;
}

char* concat_str(char * cmd, char mode) {
	const size_t len1 = strlen(cmd);

	char *result = malloc(len1 + 4);

	strcpy(result, cmd);
	result[len1] = mode;
	strcat(result, "\r");
	strcat(result, "\n");

	return result;
}
