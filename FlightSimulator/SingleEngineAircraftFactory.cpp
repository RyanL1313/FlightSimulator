//========================================================
// SingleEngineAircraftFactory.cpp
// Implementation file for the SingleEngineAircraftFactory
// class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================


#include "SingleEngineAircraftFactory.h"

SingleEngineAircraftFactory::SingleEngineAircraftFactory()
{

}

//-------------------------------------------------
// Returns the only instance of
// SingleEngineAircraftFactory that ever gets created.
//-------------------------------------------------
SingleEngineAircraftFactory* SingleEngineAircraftFactory::getInstance()
{
	static SingleEngineAircraftFactory* theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new SingleEngineAircraftFactory();
	}

	return theInstance;
}

//-------------------------------------------------
// Creates a SharedSingleEngineAircraft object and
// adds it to m_aff.
//
// Args:
//	fdp - The flight data parser
//-------------------------------------------------
void SingleEngineAircraftFactory::createSharedAircraft(FlightDataParser*& fdp)
{
	char make[32];
	char description[32];
	double rateOfClimb;
	double wingspan;
	double fuselageLength;
	double cruiseSpeed;
	double cruiseAltitude;

	SharedSingleEngineAircraft* tempSharedAircraft = new SharedSingleEngineAircraft();

	fdp->getAircraftData(AircraftType::SINGLEENGINE, make, description, &rateOfClimb, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude);

	// Set all of the aircraft data
	tempSharedAircraft->setMake(make);
	tempSharedAircraft->setDescription(description);
	tempSharedAircraft->setRateOfClimb(rateOfClimb);
	tempSharedAircraft->setWingspan(wingspan);
	tempSharedAircraft->setFuselageLength(fuselageLength);
	tempSharedAircraft->setCruiseSpeed(cruiseSpeed);
	tempSharedAircraft->setCruiseAltitude(cruiseAltitude);

	m_aff->addSharedAircraft(tempSharedAircraft);

	// Free the memory
	tempSharedAircraft = new SharedSingleEngineAircraft();
	delete tempSharedAircraft;
	tempSharedAircraft = NULL;
}