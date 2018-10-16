#include "build/temp/_test_sapi_oneWire.c"
#include "sapi_oneWire.h"
#include "unity.h"


void setup(void) {

}



void tearDown(void) {

}



void test_configOneWireGpio(void) {





 gpioMap_t gpio = GPIO1;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configGpio(gpio))), (

((void *)0)

), (UNITY_UINT)(14), UNITY_DISPLAY_STYLE_INT);



 gpio = GPIO8;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configGpio(gpio))), (

((void *)0)

), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);



 gpio = 5;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ONE_WIRE_configGpio(gpio))), (

((void *)0)

), (UNITY_UINT)(20), UNITY_DISPLAY_STYLE_INT);

}



void test_configOneWireSpeed(void) {





 uint8_t speed = 1;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_INT);



 speed = 0;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(30), UNITY_DISPLAY_STYLE_INT);



 speed = 3;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(33), UNITY_DISPLAY_STYLE_INT);

}
