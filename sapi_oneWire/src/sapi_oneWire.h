#include "stdint.h"

/* Define Boolean Data Type */
typedef uint8_t bool_t;

typedef enum {
   GPIO8 = 11, GPIO7, GPIO5, GPIO3, GPIO1,
   GPIO6 = 29, GPIO4, GPIO2, GPIO0
} gpioMap_t;

typedef struct {
	gpioMap_t gpio;
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
