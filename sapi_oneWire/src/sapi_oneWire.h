#ifndef _SAPI_ONE_WIRE_H_
#define _SAPI_ONE_WIRE_H_

/*==================[inclusions]=============================================*/

#include "stdint.h"
#include "gpio.h"
#include "oneWire_delay.h"
#include "oneWire_driver.h"

/*==================[macros]=================================================*/

#define EDU_CIAA_NXP_CLOCK_SPEED	204000000
/* Define number of cycles = 1 us */
#define NUMBER_CYCLES_1US			(EDU_CIAA_NXP_CLOCK_SPEED / 1000000)
/* Define number of cycles = 250 ns */
#define NUMBER_CYCLES_250NS		(NUMBER_CYCLES_1US / 4)
/* Ciclos de ajuste por latencia en gpioWrite (poner en 0 si no interesa) */
#define NUMBER_CYCLES_TO_ADJUST	143

#define ROM_CODE_LENGHT				8

/*==================[typedef]================================================*/

/* Define Boolean Data Type */
typedef uint8_t bool_t;

typedef enum {
	ONE_WIRE_SENSOR_NO_PRESENCE,		// 0, FALSE
	ONE_WIRE_SENSOR_OPERATIONAL,		// 1, TRUE
	ONE_WIRE_SENSOR_IDLE,
	ONE_WIRE_SENSOR_ERROR
} oneWireSensorState_t;

typedef struct {
	uint8_t romCode[8];			// 64 bit ROM code
	uint8_t familyCode;			// 8 bit family code
	uint8_t serialNumber[6];	// 48 bit Serial number
	uint8_t crc;					// 8 bit CRC
} oneWireSensorData_t;

typedef struct {
	gpioMap_t gpio;
	oneWireSensorState_t state;
	oneWireSensorData_t data;
} oneWireData_t;

typedef enum {
	ONE_WIRE_COMMAND_SKIP_OVERDRIVE	= 0x3C,
	ONE_WIRE_COMMAND_READ_ROM 			= 0x33,
	ONE_WIRE_COMMAND_SEARCH_ROM 		= 0xF0,
	ONE_WIRE_COMMAND_MATCH_ROM 		= 0x55,
	ONE_WIRE_COMMAND_SKIP_ROM 			= 0xCC,
} oneWireCommand_t;

typedef enum {
	ONE_WIRE_ROM_DATA_FAMILY_CODE,
	ONE_WIRE_ROM_DATA_SN_BYTE1,
	ONE_WIRE_ROM_DATA_SN_BYTE2,
	ONE_WIRE_ROM_DATA_SN_BYTE3,
	ONE_WIRE_ROM_DATA_SN_BYTE4,
	ONE_WIRE_ROM_DATA_SN_BYTE5,
	ONE_WIRE_ROM_DATA_SN_BYTE6,
	ONE_WIRE_ROM_DATA_CRC
} oneWireROMData;

/*==================[external functions declaration]==========================*/

/**
 * @brief			Config gpio for 1-Wire master interface.
 * @param			gpio: gpio 1-Wire interface.
 * @return			1 if gpio was configured OK, otherwise return 0.
 */
bool_t ONE_WIRE_configGpio(gpioMap_t gpio);

/**
 * @brief			Config speed for 1-Wire master interface.
 * @param			speed: speed 1-Wire interface.
 * @return			1 if speed was configured OK, otherwise return 0.
 */
bool_t ONE_WIRE_configSpeed(uint8_t speed);

/**
 * @brief			Generate a 1-Wire reset.
 * @param			* oneWireData: where will return the presence state.
 * @return			Return 1 there are no errors, return 0 otherwise.
 */
bool_t ONE_WIRE_verifySensorPresence(oneWireData_t * oneWireData);

/**
 * @brief			Read sensor ROM data.
 * @param			data: where will be stored read data
 * @return			Return 1 there are no errors, return 0 otherwise.
 */
bool_t ONE_WIRE_readSensorRomData(oneWireData_t * oneWireData);

#endif /* _SAPI_ONE_WIRE_H_ */
