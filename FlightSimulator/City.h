//========================================================
// City.h
// Header file for the City class.
// 
// Defines a City object including its data such as the
// name, state, airport symbol, latitude, and longitude.
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

using namespace std;

class City
{
private:

	char m_sName[32];
	char m_sState[32];
	char m_sSymbol[4];
	double m_dLatitude;
	double m_dLongitude;

public:

	City();
	~City();
	void setName(char* name);
	void setState(char* state);
	void setSymbol(char* symbol);
	void setLatitude(double latitude);
	void setLongitude(double longitude);
	char* getName();
	char* getState();
	char* getSymbol();
	double getLatitude();
	double getLongitude();
};