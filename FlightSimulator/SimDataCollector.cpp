//========================================================
// SimDataCollector.cpp
// Implementation file for the SimDataCollector class.
//========================================================

#include "SimDataCollector.h"
#include <iostream>

using namespace std;

//------------------------------------------
// Default constructor
//------------------------------------------
SimDataCollector::SimDataCollector()
{

}

//------------------------------------------
// Return how many instances of this class there are.
//------------------------------------------
int SimDataCollector::getInstanceNumber()
{
	return this->m_iInstanceNumber;
}

//-----------------------------------------------
// Returns the only instance of SimDataCollector
// that ever gets created.
//-----------------------------------------------
SimDataCollector* SimDataCollector::getInstance()
{
	static SimDataCollector* theInstance = NULL;
	static int counter = 1;

	if (theInstance == NULL) // First time creating an instance of this class
	{
		theInstance = new SimDataCollector();
		theInstance->m_iInstanceNumber = counter;
		counter++;
	}

	return theInstance;
}