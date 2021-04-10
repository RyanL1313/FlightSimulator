#pragma once
#include "AircraftFactory.h"
#include "SharedSingleEngineAircraft.h"

class SingleEngineAircraftFactory : public AircraftFactory
{
private:
	SingleEngineAircraftFactory(); // Private constructor for Singleton design
public:
	void createSharedAircraft(FlightDataParser*& fdp); // Creates a SharedSingleEngineAircraft object and adds it to m_aff
	static SingleEngineAircraftFactory* getInstance(); // Returns the single instance of this class
};