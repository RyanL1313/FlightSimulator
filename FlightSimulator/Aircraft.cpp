//========================================================
// Aircraft.cpp
// Implementation file for the Aircraft class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

#include "Aircraft.h"

using namespace std;

Aircraft::Aircraft()
{

}

Aircraft::~Aircraft()
{
	delete m_sa;
}

SharedAircraft* Aircraft::getSharedAircraft()
{
	return m_sa;
}

double Aircraft::getCurLatitude()
{
	return m_dCurLatitude;
}

double Aircraft::getCurLongitude()
{
	return m_dCurLongitude;
}

double Aircraft::getCurAltitude()
{
	return m_dCurAltitude;
}

void Aircraft::setSharedAircraft(SharedAircraft* sa)
{
	m_sa = sa;
}

void Aircraft::setCurLatitude(double lat)
{
	m_dCurLatitude = lat;
}

void Aircraft::setCurLongitude(double lon)
{
	m_dCurLongitude = lon;
}

void Aircraft::setCurAltitude(double alt)
{
	m_dCurAltitude = alt;
}