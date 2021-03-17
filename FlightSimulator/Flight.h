//==========================================================
// Flight.h
// Header file for the Flight class.
// 
// Defines a Flight object including its data such as the
// make, description, rate of climb, wingspan, fuselage
// length, cruise speed, and cruise altitude.
//
// Author: Ryan Lynch
// Date: March 2021
//==========================================================

#pragma once

using namespace std;

class Flight
{
private:

	char m_sAirline[32]; // The airline
	char m_sPlaneType[32]; // The aircraft type
	int m_iFlightNumber; // The flight number
	char m_sDepartureLocation[4]; // The departure city symbol
	int m_iDepartureHour; // The departure hour
	int m_iDepartureMinute; // The departure minute
	double m_dDepartureTime; // A combined hours and minutes of the departure time
	char m_sDestination[4]; // The destination city symbol
	int m_iEstArrivalHour; // Estimated time of the flight's arrival hour
	int m_iEstArrivalMinute; // Estimated time of the flight's arrival minute
	double m_dEstArrivalTime; // A combined hours and minutes of the arrival time
	int m_iCurrentHour; // Current hour of the simulation
	int m_iCurrentMinute; // Current minute of the simulation
	double m_dCurrentTime; // A combined hours and minutes of the current time
	double m_dTimeReachCruiseAlt; // The time (hours) when the flight will reach cruise altitude
	double m_dTimeStartDescending; // The time (hours) when the flight needs to start descending
	double m_dDepCityLatitude; // The departure city's latitude
	double m_dDepCityLongitude; // The departure city's longitude
	double m_dDestCityLatitude; // The destination city's latitude
	double m_dDestCityLongitude; // The destination city's longitude
	char m_sDepCityName[32]; // The full name of the departure city
	char m_sDepStateName[32]; // The full name of the departure state
	char m_sDestCityName[32]; // The full name of the departure city
	char m_sDestStateName[32]; // The full name of the destination state
	double m_dCurrentAltitude; // The current altitude of the plane
	double m_dCurrentLatitude; // The current latitude of the plane
	double m_dCurrentLongitude; // The current longitude of the plane
	double m_dCruiseAltitude; // The maximum altitude in feet that the plane will reach
	double m_dRateOfClimb; // The rate of climb of the plane in feet/minute
	double m_dCurrentSpeed; // The current speed of the plane in miles per hour (it's just the cruise speed)
	double m_dTripTime; // The total time the flight will take in hours
	double m_dTotalDistance; // The total distance (in miles) the flight spans
	double m_dDistanceFromStart; // The distance (in miles) the flight is from the departure city
	double m_dDistanceToDestination; // The distance (in miles) the flight is from the destination
	bool m_bComplete; // Flag to indicate if the flight has landed or not
	bool m_bOngoing; // Flag to indicate if the flight is in the air

public:

	Flight();
	~Flight();
	void setAirline(char* airline);
	void setPlaneType(char* planeType);
	void setFlightNumber(int flightNumber);
	void setDepartureLocation(char* depLocation);
	void setDepartureHour(int depHour);
	void setDepartureMinute(int depMinute);
	void setDepartureTime();
	void setDestination(char* destination);
	void setEstArrivalHour();
	void setEstArrivalMinute();
	void setEstArrivalTime(double time);
	void setCurrentHour(int hour);
	void setCurrentMinute(int minute);
	void setCurrentTime(double time);
	void setDistReachCruiseAlt(double distance);
	void setDepCityLatitude(double latitude);
	void setDepCityLongitude(double longitude);
	void setDestCityLatitude(double latitude);
	void setDestCityLongitude(double longitude);
	void setDepCityName(char* city);
	void setDepStateName(char* state);
	void setDestCityName(char* city);
	void setDestStateName(char* state);
	void setCurrentAltitude(double altitude);
	void setCurrentLatitude(double latitude);
	void setCurrentLongitude(double longitude);
	void setCruiseAltitude(double altitude);
	void setRateOfClimb(double roc);
	void setCurrentSpeed(double speed);
	void setTripTime(double tripTime);
	void setTotalDistance(double distance);
	void setDistanceFromStart(double distance);
	void setDistanceToDestination(double distance);
	void setCompleteFlag(bool val);
	void setOngoingFlag(bool val);
	char* getAirline();
	char* getPlaneType();
	int getFlightNumber();
	char* getDepartureLocation();
	int getDepartureHour();
	int getDepartureMinute();
	double getDepartureTime();
	char* getDestination();
	int getEstArrivalHour();
	int getEstArrivalMinute();
	double getEstArrivalTime();
	int getCurrentHour();
	int getCurrentMinute();
	double getCurrentTime();
	double getDistReachCruiseAlt();
	double getDepCityLatitude();
	double getDepCityLongitude();
	double getDestCityLatitude();
	double getDestCityLongitude();
	char* getDepCityName();
	char* getDepStateName();
	char* getDestCityName();
	char* getDestStateName();
	double getCurrentAltitude();
	double getCurrentLatitude();
	double getCurrentLongitude();
	double getCruiseAltitude();
	double getRateOfClimb();
	double getCurrentSpeed();
	double getTripTime();
	double getTotalDistance();
	double getDistanceFromStart();
	double getDistanceToDestination();
	bool getCompleteFlag();
	bool getOngoingFlag();
	void updateLatitude(); // Update an ongoing flight's latitude (happens every simulation second the plane is flying)
	void updateLongitude(); // Update an ongoing flight's longitude (happens every simulation second the plane is flying)
	void updateDistanceFromCities(); // Update an ongoing flight's distance (in miles) from the departure city and distance to the destination city
	void updateAltitude(); // Update an ongoing flight's altitude (happens every simulation second the plane is flying)
	void calculateAltitudeChangeTimes(); // Calculates when the flight will reach cruise altitude and when the flight will need to start descending

	enum Status{ COMPLETE, TAKEOFF, ONGOING, ARRIVED }; // Statuses for flights
};