#ifndef _SIGNAL_PROC_H_
#define _SIGNAL_PROC_H_

#include "types.h"

/*nr de pucte caracteristica voltage/temperatura*/
#define NR_PUNCTE_TEMP_CHAR 15

#define AdcBitResolution (10)
#define Voltage_prez_rez 0.00048828125
/*5V ----- 10240   ---- 0.00048828125/bit*/
#define AdcVoltageRef (T_ULONG)((double)(5) / Voltage_prez_rez)

/*0x50 ---> 80 deg ---> 5V*/
#define Maxim_Voltage_SensorT 0x50
#define Minim_Voltage_SensorT 0x00
#define Delta_Voltage (Maxim_Voltage_SensorT - Minim_Voltage_SensorT)

/*50 grade ---> 800 deg repz ---->0x320 repz (0.0625grade/bit)*/
#define Maxim_Temperature_SensorT 0x320
/*-50 grade --> -800 deg repz ---> 0xfce0 repz (0.0625grade/bit)*/
#define Minim_Temperature_SensorT 0xfce0

#define Delta_Temperature ((T_SLONG)((T_SWORD)Maxim_Temperature_SensorT - (T_SWORD)Minim_Temperature_SensorT))

#define VoltageX1 0
#define TemperatureY1 (T_SWORD)0xfce0

#if 0
/*carcteristic of LM35 sensor with LM358 operational amplifier*/
#define Temperatureplus125         2000
#define Voltageplus125             51
#define Temperatureminus40         (T_SWORD)-640
#define Voltageminus40             10211
#endif
/*carcteristic of LM35 sensor simple*/
#define Temperatureplus125         2000
#define Voltageplus125             2560
#define Temperatureminus40         (T_SWORD)0
#define Voltageminus40             (T_SWORD)0

typedef struct temp_characteristic
{
    T_SWORD sw_temp;
    T_UWORD uw_voltage;
};
typedef enum sensorsID
{
    No_Sensor = 0,
    Sensor_0_Temperature ,
    Sensor_1_Temperature ,
    Sensor_0_TemperatureRS458 ,
    Sensor_1_TemperatureRS458 ,
    Sensor_0_push,
    Sensor_default,
};

extern const struct temp_characteristic sa_sensor_temp_char[NR_PUNCTE_TEMP_CHAR];

extern T_UWORD Convert_to_Voltage (T_UWORD uw_raw_value);
extern T_SWORD ConvertV_to_Temperature2Tz(T_UWORD uw_voltage);
extern T_SWORD ConvertV_to_TemperatureLM35(T_UWORD uw_voltage);

extern T_UBYTE GetUARTSensorRequest(T_UBYTE lub_old_sens_req);
extern void init_signal_procesing(void);
//extern T_SWORD ConvertV_to_Temperature2TzPrime(T_UWORD uw_voltage);
#endif /*#ifndef _SIGNAL_PROC_H_*/
