//========================================================
// SingleEngineAircraftFactory.h
// Header file for the SingleEngineAircraftFactory class.
// 
// Extends AircraftFactory to provide a means of creating
// SharedSingleEngineAircraft objects and storing them in 
// the AircraftFlyweightFactory instance.
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

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