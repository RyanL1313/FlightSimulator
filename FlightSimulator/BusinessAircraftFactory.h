#pragma once
#include "AircraftFactory.h"
#include "SharedBusinessAircraft.h"

class BusinessAircraftFactory : public AircraftFactory
{
private:
	BusinessAircraftFactory(); // Private constructor for Singleton design
public:
	void createSharedAircraft(FlightDataParser*& fdp); // Creates a SharedBusinessAircraft object and adds it to m_aff
	static BusinessAircraftFactory* getInstance(); // Returns the single instance of this class
};