//==========================================================
// AircraftFactory.h
// Header file for the AircraftFactory class.
// 
// Defines the interface for AircraftFactory subclasses.
// The subclasses will create SharedAircraft objects
// corresponding to the factory type. This class works with
// SimDataCollector to implement the Abstract Factory
// design pattern.
//
// Author: Ryan Lynch
// Date: April 2021
//==========================================================

#pragma once
#include <vector>
#include "SharedAircraft.h"
#include "AircraftTypes.h"
#include "FlightDataParser.h"
#include "AircraftFlyweightFactory.h"

using namespace std;

class AircraftFactory
{
private:
protected:
	AircraftFlyweightFactory* m_aff = AircraftFlyweightFactory::getInstance(); // The flyweight factory singleton instance to be used by the subclasses
public:

	~AircraftFactory(); // Destructor

	virtual void createSharedAircraft(FlightDataParser*& fdp); // Gets overridden in the subclasses to create a SharedAircraft and add it to m_aff
};