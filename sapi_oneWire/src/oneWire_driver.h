#ifndef _ONE_WIRE_DRIVER_H_
#define _ONE_WIRE_DRIVER_H_

/*==================[inclusions]=============================================*/

#include "sapi_oneWire.h"

/*==================[external functions declaration]==========================*/

/**
 * @brief			Write 1-Wire data byte.
 * @param			data: byte to transmit.
 */
void ONE_WIRE_DRIVER_writeByte(uint8_t data);

/**
 * @brief			Read 1-Wire data byte and return it.
 * @relval			Byte read.
 */
uint8_t ONE_WIRE_DRIVER_readByte(void);

/**
 * @brief			Check CRC from obtained ROM data.
 * @return			Return 1 if CRC is valid, return 0 otherwise.
 */
bool_t ONE_WIRE_DRIVER_checkCRC(void);

#endif /* _ONE_WIRE_DRIVER_H_ */
