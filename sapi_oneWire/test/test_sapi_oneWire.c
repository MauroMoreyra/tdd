#include "unity.h"
#include "sapi_oneWire.h"

void setup(void) {
}

void tearDown(void) {
}

void test_configOneWireGpio(void) {
	/* Se puede configurar cualquier GPIO como master del bus 1-Wire. */
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
	/* Se puede configurar la velocidad del bus: standard (=1) o overdrive (=0). */
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
