//==========================================================
// Aircraft.h
// Header file for the Aircraft class.
// 
// Defines an Aircraft object including its data such as the
// make, description, rate of climb, wingspan, fuselage
// length, cruise speed, and cruise altitude.
//
// Author: Ryan Lynch
// Date: March 2021
//==========================================================

using namespace std;

class Aircraft
{
private:

	char m_sMake[32];
	char m_sDescription[32];
	double m_dRateOfClimb;
	double m_dWingspan;
	double m_dFuselageLength;
	double m_dCruiseSpeed;
	double m_dCruiseAltitude;

public:

	Aircraft();
	~Aircraft();
	void setMake(char* make);
	void setDescription(char* description);
	void setRateOfClimb(double rateOfClimb);
	void setWingspan(double wingspan);
	void setFuselageLength(double fusLength);
	void setCruiseSpeed(double cruiseSpeed);
	void setCruiseAltitude(double cruiseAltitude);
	char* getMake();
	char* getDescription();
	double getRateOfClimb();
	double getWingspan();
	double getFuselageLength();
	double getCruiseSpeed();
	double getCruiseAltitude();
};