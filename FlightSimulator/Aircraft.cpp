//========================================================
// Aircraft.cpp
// Implementation file for the Aircraft class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

#pragma warning(disable : 4996)

#include "Aircraft.h"
#include <string.h>

using namespace std;

Aircraft::Aircraft()
{

}

Aircraft::~Aircraft()
{

}

void Aircraft::setMake(char* make)
{
	strcpy(m_sMake, make);
}

void Aircraft::setDescription(char* description)
{
	strcpy(m_sDescription, description);
}

void Aircraft::setRateOfClimb(double rateOfClimb)
{
	m_dRateOfClimb = rateOfClimb;
}

void Aircraft::setWingspan(double wingspan)
{
	m_dWingspan = wingspan;
}

void Aircraft::setFuselageLength(double fuselageLength)
{
	m_dFuselageLength = fuselageLength;
}

void Aircraft::setCruiseSpeed(double cruiseSpeed)
{
	m_dCruiseSpeed = cruiseSpeed;
}

void Aircraft::setCruiseAltitude(double cruiseAltitude)
{
	m_dCruiseAltitude = cruiseAltitude;
}

char* Aircraft::getMake()
{
	return m_sMake;
}

char* Aircraft::getDescription()
{
	return m_sDescription;
}

double Aircraft::getRateOfClimb()
{
	return m_dRateOfClimb;
}

double Aircraft::getWingspan()
{
	return m_dWingspan;
}

double Aircraft::getFuselageLength()
{
	return m_dFuselageLength;
}

double Aircraft::getCruiseSpeed()
{
	return m_dCruiseSpeed;
}

double Aircraft::getCruiseAltitude()
{
	return m_dCruiseAltitude;
}