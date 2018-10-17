#include "sapi_oneWire.h"

/*==================[internal data definition]===============================*/

static oneWireData_t oneWireData;					// 1-Wire data structure
static uint32_t A, B, C, D, E, F, G, H, I, J;	// 'tick' values

/*==================[internal functions declaration]=========================*/

/*==================[external functions definition]==========================*/


bool_t ONE_WIRE_configGpio(gpioMap_t gpio) {
	/*
	 * Configure GPIO for 1-Wire Bus
	 */

	switch(gpio) {

	case GPIO0:
	case GPIO1:
	case GPIO2:
	case GPIO3:
	case GPIO4:
	case GPIO5:
	case GPIO6:
	case GPIO7:
	case GPIO8:
		/* Si GPIO0 <= gpio <= GPIO8 */
		oneWireData.gpio = gpio;
		break;

	default:
		/* Error */
		return (0);
	}
	/* Si configuro OK, return 1 */
	return (1);
}

bool_t ONE_WIRE_configSpeed(uint8_t speed) {
	/*
	 * Adjust tick values depending on speed [microseconds]
	 * Define 1-Wire timing to 'standard' (=1) or 'overdrive' (=0).
	 */

	if(speed == 1) {
		/* Standard Speed */
		A = 6 * 4;		// 6
		B = 64 * 4;		// 64
		C = 60 * 4;		// 60
		D = 10 * 4;		// 10
		E = 9 * 4;		// 9
		F = 55 * 4;		// 55
		G = 0;			// 0
		H = 480 * 4;	// 480
		I = 70 * 4;		// 70
		J = 410 * 4;	// 410
	}
	else if(speed == 0) {
		/* Overdrive Speed */
		A = 1.5 * 4;	// 1.5
		B = 7.5 * 4;	// 7.5
		C = 7.5 * 4;	// 7.5
		D = 2.5 * 4;	// 2.5
		E = 0.75 * 4;	// 0.75
		F = 7 * 4;		// 7
		G = 2.5 * 4;	// 2.5
		H = 70 * 4;		// 70
		I = 8.5 * 4;	// 8.5
		J = 40 * 4;		// 40
	}
	else {
		/* Error */
		return (0);
	}
	/* Si configuro OK, return 1 */
	return (1);
}

bool_t ONE_WIRE_verifySensorPresence(oneWireData_t * oneWireData) {

	bool_t result = 0;

	ONE_WIRE_DELAY_250ns(G);
	if(gpioInit(oneWireData->gpio, GPIO_OUTPUT) == 0)
		return result;	// Error
	if(gpioWrite(oneWireData->gpio, 0) == 0)
		return result;	// Error
	ONE_WIRE_DELAY_250ns(H);
	if(gpioWrite(oneWireData->gpio, 1) == 0)
		return result;	// Error
	ONE_WIRE_DELAY_250ns(I);
	// Sample for presence pulse from slave
	if(gpioInit(oneWireData->gpio, GPIO_INPUT_PULLUP) == 0)
		return result;

	if(!gpioRead(oneWireData->gpio) == 1)
		oneWireData->state = ONE_WIRE_SENSOR_OPERATIONAL;

	// Complete the reset sequence recovery
	ONE_WIRE_DELAY_250ns(J);

	return result = 1;
}

/*==================[internal functions definition]==========================*/
