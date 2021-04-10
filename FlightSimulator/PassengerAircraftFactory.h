#pragma once
#include "AircraftFactory.h"
#include "SharedPassengerAircraft.h"

class PassengerAircraftFactory : public AircraftFactory
{
private:
	PassengerAircraftFactory(); // Private constructor for Singleton design
public:
	void createSharedAircraft(FlightDataParser*& fdp); // Creates a SharedPassengerAircraft object and adds it to m_aff
	static PassengerAircraftFactory* getInstance(); // Returns the single instance of this class
};