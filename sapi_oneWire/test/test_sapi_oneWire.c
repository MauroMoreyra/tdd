#include "unity.h"
#include "sapi_oneWire.h"
#include "mock_gpio.h"
#include "mock_oneWire_delay.h"
#include "mock_oneWire_driver.h"

void setup(void) {
}

void tearDown(void) {
}

void test_configOneWireGpio(void) {
	/* 1. Se puede configurar cualquier GPIO como master del bus 1-Wire. */
	// Configuro GPIO valida, espero un 1
	gpioMap_t gpio = GPIO1;
	TEST_ASSERT_EQUAL(1, ONE_WIRE_configGpio(gpio));
	// Configuro otra GPIO valida, espero un 1
	gpio = GPIO8;
	TEST_ASSERT_EQUAL(1, ONE_WIRE_configGpio(gpio));
	// Configuro cualquier otro valor, espero un 0
	gpio = 5;
	TEST_ASSERT_EQUAL(0, ONE_WIRE_configGpio(gpio));
}

void test_configOneWireSpeed(void) {
	/* 2. Se puede configurar la velocidad del bus: standard (=1) o overdrive (=0). */
	// Configuro velocidad standard, espero un 1
	uint8_t speed = 1;
	TEST_ASSERT_EQUAL(1, ONE_WIRE_configSpeed(speed));
	// Configuro velocidad overdrive, espero un 1
	speed = 0;
	TEST_ASSERT_EQUAL(1, ONE_WIRE_configSpeed(speed));
	// Configuro cualquier otro valor, espero un 0
	speed = 3;
	TEST_ASSERT_EQUAL(0, ONE_WIRE_configSpeed(speed));
}

void test_oneWireSensorPresenceValid(void) {
	/* 3. Se puede verificar si existe presencia de dispositivo iButton sobre el bus. */
	oneWireData_t oneWireData = {
			.gpio = GPIO1,
			.state = ONE_WIRE_SENSOR_IDLE,
	};
	/* Configuro Standard speed */
	ONE_WIRE_configSpeed(1);

	/* Defino prerequisitos de test */
	gpioInit_ExpectAndReturn(oneWireData.gpio, GPIO_OUTPUT, 1);
	gpioWrite_ExpectAndReturn(oneWireData.gpio, 0, 1);
	gpioWrite_ExpectAndReturn(oneWireData.gpio, 1, 1);
	gpioInit_ExpectAndReturn(oneWireData.gpio, GPIO_INPUT_PULLUP, 1);
	gpioRead_ExpectAndReturn(oneWireData.gpio, 0);
	ONE_WIRE_DELAY_250ns_Ignore();
	/* Tests */
	TEST_ASSERT_EQUAL(1, ONE_WIRE_verifySensorPresence(&oneWireData));
	TEST_ASSERT_EQUAL(1, oneWireData.state);
}

void test_oneWireSensorPresenceNotValid(void) {
	/* 4. Se puede verificar si NO existe presencia de dispositivo iButton sobre el bus. */
	oneWireData_t oneWireData = {
			.gpio = GPIO1,
			.state = ONE_WIRE_SENSOR_IDLE,
	};
	/* Configuro Standard speed */
	ONE_WIRE_configSpeed(1);

	/* Defino prerequisitos de test */
	gpioInit_ExpectAndReturn(oneWireData.gpio, GPIO_OUTPUT, 1);
	gpioWrite_ExpectAndReturn(oneWireData.gpio, 0, 1);
	gpioWrite_ExpectAndReturn(oneWireData.gpio, 1, 1);
	gpioInit_ExpectAndReturn(oneWireData.gpio, GPIO_INPUT_PULLUP, 1);
	gpioRead_ExpectAndReturn(oneWireData.gpio, 1);
	ONE_WIRE_DELAY_250ns_Ignore();
	/* Tests */
	TEST_ASSERT_EQUAL(1, ONE_WIRE_verifySensorPresence(&oneWireData));
	TEST_ASSERT_EQUAL(0, oneWireData.state);
}

void test_oneWireReadSensorRomData(void) {
	/* 5. Se pueden leer los datos de ROM de dispositivo iButton presente sobre el bus. */
	oneWireData_t oneWireData = {
			.gpio = GPIO1,
			.state = ONE_WIRE_SENSOR_IDLE,
	};
	uint8_t i;

	/* Defino prerequisitos de test */
	gpioInit_ExpectAndReturn(oneWireData.gpio, GPIO_OUTPUT, 1);
	gpioWrite_ExpectAndReturn(oneWireData.gpio, 0, 1);
	gpioWrite_ExpectAndReturn(oneWireData.gpio, 1, 1);
	gpioInit_ExpectAndReturn(oneWireData.gpio, GPIO_INPUT_PULLUP, 1);
	gpioRead_ExpectAndReturn(oneWireData.gpio, 0);
	ONE_WIRE_DELAY_250ns_Ignore();
	ONE_WIRE_DRIVER_writeByte_Ignore();
	ONE_WIRE_DRIVER_readByte_IgnoreAndReturn(0xAA);
	ONE_WIRE_DRIVER_checkCRC_IgnoreAndReturn(1);
	/* Tests */
	TEST_ASSERT_EQUAL(1, ONE_WIRE_readSensorRomData(&oneWireData));
	for(i = 0; i < ROM_CODE_LENGHT; i++) {
		TEST_ASSERT_EQUAL(0xAA, oneWireData.data.romCode[i]);
	}
}
