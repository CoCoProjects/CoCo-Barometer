
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
#include "CoCo-Barometer.h"

Barometer::Barometer(Adafruit_BMP085 &Barometer_REF) : Barometer_REF(Barometer_REF) {
    Serial.println("Barometer object created.");
}

Barometer::~Barometer() {
    delete &Barometer_REF;
    Serial.println("Barometer object destroyed.");
}

void Barometer::startBarometer() {
    while (!Barometer_REF.begin()) {
        Serial.println("Barometer initialization failed.");
        delay(200);
    }
}

void Barometer::gatherData() {
    temperature = Barometer_REF.readTemperature();
    pressure = Barometer_REF.readPressure();
    altitude = Barometer_REF.readAltitude();
    calculatedAltitude = Barometer_REF.readAltitude(SEA_LEVEL_PRESSURE_hPa * 100);
}

void Barometer::printData() {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" *C");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" Pa");

    Serial.print("Altitude: ");
    Serial.print(altitude);
    Serial.println(" m");

    Serial.print("Calculated Altitude: ");
    Serial.print(calculatedAltitude);
    Serial.println(" m");

    Serial.println();
}