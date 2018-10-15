#include "sapi_oneWire.h"

static oneWireData_t oneWireData;		// 1-Wire data structure

bool_t ONE_WIRE_configGpio(gpioMap_t gpio) {

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
	return (1);
}
