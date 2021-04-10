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
	double m_dCruiseAltitude;

public:

	SharedAircraft();
	~SharedAircraft();
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