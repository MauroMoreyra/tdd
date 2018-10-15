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

), (UNITY_UINT)(13), UNITY_DISPLAY_STYLE_INT);

}



void test_configOneWireSpeed(void) {



 uint8_t speed = 3;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);

}
