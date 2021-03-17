//========================================================
// City.cpp
// Implementation file for the City class
//
// Author: Ryan Lynch
// Date: March 2021
//========================================================

#pragma warning(disable : 4996)

using namespace std;

#include "City.h"
#include <string.h>

City::City()
{

}

City::~City()
{
}

void City::setName(char* name)
{
	strcpy(m_sName, name);
}

void City::setState(char* state)
{
	strcpy(m_sState, state);
}

void City::setSymbol(char* symbol)
{
	strcpy(m_sSymbol, symbol);
}

void City::setLatitude(double latitude)
{
	m_dLatitude = latitude;
}

void City::setLongitude(double longitude)
{
	m_dLongitude = longitude;
}

char* City::getName()
{
	return m_sName;
}

char* City::getState()
{
	return m_sState;
}

char* City::getSymbol()
{
	return m_sSymbol;
}

double City::getLatitude()
{
	return m_dLatitude;
}

double City::getLongitude()
{
	return m_dLongitude;
}