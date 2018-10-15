#include "unity.h"
#include "sapi_oneWire.h"

void setup(void) {
}

void tearDown(void) {
}

void test_configOneWireGpio(void) {
	/* Se puede configurar cualquier GPIO como master del bus 1-Wire. */
	gpioMap_t gpio = GPIO1;
	TEST_ASSERT_EQUAL(1, ONE_WIRE_configGpio(gpio));
}

void test_configOneWireSpeed(void) {
	/* Se puede configurar la velocidad del bus: standard o overdrive. */
	uint8_t speed = 1;
	TEST_ASSERT_EQUAL(1, ONE_WIRE_configSpeed(speed));
}
