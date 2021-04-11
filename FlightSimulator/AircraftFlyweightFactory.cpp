//========================================================
// AircraftFlyweightFactory.cpp
// Implementation file for the AircraftFlyweightFactory
// class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

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

//-------------------------------------------------
// Returns the only instance of
// AircraftFlyweightFactory that ever gets created.
//-------------------------------------------------
AircraftFlyweightFactory* AircraftFlyweightFactory::getInstance()
{
	static AircraftFlyweightFactory* theInstance = NULL;

	if (theInstance == NULL)
	{
		theInstance = new AircraftFlyweightFactory();
	}

	return theInstance;
}

//-------------------------------------------------
// Attempts to add a SharedAircraft object to 
// the vector of distinct SharedAircraft objects.
//
// Args:
//	sharedAC - The SharedAircraftObject we are
//	attempting to add
// 
// Returns:
// True if the SharedAircraft was not present in
// the flyweight factory, false if it was
//-------------------------------------------------
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

//-------------------------------------------------
// Returns a pointer to a SharedAircraft object
// present in the factory.
//
// Args:
//	make - The plane make corresponding to the 
//	SharedAircraft object we are looking for.
//
// Returns:
//	The pointer to the SharedAircraft object
//	we were looking for, or NULL if it was not
//	found
//-------------------------------------------------
SharedAircraft* AircraftFlyweightFactory::getSharedAircraft(char* make)
{
	for (int i = 0; i < m_AllSharedAircrafts.size(); i++)
	{
		if (strcmp(m_AllSharedAircrafts[i]->getMake(), make) == 0) // Found the SharedAircraft we need
			return m_AllSharedAircrafts[i];
	}

	return NULL; // Not found
}