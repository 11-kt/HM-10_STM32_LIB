# Lib for managing HM-10 wireless data transmission device (BLE). Base on stm32l152ret6.

## Available AT commands:
* AT
* AT+RESET
* AT+RENEW
* AT+BAUD
* AT+CON
* AT+IMME
* AT+NAME
* AT+ROLE
* AT+START
* AT+ADDR
* AT+POWER
* AT+MODE
* AT+TEMP
* AT+RSSI

## Config funs:
* checkConnection - Check UART connection
* setBaudRate - set HM10 baudrate
* setRole - set HM10 role (master/slave)
* setImme - set working mode (at only/at + data)
* setName - set HM10 BLE name
* setPower - set HM10 power
* setMode - set HM10 working mode (when device connected)
* getBaudRate - get current HM10 baudrate
* getRole - get current HM10 role
* getImme - get current HM10 working mode
* getAddr - get current HM10 mac addr
* getPower - get current HM10 power
* getMode - get current HM10 working mode (when connected)
* getTemp - get connected HM10 temperature
* getRSSI - get connected HM10 RSSI
* renewDevice - HM10 factory reset
* resetDevice - reboot HM10
* startHM10 - start HM10 to transmit and receive data
* setupSlave - setup Slave mode
*  setupMaster - setup Master mode

## HM-10 firmware:
* `HMSoft v710`