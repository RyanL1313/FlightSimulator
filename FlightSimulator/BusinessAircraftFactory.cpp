#include "BusinessAircraftFactory.h"

BusinessAircraftFactory::BusinessAircraftFactory()
{

}

BusinessAircraftFactory* BusinessAircraftFactory::getInstance()
{
	static BusinessAircraftFactory* theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new BusinessAircraftFactory();
	}

	return theInstance;
}

void BusinessAircraftFactory::createSharedAircraft(FlightDataParser*& fdp)
{
	char make[32];
	char description[32];
	double rateOfClimb;
	double wingspan;
	double fuselageLength;
	double cruiseSpeed;
	double cruiseAltitude;

		SharedBusinessAircraft* tempSharedAircraft = new SharedBusinessAircraft();
		fdp->getAircraftData(AircraftType::BUSINESSJET, make, description, &rateOfClimb, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude);

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
		tempSharedAircraft = new SharedBusinessAircraft();
		delete tempSharedAircraft;
		tempSharedAircraft = NULL;
}