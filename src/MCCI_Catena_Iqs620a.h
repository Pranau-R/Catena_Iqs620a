/*

Module: MCCI_Catena_Iqs620a.h

Function:
    Top-level include file for MCCI Catena IQS620A library (simple).

Copyright and License:
    See accompanying LICENSE file for copyright and license information.

Author:
    Pranau R, MCCI Corporation   April 2023

*/

#ifndef MCCI_CATENA_IQS620A_H
#define MCCI_CATENA_IQS620A_H

#include <Arduino.h>

/// \brief namespace for this library
namespace McciCatenaIqs620a {

/*  Global defines      ----------------------------------------------------------*/

#define MS_500                                  500
#define ONE_SEC                                 1000
#define TWO_SEC                                 2000
#define THREE_SEC                               3000
#define TWELVE_SEC                              12000
#define MS_5                                    5

// Define Product Numbers
#define IQS620_PRODUCT_NR                       65
#define IQS620N_SOFTWARE_NR                     8
#define IQS620N_HARDWARE_NR                     130

/*  Define device data registers      --------------------------------------------*/

#define I2C_ADDRESS                             0x44

#define VERSION_INFO                            0x00
#define SYSTEM_FLAGS                            0x10

// Count Data
#define CHANNEL0_CS_LOW                         0x20
#define CHANNEL0_CS_HIGH                        0x21
#define CHANNEL1_CS_LOW                         0x22
#define CHANNEL1_CS_HIGH                        0x23
#define CHANNEL2_CS_LOW                         0x24
#define CHANNEL2_CS_HIGH                        0x25
#define CHANNEL3_CS_LOW                         0x26
#define CHANNEL3_CS_HIGH                        0x27
#define CHANNEL4_CS_LOW                         0x28
#define CHANNEL4_CS_HIGH                        0x29
#define CHANNEL5_CS_LOW                         0x2A
#define CHANNEL5_CS_HIGH                        0x2B

#define CHANNEL0_LTA_LOW                        0x30
#define CHANNEL0_LTA_HIGH                       0x31
#define CHANNEL1_LTA_LOW                        0x32
#define CHANNEL2_LTA_HIGH                       0x33

/*ProxFusion sensor settings block 0*/
#define PXS_SETTINGS_0_0                        0x40
#define PXS_SETTINGS_0_1                        0x41
#define PXS_SETTINGS_0_2                        0x42
#define PXS_SETTINGS_0_3                        0x43
#define PXS_SETTINGS_0_4                        0x44
#define PXS_SETTINGS_0_5                        0x45
#define PXS_SETTINGS_0_6                        0x46
#define PXS_SETTINGS_0_7                        0x47
#define PXS_SETTINGS_0_8                        0x48
#define PXS_SETTINGS_0_9                        0x49
#define PXS_SETTINGS_0_10                       0x4A
#define PXS_SETTINGS_0_11                       0x4B

/*ProxFusion sensor settings block 1*/
#define PXS_SETTINGS_1_0                        0x50
#define PXS_SETTINGS_1_1                        0x51
#define PXS_SETTINGS_1_2                        0x52
#define PXS_SETTINGS_1_3                        0x53
#define PXS_SETTINGS_1_4                        0x54
#define PXS_SETTINGS_1_5                        0x55
#define PXS_SETTINGS_1_6                        0x56
#define PXS_SETTINGS_1_7                        0x57

/*ProxFusion UI settings*/
#define PXS_UI_SETTINGS_0                       0x60
#define PXS_UI_SETTINGS_1                       0x61
#define PXS_UI_SETTINGS_2                       0x62
#define PXS_UI_SETTINGS_3                       0x63
#define PXS_UI_SETTINGS_4                       0x64
#define PXS_UI_SETTINGS_5                       0x65
#define PXS_UI_SETTINGS_6                       0x66

/*SAR UI settings*/
#define SAR_UI_SETTINGS_0                       0x70
#define SAR_UI_SETTINGS_1                       0x71
#define SAR_UI_SETTINGS_2                       0x72
#define SAR_UI_SETTINGS_3                       0x73
#define SAR_UI_SETTINGS_4                       0x74
#define SAR_UI_SETTINGS_5                       0x75

/*Hysteresis UI settings*/
#define METAL_UI_SETTINGS_0                     0x80
#define METAL_UI_SETTINGS_1                     0x81
#define METAL_UI_SETTINGS_2                     0x82
#define METAL_UI_SETTINGS_3                     0x83

/*Hall-effect sensor settings*/
#define HALL_SENS_SETTINGS_0                    0x90
#define HALL_SENS_SETTINGS_1                    0x91
#define HALL_SENS_SETTINGS_2                    0x92
#define HALL_SENS_SETTINGS_3                    0x93

/*Hall-effect switch UI settings*/
#define HALL_UI_SETTINGS_0                      0xA0
#define HALL_UI_SETTINGS_1                      0xA1
#define HALL_UI_SETTINGS_2                      0xA2

/*Temperature UI settings*/
#define TEMP_UI_SETTINGS_0                      0xC0
#define TEMP_UI_SETTINGS_1                      0xC1
#define TEMP_UI_SETTINGS_2                      0xC2
#define TEMP_UI_SETTINGS_3                      0xC3

/*Device and Power Mode Settings*/
#define DEV_SETTINGS                            0xD0
#define ACTIVE_CHANNELS                         0xD1
#define POWER_MODE_SETTINGS                     0xD2
#define NORMAL_MODE_REPORT_RATE                 0xD3
#define lOW_POWER_MODE_REPORT_RATE              0xD4
#define ULTRA_LOW_POWER_MODE_REPORT_RATE        0xD5
#define AUTO_MODE_TIME                          0xD6
#define GLOBAL_EVENT_MASK                       0xD7
#define PWM_DUTY_CYCLE                          0xD8
#define RDY_TIMEOUT_PERIOD                      0xD9
#define I2C_SETTINGS                            0xDA
#define CHANNEL_RESEED_ENABLE                   0xDB

#define DIRECT_ADDRESS                          0xF0
#define DIRECT_DATA                             0xF1

/* Bit definitions */
#define ACK_RESET                               0x40
#define REDO_ATI_ALL                            0x02
#define DO_RESEED                               0x01

// Sensor Settings
/* Change the Prox Sensor Settings 0 */
/* Memory Map Position 0x40 - 0x4B */
#define nPXS_SETTINGS0_0                        0x03
#define nPXS_SETTINGS0_1                        0x03
#define nPXS_SETTINGS0_2                        0x03
#define nPXS_SETTINGS0_3                        0x67
#define nPXS_SETTINGS0_4                        0x67
#define nPXS_SETTINGS0_5                        0x67
#define nPXS_SETTINGS0_6                        0xD0
#define nPXS_SETTINGS0_7                        0xD0
#define nPXS_SETTINGS0_8                        0xD0
#define nPXS_SETTINGS0_9                        0x06
#define nPXS_SETTINGS0_10                       0x06
#define nPXS_SETTINGS0_11                       0x06

/* Change the Prox Sensor Settings 1 */
/* Memory Map Position 0x50 - 0x58 */
#define nPXS_SETTINGS1_0                        0x00
#define nPXS_SETTINGS1_1                        0x01
#define nPXS_SETTINGS1_2                        0xAA
#define nPXS_SETTINGS1_3                        0xB0
#define nPXS_SETTINGS1_4                        0x8C
#define nPXS_SETTINGS1_5                        0x18
#define nPXS_SETTINGS1_6                        0x18
#define nPXS_SETTINGS1_7                        0x18

/* Change the Prox UI Settings */
/* Memory Map Position 0x60 - 0x66 */
#define nPXS_UI_SETTINGS_0                      0x16
#define nPXS_UI_SETTINGS_1                      0x25
#define nPXS_UI_SETTINGS_2                      0x16
#define nPXS_UI_SETTINGS_3                      0x25
#define nPXS_UI_SETTINGS_4                      0x16
#define nPXS_UI_SETTINGS_5                      0x25
#define nPXS_UI_SETTINGS_6                      0x28

/* Change the SAR UI Settings */
/* Memory Map Position 0x70 - 0x75 */
#define nSAR_UI_SETTINGS_0                      0x13
#define nSAR_UI_SETTINGS_1                      0x24
#define nSAR_UI_SETTINGS_2                      0x01
#define nSAR_UI_SETTINGS_3                      0x16
#define nSAR_UI_SETTINGS_4                      0x25
#define nSAR_UI_SETTINGS_5                      0x0A

/* Change the Metal Detect UI Settings */
/* Memory Map Position 0x80 - 0x83 */
#define nMETAL_DETECT_UI_SETTINGS_0             0xA2
#define nMETAL_DETECT_UI_SETTINGS_1             0x0A
#define nMETAL_DETECT_UI_SETTINGS_2             0x16
#define nMETAL_DETECT_UI_SETTINGS_3             0x25

/* Change the HALL Sensor Settings */
/* Memory Map Position 0x90 - 0x93 */
#define nHALL_SENSOR_SETTINGS_0                 0x03
#define nHALL_SENSOR_SETTINGS_1                 0x50
#define nHALL_SENSOR_SETTINGS_2                 0x0D
#define nHALL_SENSOR_SETTINGS_3                 0x47

/* Change the HALL Switch UI Settings */
/* Memory Map Position 0xA0 - 0xA2 */
#define nHALL_UI_SETTINGS_0                     0x00
#define nHALL_UI_SETTINGS_1                     0x19
#define nHALL_UI_SETTINGS_2                     0x19

/* Change the Temperature UI Settings */
/* Memory Map Position 0xC0 - 0xC3 */
#define nTEMP_UI_SETTINGS_0                     0x00
#define nTEMP_UI_SETTINGS_1                     0x03
#define nTEMP_UI_SETTINGS_2                     0x03
#define nTEMP_UI_SETTINGS_3                     0xD5

/* Change the Device & PMU Settings */
/* Memory Map Position 0xD0 - 0xD7 */
#define nSYSTEM_SETTINGS                        0x08
#define nACTIVE_CHS                             0x3F
#define nPMU_SETTINGS                           0x03
#define nREPORT_RATES_TIMINGS_0                 0x10
#define nREPORT_RATES_TIMINGS_1                 0x30
#define nREPORT_RATES_TIMINGS_2                 0x08
#define nREPORT_RATES_TIMINGS_3                 0x14
#define nGLOBAL_EVENT_MASK                      0x00
#define nPWM_DUTY_CYCLE                         0x00

/*  Typedefs        --------------------------------------------------------------*/

// Enum to determine what to show on screen
typedef enum IC_Type
    {
    noSensor = 0,
    IQS620n = 1
    } IC_Type_e;

// 'Timer' object
typedef struct Timer
    {
    uint32_t Timer_counter;     // This timer's counter
    uint32_t Timer_start;       // This timer's start ms
    bool TimerExpired;          // Flag indicating whether timer expired
    } Timer_t;

// PXS CH  Value
typedef union
    {
    // Bitfield for PXS UI Flags
    struct
        {
        uint8_t Ch_Low;
        uint8_t Ch_High;
        };
    uint16_t Ch;
    } Ch_t;

typedef union
    {
    // Bitfield for System Flags
    struct
        {
        uint8_t NpSegmentActive     :1;
        uint8_t Event               :1;
        uint8_t InAti               :1;
        uint8_t PowerMode           :2;
        uint8_t None                :2;
        uint8_t ShowReset           :1;
        };
    uint8_t SystemFlags;
    } SystemFlags_t;

// Hall UI Flags
typedef union
    {
    // Bitfield for PXS UI Flags
    struct
        {
        uint8_t Hall_N_S            :1;
        uint8_t Hall_Prox           :1;
        uint8_t Hall_Touch          :1;
        };
    uint8_t HallFlags;
    }HallFlags_t;

// SAR and Metal Flags
typedef union
    {
    // Bitfield for SAR and Metal Flags
    struct
        {
        uint8_t FHalt           :1;
        uint8_t Movement        :1;
        uint8_t Quick_Release   :1;
        uint8_t None            :1;
        uint8_t Sar_Active      :1;
        uint8_t Metal_Prox      :1;
        uint8_t Metal_Touch     :1;
        uint8_t Metal_Type      :1;
        };
        uint8_t SARMetalFlags;
    }SARMetalFlags_t;

// "Object" for IQS620 production
typedef struct IQS620n
    {
    // System Flags
    SystemFlags_t SystemFlags;

    // Sar and Metal Flags
    SARMetalFlags_t SARMetalFlags;

    // Hall UI Flags
    HallFlags_t HallFlags;

    // Channel 0 data
    Ch_t Ch[6];
    Ch_t LTA1;

    } IQS620n_t;

/// \brief instance object for IPS-7100 Sensor
class cIQS620A
    {
public:
    cIQS620A();
    virtual ~cIQS620A();

    enum class Address : std::int8_t
        {
        Error = -1,
        IQS620n = 0x44,
        };

    bool begin();

    uint8_t configureIqs620n();

    uint8_t iqsRead();

    bool isIqsReady();

    bool waitForIqsReady();

    void setRdyPin(int rdyPin);

    void setTimer(Timer_t* timer);

    void setTimer(Timer_t* timer, uint32_t time);

    bool timerExpired(Timer_t* timer);

    bool writeRegister(uint16_t command, uint8_t pData);

    bool readRegisters(uint16_t command, std::uint8_t *pBuffer, size_t nBuffer);

    // get SAR Count
    int16_t getCh0Data();
    int16_t getCh1Data();
    int16_t getCh2Data();

    // get Hall Effect Amplitude
    int16_t getAmplitude();

private:
    //ProxFusion IC's
    IQS620n_t m_iqs620n;              // Create variable for iqs620A

    // Indicate chip is ready for polling
    bool m_chipReady = false;

    uint8_t m_rdyPin;
    // Buffer to read data into
    uint8_t m_buffer[20];
    // What type of IC is this?
    IC_Type_e m_icType;

    // Timer
    Timer_t m_errorTimer          = {0};          // Error Timer
    Timer_t m_mainTimer           = {0};          // Error Timer
    };

} // end namespace McciCatenaIqs620a

#endif /* _MCCI_CATENA_IQS620A_H_ */