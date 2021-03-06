/* AUTOGENERATED FILE. DO NOT EDIT. */
#ifndef _MOCK_ONEWIRE_DRIVER_H
#define _MOCK_ONEWIRE_DRIVER_H

#include "oneWire_driver.h"

/* Ignore the following warnings, since we are copying code */
#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic push
#endif
#if !defined(__clang__)
#pragma GCC diagnostic ignored "-Wpragmas"
#endif
#pragma GCC diagnostic ignored "-Wunknown-pragmas"
#pragma GCC diagnostic ignored "-Wduplicate-decl-specifier"
#endif

void mock_oneWire_driver_Init(void);
void mock_oneWire_driver_Destroy(void);
void mock_oneWire_driver_Verify(void);




#define ONE_WIRE_DRIVER_writeByte_Ignore() ONE_WIRE_DRIVER_writeByte_CMockIgnore()
void ONE_WIRE_DRIVER_writeByte_CMockIgnore(void);
#define ONE_WIRE_DRIVER_writeByte_Expect(data) ONE_WIRE_DRIVER_writeByte_CMockExpect(__LINE__, data)
void ONE_WIRE_DRIVER_writeByte_CMockExpect(UNITY_LINE_TYPE cmock_line, uint8_t data);
typedef void (* CMOCK_ONE_WIRE_DRIVER_writeByte_CALLBACK)(uint8_t data, int cmock_num_calls);
void ONE_WIRE_DRIVER_writeByte_StubWithCallback(CMOCK_ONE_WIRE_DRIVER_writeByte_CALLBACK Callback);
#define ONE_WIRE_DRIVER_readByte_IgnoreAndReturn(cmock_retval) ONE_WIRE_DRIVER_readByte_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void ONE_WIRE_DRIVER_readByte_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return);
#define ONE_WIRE_DRIVER_readByte_ExpectAndReturn(cmock_retval) ONE_WIRE_DRIVER_readByte_CMockExpectAndReturn(__LINE__, cmock_retval)
void ONE_WIRE_DRIVER_readByte_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, uint8_t cmock_to_return);
typedef uint8_t (* CMOCK_ONE_WIRE_DRIVER_readByte_CALLBACK)(int cmock_num_calls);
void ONE_WIRE_DRIVER_readByte_StubWithCallback(CMOCK_ONE_WIRE_DRIVER_readByte_CALLBACK Callback);
#define ONE_WIRE_DRIVER_checkCRC_IgnoreAndReturn(cmock_retval) ONE_WIRE_DRIVER_checkCRC_CMockIgnoreAndReturn(__LINE__, cmock_retval)
void ONE_WIRE_DRIVER_checkCRC_CMockIgnoreAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
#define ONE_WIRE_DRIVER_checkCRC_ExpectAndReturn(cmock_retval) ONE_WIRE_DRIVER_checkCRC_CMockExpectAndReturn(__LINE__, cmock_retval)
void ONE_WIRE_DRIVER_checkCRC_CMockExpectAndReturn(UNITY_LINE_TYPE cmock_line, bool_t cmock_to_return);
typedef bool_t (* CMOCK_ONE_WIRE_DRIVER_checkCRC_CALLBACK)(int cmock_num_calls);
void ONE_WIRE_DRIVER_checkCRC_StubWithCallback(CMOCK_ONE_WIRE_DRIVER_checkCRC_CALLBACK Callback);

#if defined(__GNUC__) && !defined(__ICC) && !defined(__TMS470__)
#if __GNUC__ > 4 || (__GNUC__ == 4 && (__GNUC_MINOR__ > 6 || (__GNUC_MINOR__ == 6 && __GNUC_PATCHLEVEL__ > 0)))
#pragma GCC diagnostic pop
#endif
#endif

#endif
