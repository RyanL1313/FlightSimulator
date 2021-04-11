//========================================================
// PassengerAircraftFactory.h
// Header file for the PassengerAircraftFactory class.
// 
// Extends AircraftFactory to provide a means of creating
// SharedPassengerAircraft objects and storing them in 
// the AircraftFlyweightFactory instance.
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

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