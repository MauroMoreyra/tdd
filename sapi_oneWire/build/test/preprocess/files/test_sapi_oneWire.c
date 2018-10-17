#include "build/temp/_test_sapi_oneWire.c"
#include "mock_oneWire_delay.h"
#include "mock_gpio.h"
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

), (UNITY_UINT)(16), UNITY_DISPLAY_STYLE_INT);



 gpio = GPIO8;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configGpio(gpio))), (

((void *)0)

), (UNITY_UINT)(19), UNITY_DISPLAY_STYLE_INT);



 gpio = 5;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ONE_WIRE_configGpio(gpio))), (

((void *)0)

), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_INT);

}



void test_configOneWireSpeed(void) {





 uint8_t speed = 1;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(29), UNITY_DISPLAY_STYLE_INT);



 speed = 0;

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(32), UNITY_DISPLAY_STYLE_INT);



 speed = 3;

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((ONE_WIRE_configSpeed(speed))), (

((void *)0)

), (UNITY_UINT)(35), UNITY_DISPLAY_STYLE_INT);

}



void test_oneWireSensorPresenceValid(void) {



 oneWireData_t oneWireData = {

   .gpio = GPIO1,

   .state = ONE_WIRE_SENSOR_IDLE,

 };



 ONE_WIRE_configSpeed(1);





 gpioInit_CMockExpectAndReturn(48, oneWireData.gpio, GPIO_OUTPUT, 1);

 gpioWrite_CMockExpectAndReturn(49, oneWireData.gpio, 0, 1);

 gpioWrite_CMockExpectAndReturn(50, oneWireData.gpio, 1, 1);

 gpioInit_CMockExpectAndReturn(51, oneWireData.gpio, GPIO_INPUT_PULLUP, 1);

 gpioRead_CMockExpectAndReturn(52, oneWireData.gpio, 0);

 ONE_WIRE_DELAY_250ns_CMockIgnore();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_verifySensorPresence(&oneWireData))), (

((void *)0)

), (UNITY_UINT)(55), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((oneWireData.state)), (

((void *)0)

), (UNITY_UINT)(56), UNITY_DISPLAY_STYLE_INT);

}



void test_oneWireSensorPresenceNotValid(void) {



 oneWireData_t oneWireData = {

   .gpio = GPIO1,

   .state = ONE_WIRE_SENSOR_IDLE,

 };



 ONE_WIRE_configSpeed(1);





 gpioInit_CMockExpectAndReturn(69, oneWireData.gpio, GPIO_OUTPUT, 1);

 gpioWrite_CMockExpectAndReturn(70, oneWireData.gpio, 0, 1);

 gpioWrite_CMockExpectAndReturn(71, oneWireData.gpio, 1, 1);

 gpioInit_CMockExpectAndReturn(72, oneWireData.gpio, GPIO_INPUT_PULLUP, 1);

 gpioRead_CMockExpectAndReturn(73, oneWireData.gpio, 1);

 ONE_WIRE_DELAY_250ns_CMockIgnore();



 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((ONE_WIRE_verifySensorPresence(&oneWireData))), (

((void *)0)

), (UNITY_UINT)(76), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((oneWireData.state)), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

}
