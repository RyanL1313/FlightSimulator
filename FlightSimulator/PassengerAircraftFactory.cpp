//========================================================
// PassengerAircraftFactory.cpp
// Implementation file for the PassengerAircraftFactory
// class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

#include "PassengerAircraftFactory.h"

PassengerAircraftFactory::PassengerAircraftFactory()
{

}

//-------------------------------------------------
// Returns the only instance of
// PassengerAircraftFactory that ever gets created.
//-------------------------------------------------
PassengerAircraftFactory* PassengerAircraftFactory::getInstance()
{
	static PassengerAircraftFactory* theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new PassengerAircraftFactory();
	}

	return theInstance;
}

//-------------------------------------------------
// Creates a SharedPassengerAircraft object and
// adds it to m_aff.
//
// Args:
//	fdp - The flight data parser
//-------------------------------------------------
void PassengerAircraftFactory::createSharedAircraft(FlightDataParser*& fdp)
{
	char make[32];
	char description[32];
	double rateOfClimb;
	double wingspan;
	double fuselageLength;
	double cruiseSpeed;
	double cruiseAltitude;

	
	SharedPassengerAircraft* tempSharedAircraft = new SharedPassengerAircraft();

	fdp->getAircraftData(AircraftType::PASSENGERJET, make, description, &rateOfClimb, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude);

	// Set all of the aircraft's data
	tempSharedAircraft->setMake(make);
	tempSharedAircraft->setDescription(description);
	tempSharedAircraft->setRateOfClimb(rateOfClimb);
	tempSharedAircraft->setWingspan(wingspan);
	tempSharedAircraft->setFuselageLength(fuselageLength);
	tempSharedAircraft->setCruiseSpeed(cruiseSpeed);
	tempSharedAircraft->setCruiseAltitude(cruiseAltitude);

	m_aff->addSharedAircraft(tempSharedAircraft);

	// Free the memory
	tempSharedAircraft = new SharedPassengerAircraft();
	delete tempSharedAircraft;
	tempSharedAircraft = NULL;
}