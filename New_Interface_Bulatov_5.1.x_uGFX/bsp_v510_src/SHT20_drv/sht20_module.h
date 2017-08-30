#ifndef __SHT20_MODULE_H
#define __SHT20_MODULE_H 

#define SHT20_I2C_ADDRESS			0x80
#define SHT20_I2C_INST	I2C_DEFAULT_INSTANCE
#define SHT20_I2C_SPEED	100000

#define SHT20_TRIGGER_TEMPERATURE_MEAS		0xF3
#define SHT20_TRIGGER_HUMIDITY_MEAS		0xF5
#define SHT20_WRITE_USER_REG			0xE6
#define SHT20_READ_USER_REG			0xE7
#define SHR21_SOFT_RESET			0xFE

#define SHT20_MEAS_TIME_HUMIDITY		29 /* ms, max at 12 bit resolution */
#define SHT20_MEAS_TIME_TEMPERATURE		85 /* ms, max at 14 bit resolution */
#define SHT20_STATUS_BITS_MASK			0x03
#define SHT20_RESULT_TYPE			0x02
#define SHT20_TEMPERATURE_RESULT		0x00
#define SHT20_HUMIDITY_RESULT			0x02

//---------- Defines -----------------------------------------------------------
// CRC
// sensor command
typedef enum{
  TRIG_T_MEASUREMENT_HM = 0xE3, // command trig. temp meas. hold master
  TRIG_RH_MEASUREMENT_HM = 0xE5, // command trig. humidity meas. hold master
  TRIG_T_MEASUREMENT_POLL = 0xF3, // command trig. temp meas. no hold master
  TRIG_RH_MEASUREMENT_POLL = 0xF5, // command trig. humidity meas. no hold master
  USER_REG_W = 0xE6, // command writing user register
  USER_REG_R = 0xE7, // command reading user register
  SOFT_RESET = 0xFE // command soft reset
}etSHT2xCommand;

typedef enum {
  SHT2x_RES_12_14BIT = 0x00, // RH=12bit, T=14bit
  SHT2x_RES_8_12BIT = 0x01, // RH= 8bit, T=12bit
  SHT2x_RES_10_13BIT = 0x80, // RH=10bit, T=13bit
  SHT2x_RES_11_11BIT = 0x81, // RH=11bit, T=11bit
  SHT2x_RES_MASK = 0x81 // Mask for res. bits (7,0) in user reg.
} etSHT2xResolution;

typedef enum {
  SHT2x_EOB_ON = 0x40, // end of battery
  SHT2x_EOB_MASK = 0x40, // Mask for EOB bit(6) in user reg.
} etSHT2xEob;

typedef enum {
  SHT2x_HEATER_ON = 0x04, // heater on
  SHT2x_HEATER_OFF = 0x00, // heater off
  SHT2x_HEATER_MASK = 0x04, // Mask for Heater bit(2) in user reg.
} etSHT2xHeater;

// measurement signal selection
typedef enum{
  HUMIDITY,
  TEMP
}etSHT2xMeasureType;

typedef enum{
  I2C_ADR_W = 128, // sensor I2C address + write bit
  I2C_ADR_R = 129 // sensor I2C address + read bit
}etI2cHeader;

/*
// writes the SHT2x user register (8bit)
// input : *pRegisterValue
// output: -
// return: error

// measures humidity or temperature. This function polls every 10ms until
// measurement is ready.
// input: eSHT2xMeasureType
// output: *pMeasurand: humidity / temperature as raw value
// return: error
// note: timing for timeout may be changed
//==============================================================================
uint8_t SHT2x_MeasurePoll(etSHT2xMeasureType eSHT2xMeasureType, int16_t *pMeasurand);
//==============================================================================

// measures humidity or temperature. This function waits for a hold master until
// measurement is ready or a timeout occurred.
// input: eSHT2xMeasureType
// output: *pMeasurand: humidity / temperature as raw value
// return: error
// note: timing for timeout may be changed
//==============================================================================
uint8_t SHT2x_MeasureHM(etSHT2xMeasureType eSHT2xMeasureType, int16_t *pMeasurand);
//==============================================================================

// performs a reset
// input: -
// output: -
// return: error
//==============================================================================
uint8_t SHT2x_SoftReset();
//==============================================================================

// calculates the relative humidity
// input: sRH: humidity raw value (16bit scaled)
// return: pHumidity relative humidity [%RH]
//==============================================================================
float SHT2x_CalcRH(uint16_t u16sRH);
//==============================================================================

// calculates temperature
// input: sT: temperature raw value (16bit scaled)
// return: temperature [�C]
//==============================================================================
float SHT2x_CalcTemperatureC(uint16_t u16sT);
//==============================================================================

// gets serial number of SHT2x according application note "How To
// Read-Out the Serial Number"
// note: readout of this function is not CRC checked
//
// input: -
// output: u8SerialNumber: Array of 8 bytes (64Bits)
// MSB LSB
// u8SerialNumber[7] u8SerialNumber[0]
// SNA_1 SNA_0 SNB_3 SNB_2 SNB_1 SNB_0 SNC_1 SNC_0
// return: error
//==============================================================================
uint8_t SHT2x_GetSerialNumber(uint8_t u8SerialNumber[]);
//==============================================================================*/

int16_t sht20readTemp(void);

int16_t sht20readRh(void);

int16_t sht20test_read(void);

void sht20_reset(void);

#endif /* __SHT20_MODULE_H */