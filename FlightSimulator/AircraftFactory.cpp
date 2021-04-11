//========================================================
// AircraftFactory.cpp
// Implementation file for the AircraftFactory class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

#include "AircraftFactory.h"

AircraftFactory::~AircraftFactory()
{
	delete m_aff;
}

//------------------------------------------
// Interface for method to create a 
// SharedAircraft object.
//
// Args:
//	fdp - The flight data parser
//------------------------------------------
void AircraftFactory::createSharedAircraft(FlightDataParser*& fdp)
{

}