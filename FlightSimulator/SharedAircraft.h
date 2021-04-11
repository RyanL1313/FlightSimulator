//==========================================================
// SharedAircraft.h
// Header file for the SharedAircraft class.
// 
// Defines a SharedAircraft object. Each
// SharedAircraft object has a make, description, rate of
// climb, wingspan, fuselage length, cruise speed, and
// cruise altitude.
//
// Author: Ryan Lynch
// Date: April 2021
//==========================================================

#pragma once

class SharedAircraft
{

private:

	char m_sMake[32];
	char m_sDescription[32];
	double m_dRateOfClimb;
	double m_dWingspan;
	double m_dFuselageLength;
	double m_dCruiseSpeed;
	int m_iCruiseAltitude;

public:

	SharedAircraft();
	~SharedAircraft();
	void setMake(char* make);
	void setDescription(char* description);
	void setRateOfClimb(double rateOfClimb);
	void setWingspan(double wingspan);
	void setFuselageLength(double fusLength);
	void setCruiseSpeed(double cruiseSpeed);
	void setCruiseAltitude(int cruiseAltitude);
	char* getMake();
	char* getDescription();
	double getRateOfClimb();
	double getWingspan();
	double getFuselageLength();
	double getCruiseSpeed();
	int getCruiseAltitude();
};