/*

Module: MCCI_Catena_Iqs620a.cpp

Function:
    Implementation code for MCCI Catena IQS620A sensor library (simple).

Copyright and License:
    See accompanying LICENSE file for copyright and license information.

Author:
    Pranau R, MCCI Corporation   April 2023

*/

#include "MCCI_Catena_Iqs620a.h"
#include <Wire.h>

using namespace McciCatenaIqs620a;

cIQS620A::cIQS620A()
    {
    //default constructor
    }

cIQS620A::~cIQS620A()
    {
    }

bool cIQS620A::begin()
    {
    // Get the Version info
    uint8_t res = 0;
    res = configureIqs620n();
    readRegisters(VERSION_INFO, m_buffer, sizeof(m_buffer));

    // Set the appropriate IC
    if(m_buffer[0] == IQS620_PRODUCT_NR && m_buffer[1] == IQS620N_SOFTWARE_NR && m_buffer[2] == IQS620N_HARDWARE_NR)
        {
        m_icType = IQS620n;
        }
    // No valid IC type found
    else
        {
        m_icType = noSensor;
        }

    setTimer(&m_mainTimer);

    if (m_icType == IQS620n)
        {
        // setup device
        res = configureIqs620n();
        }

    // An error occured
    if(res)
        {
        // Serial.print("res: ");
        // Serial.println(res);
        }

    delay(1000);

    // Initialise Mode timer
    m_errorTimer.Timer_counter = THREE_SEC;       // 3s timer
    m_mainTimer.Timer_counter = ONE_SEC;          // 1s timer

	return m_icType;
    }

uint8_t cIQS620A::configureIqs620n()
    {
    uint8_t res = 0;

    /* Change the Device & PMU Settings */
    /* Memory Map Position 0xD0 - 0xD7 */
    res |= writeRegister(DEV_SETTINGS,                      (uint8_t)nSYSTEM_SETTINGS);
    res |= writeRegister(ACTIVE_CHANNELS,                   (uint8_t)nACTIVE_CHS);
    res |= writeRegister(POWER_MODE_SETTINGS,               (uint8_t)nPMU_SETTINGS);
    res |= writeRegister(NORMAL_MODE_REPORT_RATE,           (uint8_t)nREPORT_RATES_TIMINGS_0);
    res |= writeRegister(lOW_POWER_MODE_REPORT_RATE,        (uint8_t)nREPORT_RATES_TIMINGS_1);
    res |= writeRegister(ULTRA_LOW_POWER_MODE_REPORT_RATE,  (uint8_t)nREPORT_RATES_TIMINGS_2);
    res |= writeRegister(AUTO_MODE_TIME,                    (uint8_t)nREPORT_RATES_TIMINGS_3);
    res |= writeRegister(GLOBAL_EVENT_MASK,                 (uint8_t)nGLOBAL_EVENT_MASK);
    res |= writeRegister(PWM_DUTY_CYCLE,                    (uint8_t)nPWM_DUTY_CYCLE);

    /* Configure the Prox Sensor Settings 0 */
    /* Memory Map Position 0x40 - 0x4B */
    res |= writeRegister(PXS_SETTINGS_0_0, (uint8_t)nPXS_SETTINGS0_0);
    res |= writeRegister(PXS_SETTINGS_0_1, (uint8_t)nPXS_SETTINGS0_1);
    res |= writeRegister(PXS_SETTINGS_0_2, (uint8_t)nPXS_SETTINGS0_2);
    res |= writeRegister(PXS_SETTINGS_0_3, (uint8_t)nPXS_SETTINGS0_3);
    res |= writeRegister(PXS_SETTINGS_0_4, (uint8_t)nPXS_SETTINGS0_4);
    res |= writeRegister(PXS_SETTINGS_0_5, (uint8_t)nPXS_SETTINGS0_5);
    res |= writeRegister(PXS_SETTINGS_0_6, (uint8_t)nPXS_SETTINGS0_6);
    res |= writeRegister(PXS_SETTINGS_0_7, (uint8_t)nPXS_SETTINGS0_7);
    res |= writeRegister(PXS_SETTINGS_0_8, (uint8_t)nPXS_SETTINGS0_8);
    res |= writeRegister(PXS_SETTINGS_0_9, (uint8_t)nPXS_SETTINGS0_9);
    res |= writeRegister(PXS_SETTINGS_0_10, (uint8_t)nPXS_SETTINGS0_10);
    res |= writeRegister(PXS_SETTINGS_0_11, (uint8_t)nPXS_SETTINGS0_11);

    /* Configure the Prox Sensor Settings 1 */
    /* Memory Map Position 0x50 - 0x57 */
    res |= writeRegister(PXS_SETTINGS_1_0, (uint8_t)nPXS_SETTINGS1_0);
    res |= writeRegister(PXS_SETTINGS_1_1, (uint8_t)nPXS_SETTINGS1_1);
    res |= writeRegister(PXS_SETTINGS_1_2, (uint8_t)nPXS_SETTINGS1_2);
    res |= writeRegister(PXS_SETTINGS_1_3, (uint8_t)nPXS_SETTINGS1_3);
    res |= writeRegister(PXS_SETTINGS_1_4, (uint8_t)nPXS_SETTINGS1_4);
    res |= writeRegister(PXS_SETTINGS_1_5, (uint8_t)nPXS_SETTINGS1_5);
    res |= writeRegister(PXS_SETTINGS_1_6, (uint8_t)nPXS_SETTINGS1_6);
    res |= writeRegister(PXS_SETTINGS_1_7, (uint8_t)nPXS_SETTINGS1_7);

    /* Change the Prox UI Settings */
    /* Memory Map Position 0x60 - 0x66 */
    res |= writeRegister(PXS_UI_SETTINGS_0, (uint8_t)nPXS_UI_SETTINGS_0);
    res |= writeRegister(PXS_UI_SETTINGS_1, (uint8_t)nPXS_UI_SETTINGS_1);
    res |= writeRegister(PXS_UI_SETTINGS_2, (uint8_t)nPXS_UI_SETTINGS_2);
    res |= writeRegister(PXS_UI_SETTINGS_3, (uint8_t)nPXS_UI_SETTINGS_3);
    res |= writeRegister(PXS_UI_SETTINGS_4, (uint8_t)nPXS_UI_SETTINGS_4);
    res |= writeRegister(PXS_UI_SETTINGS_5, (uint8_t)nPXS_UI_SETTINGS_5);
    res |= writeRegister(PXS_UI_SETTINGS_6, (uint8_t)nPXS_UI_SETTINGS_6);

    /* Configure the SAR UI Settings */ // Uncomment this configuration if using SAR UI
    /* Memory Map Position 0x70 - 0x75 */
    // res |= writeRegister(SAR_UI_SETTINGS_0, (uint8_t)nSAR_UI_SETTINGS_0);
    // res |= writeRegister(SAR_UI_SETTINGS_1, (uint8_t)nSAR_UI_SETTINGS_1);
    // res |= writeRegister(SAR_UI_SETTINGS_2, (uint8_t)nSAR_UI_SETTINGS_2);
    // res |= writeRegister(SAR_UI_SETTINGS_3, (uint8_t)nSAR_UI_SETTINGS_3);
    // res |= writeRegister(SAR_UI_SETTINGS_4, (uint8_t)nSAR_UI_SETTINGS_4);
    // res |= writeRegister(SAR_UI_SETTINGS_5, (uint8_t)nSAR_UI_SETTINGS_5);

    /* Change the Metal Detect UI Settings */
    /* Memory Map Position 0x80 - 0x83 */
    res |= writeRegister(METAL_UI_SETTINGS_0, (uint8_t)nMETAL_DETECT_UI_SETTINGS_0);
    res |= writeRegister(METAL_UI_SETTINGS_1, (uint8_t)nMETAL_DETECT_UI_SETTINGS_1);
    res |= writeRegister(METAL_UI_SETTINGS_2, (uint8_t)nMETAL_DETECT_UI_SETTINGS_2);
    res |= writeRegister(METAL_UI_SETTINGS_3, (uint8_t)nMETAL_DETECT_UI_SETTINGS_3);

    /* Change the HALL Sensor Settings */
    /* Memory Map Position 0x90 - 0x93 */
    res |= writeRegister(HALL_SENS_SETTINGS_0, (uint8_t)nHALL_SENSOR_SETTINGS_0);
    res |= writeRegister(HALL_SENS_SETTINGS_1, (uint8_t)nHALL_SENSOR_SETTINGS_1);
    res |= writeRegister(HALL_SENS_SETTINGS_2, (uint8_t)nHALL_SENSOR_SETTINGS_2);
    res |= writeRegister(HALL_SENS_SETTINGS_3, (uint8_t)nHALL_SENSOR_SETTINGS_3);

    /* Change the HALL Switch UI Settings */
    /* Memory Map Position 0xA0 - 0xA2 */
    res |= writeRegister(HALL_UI_SETTINGS_0, (uint8_t)nHALL_UI_SETTINGS_0);
    res |= writeRegister(HALL_UI_SETTINGS_1, (uint8_t)nHALL_UI_SETTINGS_1);
    res |= writeRegister(HALL_UI_SETTINGS_2, (uint8_t)nHALL_UI_SETTINGS_2);

    /* Change the Temperature UI Settings */
    /* Memory Map Position 0xC0 - 0xC3 */
    res |= writeRegister(TEMP_UI_SETTINGS_0, (uint8_t)nTEMP_UI_SETTINGS_0);
    res |= writeRegister(TEMP_UI_SETTINGS_1, (uint8_t)nTEMP_UI_SETTINGS_1);
    res |= writeRegister(TEMP_UI_SETTINGS_2, (uint8_t)nTEMP_UI_SETTINGS_2);
    res |= writeRegister(TEMP_UI_SETTINGS_3, (uint8_t)nTEMP_UI_SETTINGS_3);

    // Wait for Redo Ati to complete
    do
        {
        res |= readRegisters(SYSTEM_FLAGS, &m_iqs620n.SystemFlags.SystemFlags, sizeof(&m_iqs620n.SystemFlags.SystemFlags));
        }
    while (!res && m_iqs620n.SystemFlags.InAti);

    return res;
    }

bool cIQS620A::isIqsReady()
    {
    if (digitalRead(this->m_rdyPin) == 0)
        {
        return true;
        }
    else
        {
        return false;
        }
    }

// wait for IQS620A to provide a ready signal (low) on IQS620A RDY pin
bool cIQS620A::waitForIqsReady()
    {
    uint32_t timeout=0;
    while (1)
        {
        if(digitalRead(this->m_rdyPin) == 1)
            break;
        if (timeout++ > 1000000)
            goto fatal_error;
        }
    timeout=0;
    while (1) {
        if(digitalRead(this->m_rdyPin) ==0 )
            break;
        if (timeout++ > 1000000)
            goto fatal_error;
    }
    return true;
fatal_error:
    Serial.println("Fatal Error: IQS620A ready pin is not toggling");
    return false;
    }

void cIQS620A::setRdyPin(int rdyPin)
    {
    this->m_rdyPin = rdyPin;
    pinMode(this->m_rdyPin, INPUT_PULLUP);
    }

uint8_t cIQS620A::iqsRead()
    {
    uint8_t res = 0;

    if(m_icType == IQS620n)
        {
        // Read version number to insure we still have the correct device attached - otherwise, do setup
        res = readRegisters(VERSION_INFO, m_buffer, sizeof(m_buffer));

        // System flags, Global Events and PXS UI Flags - 9 bytes
        res |= readRegisters(SYSTEM_FLAGS, &m_iqs620n.SystemFlags.SystemFlags, sizeof(&m_iqs620n.SystemFlags.SystemFlags));

        // Read PXS Channel 0 Data - 12 bytes
        res |= readRegisters(CHANNEL0_CS_LOW, &m_iqs620n.Ch[0].Ch_Low, sizeof(&m_iqs620n.Ch[0].Ch_Low));

        // Read channel 1 for SAR
        res |= readRegisters(CHANNEL1_CS_LOW, &m_iqs620n.Ch[1].Ch_Low, sizeof(&m_iqs620n.Ch[1].Ch_Low));

        // Read channel 2 for SAR
        res |= readRegisters(CHANNEL2_CS_LOW, &m_iqs620n.Ch[2].Ch_Low, sizeof(&m_iqs620n.Ch[2].Ch_Low));

        // Read channel 4 for SAR
        res |= readRegisters(CHANNEL4_CS_LOW, &m_iqs620n.Ch[4].Ch_Low, sizeof(&m_iqs620n.Ch[4].Ch_Low));

        // Read channel 5 for SAR
        res |= readRegisters(CHANNEL5_CS_LOW, &m_iqs620n.Ch[5].Ch_Low, sizeof(&m_iqs620n.Ch[5].Ch_Low));
        }

    // A read error occurred
    if(res)
        {
        // Serial.print("res : ");
        // Serial.println(res);
        }

    // reset timer
    setTimer(&m_errorTimer);

    m_chipReady = true;

    if(timerExpired(&m_errorTimer))
        {
        //Serial.print("Timer Expired : ");
        //Serial.println(ERR_TIMEOUT);
        }
    }

bool cIQS620A::writeRegister(uint16_t reg, uint8_t pData)
    {
    Wire.beginTransmission((uint8_t) Address::IQS620n);
    Wire.write(reg);
    Wire.write(pData);

    if (Wire.endTransmission() != 0)
        {
        return false;
        }

    return true;
    }

bool cIQS620A::readRegisters(uint16_t reg, std::uint8_t *pBuffer, size_t nBuffer)
    {
    if (pBuffer == nullptr || nBuffer > 32)
        {
        return false;
        }

    Wire.beginTransmission((uint8_t) Address::IQS620n);
    if (Wire.write((uint8_t)reg) != 1)
        {
        return false;
        }
    if (Wire.endTransmission() != 0)
        {
        return false;
        }

    auto nReadFrom = Wire.requestFrom((uint8_t) Address::IQS620n, std::uint8_t(nBuffer));

    if (nReadFrom != nBuffer)
        {
        return false;
        }

    auto const nResult = unsigned(Wire.available());

    if (nResult > nBuffer)
        {
        return false;
        }

    for (unsigned i = 0; i < nResult; ++i)
        {
        pBuffer[i] = Wire.read();
        }

    if (nResult != nBuffer)
        {
        return false;
        }

    return true;
    }

int16_t cIQS620A::getCh0Data()
    {
    return m_iqs620n.Ch[0].Ch;    // return Channel Data
    }

int16_t cIQS620A::getCh1Data()
    {
    return m_iqs620n.Ch[1].Ch;    // return Channel Data
    }

int16_t cIQS620A::getCh2Data()
    {
    return m_iqs620n.Ch[2].Ch;    // return Channel Data
    }

int16_t cIQS620A::getAmplitude()
    {
    int16_t hallEffectch4 = m_iqs620n.Ch[4].Ch;  // get Channel Data
    int16_t hallEffectch5 = m_iqs620n.Ch[5].Ch;  // get Channel Data
    return hallEffectch4 - hallEffectch5;
    }

void cIQS620A::setTimer(Timer_t* timer)
    {
    timer->TimerExpired = false;
    timer->Timer_start = millis();  // get this instant millis
    }

void cIQS620A::setTimer(Timer_t* timer, uint32_t time)
    {
    timer->TimerExpired = false;
    timer->Timer_start = millis();  // get this instant millis
    timer->Timer_counter = time;  // the timeout time for the timer
    }

bool cIQS620A::timerExpired(Timer_t* timer)
    {
    // This is a timeout
    if(((millis() - timer->Timer_start) >= timer->Timer_counter))
        timer->TimerExpired = true;
    // We haven't timed out yet
    else
        timer->TimerExpired  = false;

    // Return the state of this timer
    return timer->TimerExpired;
    }

/**** end of MCCI_Catena_Iqs620a.cpp ****/