//========================================================
// Flight.cpp
// Implementation file for the Flight class
//
// Author: Ryan Lynch
// Date: April 2021
//========================================================

#pragma warning(disable : 4996)

#include "Flight.h"
#include <string.h>
#include <iostream>

using namespace std;

//----------------------------------------
// Default constructor
//----------------------------------------
Flight::Flight()
{
	m_bComplete = false;
	m_bOngoing = false;
}

//----------------------------------------
// Destructor
//----------------------------------------
Flight::~Flight()
{
	delete m_ac;
}

void Flight::setAirline(char* airline)
{
	strcpy(m_sAirline, airline);
}

void Flight::setAircraft(Aircraft* ac)
{
	m_ac = ac;
}

void Flight::setFlightNumber(int flightNumber)
{
	m_iFlightNumber = flightNumber;
}

void Flight::setDepartureLocation(char* depLocation)
{
	strcpy(m_sDepartureLocation, depLocation);
}

void Flight::setDepartureHour(int depHour)
{
	m_iDepartureHour = depHour;
}

void Flight::setDepartureMinute(int depMinute)
{
	m_iDepartureMinute = depMinute;
}

void Flight::setDepartureTime()
{
	m_dDepartureTime = (double)m_iDepartureHour + (m_iDepartureMinute / 60.0);
}

void Flight::setDestination(char* destination)
{
	strcpy(m_sDestination, destination);
}

void Flight::setEstArrivalHour()
{
	double arrHour = m_dEstArrivalTime;
	m_iEstArrivalHour = (int)arrHour;
}

void Flight::setEstArrivalMinute()
{
	double arrMinute = m_dEstArrivalTime;
	int leftSideDecimal = (int)arrMinute;
	arrMinute -= leftSideDecimal; // Leaves just the decimal (the minutes) remaining

	// Solve the ratio arrMinute = x/60 to convert the decimal values to the arrival minute
	// So, x = 60 * arrMinute
	m_iEstArrivalMinute = 60 * arrMinute;
}

void Flight::setEstArrivalTime(double time)
{
	m_dEstArrivalTime = time;
}

void Flight::setCurrentHour(int hour)
{
	m_iCurrentHour = hour;
}

void Flight::setCurrentMinute(int minute)
{
	m_iCurrentMinute = minute;
}

void Flight::setCurrentTime(double time)
{
	m_dCurrentTime = time;
}

void Flight::setDistReachCruiseAlt(double distance)
{
	//m_dDistReachCruiseAlt = distance;
}

void Flight::setDepCityLatitude(double latitude)
{
	m_dDepCityLatitude = latitude;
}

void Flight::setDepCityLongitude(double longitude)
{
	m_dDepCityLongitude = longitude;
}

void Flight::setDestCityLatitude(double latitude)
{
	m_dDestCityLatitude = latitude;
}

void Flight::setDestCityLongitude(double longitude)
{
	m_dDestCityLongitude = longitude;
}

void Flight::setDepCityName(char* city)
{
	strcpy(m_sDepCityName, city);
}

void Flight::setDepStateName(char* state)
{
	strcpy(m_sDepStateName, state);
}

void Flight::setDestCityName(char* city)
{
	strcpy(m_sDestCityName, city);
}

void Flight::setDestStateName(char* state)
{
	strcpy(m_sDestStateName, state);
}

void Flight::setCurrentSpeed(double speed)
{
	m_dCurSpeed = speed;
}

void Flight::setTripTime(double tripTime)
{
	m_dTripTime = tripTime;
}

void Flight::setTotalDistance(double distance)
{
	m_dTotalDistance = distance;
}

void Flight::setDistanceFromStart(double distance)
{
	m_dDistanceFromStart = distance;
}

void Flight::setDistanceToDestination(double distance)
{
	m_dDistanceToDestination = distance;
}

void Flight::setCompleteFlag(bool val)
{
	m_bComplete = val;
}

void Flight::setOngoingFlag(bool val)
{
	m_bOngoing = val;
}

char* Flight::getAirline()
{
	return m_sAirline;
}

Aircraft* Flight::getAircraft()
{
	return m_ac;
}

int Flight::getFlightNumber()
{
	return m_iFlightNumber;
}

char* Flight::getDepartureLocation()
{
	return m_sDepartureLocation;
}

int Flight::getDepartureHour()
{
	return m_iDepartureHour;
}

int Flight::getDepartureMinute()
{
	return m_iDepartureMinute;
}

double Flight::getDepartureTime()
{
	return m_dDepartureTime;
}

char* Flight::getDestination()
{
	return m_sDestination;
}

int Flight::getEstArrivalHour()
{
	return m_iEstArrivalHour;
}

int Flight::getEstArrivalMinute()
{
	return m_iEstArrivalMinute;
}

double Flight::getEstArrivalTime()
{
	return m_dEstArrivalTime;
}

int Flight::getCurrentHour()
{
	return m_iCurrentHour;
}

int Flight::getCurrentMinute()
{
	return m_iCurrentMinute;
}

double Flight::getCurrentTime()
{
	return m_dCurrentTime;
}

double Flight::getDistReachCruiseAlt()
{
	//return m_dDistReachCruiseAlt;
	return 2.0;
}

double Flight::getDepCityLatitude()
{
	return m_dDepCityLatitude;
}

double Flight::getDepCityLongitude()
{
	return m_dDepCityLongitude;
}

double Flight::getDestCityLatitude()
{
	return m_dDestCityLatitude;
}

double Flight::getDestCityLongitude()
{
	return m_dDestCityLongitude;
}

char* Flight::getDepCityName()
{
	return m_sDepCityName;
}

char* Flight::getDepStateName()
{
	return m_sDepStateName;
}

char* Flight::getDestCityName()
{
	return m_sDestCityName;
}

char* Flight::getDestStateName()
{
	return m_sDestStateName;
}

double Flight::getCurrentSpeed()
{
	return m_dCurSpeed;
}

double Flight::getTripTime()
{
	return m_dTripTime;
}

double Flight::getTotalDistance()
{
	return m_dTotalDistance;
}

double Flight::getDistanceFromStart()
{
	return m_dDistanceFromStart;
}

double Flight::getDistanceToDestination()
{
	return m_dDistanceToDestination;
}

bool Flight::getCompleteFlag()
{
	return m_bComplete;
}

bool Flight::getOngoingFlag()
{
	return m_bOngoing;
}

double Flight::updateLatitude()
{
	double timeFraction = (m_dCurrentTime - m_dDepartureTime) / m_dTripTime; // Elapsed time / total trip time
	double currentLatitude = m_dDepCityLatitude + (m_dDestCityLatitude - m_dDepCityLatitude) * timeFraction; // Update the latitude

	return currentLatitude;
}

double Flight::updateLongitude()
{
	double timeFraction = (m_dCurrentTime - m_dDepartureTime) / m_dTripTime; // Elapsed time / total trip time
	double currentLongitude = m_dDepCityLongitude + (m_dDestCityLongitude - m_dDepCityLongitude) * timeFraction; // Update the longitude

	return currentLongitude;
}

void Flight::updateDistanceFromCities()
{
	double timeFraction = (m_dCurrentTime - m_dDepartureTime) / m_dTripTime; // Elapsed time / total trip time
	m_dDistanceFromStart = m_dTotalDistance * timeFraction; // Update the distance from the departure city
	m_dDistanceToDestination = m_dTotalDistance - m_dDistanceFromStart; // Update the distance to the destination city
}

double Flight::updateAltitude()
{
	double possibleAltitude = ((m_dCurrentTime * 60.0) - (m_dDepartureTime * 60.0)) * m_ac->getSharedAircraft()->getRateOfClimb(); // Gives an altitude in feet (minutes * feet/minute)
	double currentAltitude;

	if (m_dCurrentTime >= m_dTimeStartDescending) // At a point in the flight when we need to descend
	{
		double timeLeft = m_dEstArrivalTime - m_dCurrentTime; // Gets smaller as the flight approaches the destination
		currentAltitude = (timeLeft * 60.0) * m_ac->getSharedAircraft()->getRateOfClimb(); // Time left in minutes * rate of climb in feet/min gives current altitude in feet
	}
	else if (possibleAltitude >= m_ac->getSharedAircraft()->getCruiseAltitude()) // Don't need to descend, and the new altitude would pass the cruise altitude. Just use the cruise altitude
	{
		currentAltitude = m_ac->getSharedAircraft()->getCruiseAltitude();
	}
	else // The flight is ascending and at an altitude below its cruise altitude
	{
		currentAltitude = possibleAltitude;
	}
	
	return currentAltitude;
}

//-----------------------------------------
// Calculate when the plane will reach
// cruise altitude (might never happen)
// and when it needs to start descending.
// If cruise altitude cannot be reached
// while also having enough time to fully
// descend, the time to start descending
// should be the midpoint of the flight.
//-----------------------------------------
void Flight::calculateAltitudeChangeTimes()
{
	double hoursReachCruiseAlt = (m_ac->getSharedAircraft()->getCruiseAltitude() / m_ac->getSharedAircraft()->getRateOfClimb()) / 60.0; // Calculate how many hours it takes to reach cruise altitude
	double hoursReachCruiseAltAndGround = hoursReachCruiseAlt * 2.0; // This is how long it takes to reach cruise altitude and reach the ground from cruise altitude
	m_dTimeReachCruiseAlt = m_dDepartureTime + hoursReachCruiseAlt; // Gets the time in hours when this cruise altitude will be reached
	double timeReachCruiseAltAndGround = m_dDepartureTime + hoursReachCruiseAltAndGround; // The time the plane would land if it reached cruise altitude then landed from there

	if (timeReachCruiseAltAndGround >= m_dEstArrivalTime) // No time to rise to cruise altitude and land in the flight
		m_dTimeStartDescending = (m_dDepartureTime + m_dEstArrivalTime) / 2; // The plane will descend at the midpoint of the flight
	else
		m_dTimeStartDescending = m_dEstArrivalTime - hoursReachCruiseAlt; // Need to start descending at arrival time - hours to reach cruise altitude

}