#include "oneWire_driver.h"
#include "oneWire_delay.h"
#include "gpio.h"










typedef uint8_t bool_t;



typedef enum {

 ONE_WIRE_SENSOR_NO_PRESENCE,

 ONE_WIRE_SENSOR_OPERATIONAL,

 ONE_WIRE_SENSOR_IDLE,

 ONE_WIRE_SENSOR_ERROR

} oneWireSensorState_t;



typedef struct {

 uint8_t romCode[8];

 uint8_t familyCode;

 uint8_t serialNumber[6];

 uint8_t crc;

} oneWireSensorData_t;



typedef struct {

 gpioMap_t gpio;

 oneWireSensorState_t state;

 oneWireSensorData_t data;

} oneWireData_t;



typedef enum {

 ONE_WIRE_COMMAND_SKIP_OVERDRIVE = 0x3C,

 ONE_WIRE_COMMAND_READ_ROM = 0x33,

 ONE_WIRE_COMMAND_SEARCH_ROM = 0xF0,

 ONE_WIRE_COMMAND_MATCH_ROM = 0x55,

 ONE_WIRE_COMMAND_SKIP_ROM = 0xCC,

} oneWireCommand_t;



typedef enum {

 ONE_WIRE_ROM_DATA_FAMILY_CODE,

 ONE_WIRE_ROM_DATA_SN_BYTE1,

 ONE_WIRE_ROM_DATA_SN_BYTE2,

 ONE_WIRE_ROM_DATA_SN_BYTE3,

 ONE_WIRE_ROM_DATA_SN_BYTE4,

 ONE_WIRE_ROM_DATA_SN_BYTE5,

 ONE_WIRE_ROM_DATA_SN_BYTE6,

 ONE_WIRE_ROM_DATA_CRC

} oneWireROMData;

bool_t ONE_WIRE_configGpio(gpioMap_t gpio);













bool_t ONE_WIRE_configSpeed(uint8_t speed);













bool_t ONE_WIRE_verifySensorPresence(oneWireData_t * oneWireData);













bool_t ONE_WIRE_readSensorRomData(oneWireData_t * oneWireData);
