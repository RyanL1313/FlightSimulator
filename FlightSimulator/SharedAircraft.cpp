//========================================================
// SharedAircraft.cpp
// Implementation file for the SharedAircraft class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

#pragma warning(disable : 4996)

#include "SharedAircraft.h"
#include <string.h>

using namespace std;

SharedAircraft::SharedAircraft()
{

}

SharedAircraft::~SharedAircraft()
{

}

void SharedAircraft::setMake(char* make)
{
	strcpy(m_sMake, make);
}

void SharedAircraft::setDescription(char* description)
{
	strcpy(m_sDescription, description);
}

void SharedAircraft::setRateOfClimb(double rateOfClimb)
{
	m_dRateOfClimb = rateOfClimb;
}

void SharedAircraft::setWingspan(double wingspan)
{
	m_dWingspan = wingspan;
}

void SharedAircraft::setFuselageLength(double fuselageLength)
{
	m_dFuselageLength = fuselageLength;
}

void SharedAircraft::setCruiseSpeed(double cruiseSpeed)
{
	m_dCruiseSpeed = cruiseSpeed;
}

void SharedAircraft::setCruiseAltitude(double cruiseAltitude)
{
	m_dCruiseAltitude = cruiseAltitude;
}

char* SharedAircraft::getMake()
{
	return m_sMake;
}

char* SharedAircraft::getDescription()
{
	return m_sDescription;
}

double SharedAircraft::getRateOfClimb()
{
	return m_dRateOfClimb;
}

double SharedAircraft::getWingspan()
{
	return m_dWingspan;
}

double SharedAircraft::getFuselageLength()
{
	return m_dFuselageLength;
}

double SharedAircraft::getCruiseSpeed()
{
	return m_dCruiseSpeed;
}

double SharedAircraft::getCruiseAltitude()
{
	return m_dCruiseAltitude;
}