#ifndef _GPIO_H_
#define _GPIO_H_

/*==================[inclusions]=============================================*/

#include <stdint.h>
//#include "sapi_oneWire.h"

/*==================[typedef]================================================*/

typedef enum {
   GPIO8 = 11, GPIO7, GPIO5, GPIO3, GPIO1,
   GPIO6 = 29, GPIO4, GPIO2, GPIO0
} gpioMap_t;

/* Define Boolean Data Type */
typedef uint8_t bool_t;

typedef enum {
   GPIO_INPUT, GPIO_OUTPUT,
   GPIO_INPUT_PULLUP, GPIO_INPUT_PULLDOWN,
   GPIO_INPUT_PULLUP_PULLDOWN,
   GPIO_ENABLE
} gpioInit_t;

/*==================[external functions declaration]==========================*/

bool_t gpioInit(gpioMap_t gpio, gpioInit_t config);

bool_t gpioWrite(gpioMap_t gpio, bool_t value);

bool_t gpioRead(gpioMap_t gpio);


#endif /* _GPIO_H_ */
