#include "AircraftFlyweightFactory.h"

AircraftFlyweightFactory::AircraftFlyweightFactory()
{

}

AircraftFlyweightFactory::~AircraftFlyweightFactory()
{
	for (int i = 0; i < m_AllSharedAircrafts.size(); i++)
	{
		delete m_AllSharedAircrafts[i];
	}
}

AircraftFlyweightFactory* AircraftFlyweightFactory::getInstance()
{
	static AircraftFlyweightFactory* theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new AircraftFlyweightFactory();
	}

	return theInstance;
}

bool AircraftFlyweightFactory::addSharedAircraft(SharedAircraft* sharedAC)
{
	// Iterate through the vector of shared aircrafts and make sure sharedAC is not already in it
	for (int i = 0; i < m_AllSharedAircrafts.size(); i++)
	{
		if (strcmp(m_AllSharedAircrafts[i]->getMake(), sharedAC->getMake()) == 0) // This shared aircraft is already in the factory; can't add it
			return false;
	}

	m_AllSharedAircrafts.push_back(sharedAC);

	return true; // Successful add
}

SharedAircraft* AircraftFlyweightFactory::getSharedAircraft(char* make)
{
	for (int i = 0; i < m_AllSharedAircrafts.size(); i++)
	{
		if (strcmp(m_AllSharedAircrafts[i]->getMake(), make) == 0) // Found the SharedAircraft we need
			return m_AllSharedAircrafts[i];
	}

	return NULL; // Not found
}