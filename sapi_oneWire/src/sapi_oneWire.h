#ifndef _SAPI_ONE_WIRE_H_
#define _SAPI_ONE_WIRE_H_

/*==================[inclusions]=============================================*/

#include "stdint.h"
#include "gpio.h"
#include "oneWire_delay.h"

/*==================[macros]=================================================*/

#define EDU_CIAA_NXP_CLOCK_SPEED	204000000
/* Define number of cycles = 1 us */
#define NUMBER_CYCLES_1US			(EDU_CIAA_NXP_CLOCK_SPEED / 1000000)
/* Define number of cycles = 250 ns */
#define NUMBER_CYCLES_250NS		(NUMBER_CYCLES_1US / 4)
/* Ciclos de ajuste por latencia en gpioWrite (poner en 0 si no interesa) */
#define NUMBER_CYCLES_TO_ADJUST	143

/*==================[typedef]================================================*/

/* Define Boolean Data Type */
typedef uint8_t bool_t;

typedef enum {
	ONE_WIRE_SENSOR_NO_PRESENCE,		// 0, FALSE
	ONE_WIRE_SENSOR_OPERATIONAL,		// 1, TRUE
	ONE_WIRE_SENSOR_ERROR,
	ONE_WIRE_SENSOR_IDLE
} oneWireSensorState_t;

typedef struct {
	gpioMap_t gpio;
	oneWireSensorState_t state;
} oneWireData_t;

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


#endif /* _SAPI_ONE_WIRE_H_ */
