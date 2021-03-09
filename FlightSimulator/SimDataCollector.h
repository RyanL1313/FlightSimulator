//========================================================
// SimDataCollector.h
// Interface file for the SimDataCollector class.
//========================================================

#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "Flight.h"
#include "City.h"
#include "Aircraft.h"
#include <vector>

using namespace std;

class SimDataCollector
{
private:

	int m_iInstanceNumber; // Number of instances of this class. Used for singleton design purposes (cannot exceed 1)
	FlightDataParser* fdp; // Pointer to a FlightDataParser object
	CityDataParser* cdp; // Pointer to a CityDataParser object
	vector<Aircraft*> m_vAircrafts; // Vector of pointers to all Aircraft objects
	vector<Flight*> m_vFlights; // Vector of pointers to all Flight objects
	vector<City*> m_vCities; // Vector of pointers to all City objects
	double* m_pdCityDistances; // Pointer to an array of doubles containing distances from all cities to each other
	char** m_psCitySymbols; // Pointer to an array of character pointers containing city symbols


	SimDataCollector(); // Default constructor (private for singleton design purposes)

public:

	int getInstanceNumber();                // Return how many instances of this class there are
	static SimDataCollector* getInstance(); // Return the instance of a SimDataCollector object. Should always return the same object
};