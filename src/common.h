#ifndef COMMON_H
#define COMMON_H

#include "usb_pd.h"

class battery
{

public:
    double batteryVoltage[4];
    double lastBatteryVoltage[4];
    unsigned long lastRun = 0;
    int remainingPower = 50;

    int batteryPin[4] = {21, 20, 17, 16};
    double batteryOffset[4] = {
        calcOffset(1015000.0, 940000.0),
        calcOffset(1008000.0, 508000.0),
        calcOffset(998000.0, 300000.0),
        calcOffset(995000.0, 239000.0),
    };

    battery(/* args */);
    void runState();

    double getBatteryVoltage();

    double calcOffset(double R1, double R2)
    {
        return ((R1 + R2) / R2);
    }
};

class graphics
{

public:
    graphics(/* args */);
    void runState();
    unsigned long lastRun = 0;

    void batteryStatus(int bat, int yOffset, char *buff);
    void setBatteryLevel(int bat, int percentage);
    void drawBattery(int bat);
    void setPowerLevel(int offsetY, char *value, int x = 125, int y = 0);
};

class usbC
{
public:
    int source;
    unsigned long lastRun = 0;
    usbC();
    void runState();
};

class charger
{
public:
    const int dpot_bat_cs = 24;
    const int dpot_usbc_cs = 0;
    const int dpot_dc_cs = 0;

    const int con_bat = 0;
    const int con_usbc_input = 0;
    const int con_dc_input = 33;
    const int con_dc_input_converter=0;
    const int con_usbc_input_converter=0;


    void runState();
    
    charger();
    void test(int cs);
    void digitalPotWrite(int cs, int address, int value);
};

struct objStoreStruct
{
    charger charger;
    battery battery;
    graphics graphics;
    usbC usbC;
};

#endif