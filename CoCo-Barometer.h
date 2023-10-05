/************************************************************************
																																				Source
Code Form License Notice
																								-------------------------------------------

	This Source Code Form is subject to the terms of the Mozilla Public
	License, v. 2.0. If a copy of the MPL was not distributed with this
	file, You can obtain one at http://mozilla.org/MPL/2.0/.

If it is not possible or desirable to put the notice in a particular
file, then You may include the notice in a location (such as a LICENSE
file in a relevant directory) where a recipient would be likely to look
for such a notice.
*************************************************************************/
#ifndef COCO_BAROMETER_H
#define COCO_BAROMETER_H

#include <Arduino.h>
#include <Adafruit_BMP085.h>
#include "Wire.h"

//* CONSTANTS
#define SEA_LEVEL_PRESSURE_hPa 1013.25

class Barometer {
    private:
    Adafruit_BMP085 &Barometer_REF;
    float temperature, altitude, calculatedAltitude;
    int pressure;

    public:
    Barometer(Adafruit_BMP085 &);
    ~Barometer();
    void startBarometer();
    void gatherData();
    void printData();
};

#endif