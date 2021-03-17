//========================================================
// SimDataCollector.h
// Interface file for the SimDataCollector class.
//
// Author: Ryan Lynch
// Date: March 2021
//========================================================

#pragma once

#include "FlightDataParser.h"
#include "CityDataParser.h"
#include "Flight.h"
#include "City.h"
#include "Aircraft.h"
#include <vector>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class SimDataCollector
{
private:

	int m_iInstanceNumber; // Number of instances of this class. Used for singleton design purposes (cannot exceed 1)
	int m_iSimSpeedMultiplier; // Simulation speed multiplier (1X, 2X, or 3X)
	int m_iSimStartHour; // Start hour of the simulation
	int m_iSimStartMinute; // Start minute of the simulation
	FlightDataParser* fdp; // Pointer to a FlightDataParser object
	CityDataParser* cdp; // Pointer to a CityDataParser object
	char m_sDataFiles[32]; // Holds the name of the file containing the names of the XML data files
	char m_sCityDataFileName[32]; // Holds the name of the city data file
	char m_sFlightDataFileName[32]; // Holds the name of the flight data file
	fstream* dataFileNamesGetter; // Will point to the file containing the names of the XML data files
	vector<Aircraft*> m_vAircrafts; // Vector of pointers to all Aircraft objects
	vector<Flight*> m_vFlights; // Vector of pointers to all Flight objects
	vector<City*> m_vCities; // Vector of pointers to all City objects
	double* m_pdCityDistances; // Pointer to an array of doubles containing distances from all cities to each other
	char** m_psCitySymbols; // Pointer to an array of character pointers containing city symbols
	int m_iCityCount; // The number of cities in the city data file
	int m_iAircraftCount; // The number of aircraft in the flight data file
	int m_iFlightCount; // The number of flights in the flight data file

	SimDataCollector(); // Default constructor (private for singleton design purposes)
	void setDataFileNames(); // Sets the XML data file names
	void setSimSpeedMultiplier(); // Sets the simulation speed multiplier (1X, 2X, or 3X)
	void setSimStartTime(); // Sets the starting hour and minute of the simulation
	void setAllCityData(); // Sets the data about all of the cities
	void setAllAircraftData(); // Sets the data about all of the aircrafts
	void setAllFlightData(); // Sets the data about all of the flights
	void setAllCityDistances(); // Sets the distances between each city
	void setAllCitySymbols(); // Sets all city airport symbols
	Aircraft* getFlightAircraft(char* planeType); // Returns a pointer to the Aircraft object associated with a flight's plane type
	City* getFlightCity(char* citySymbol); // Returns a pointer to a city object (either departure city or destination) associated with a certain city symbol
	double calculateTripTime(double totalDistance, double cruiseSpeed); // Calculates how long a flight will take (in hours)
	double calculateTotalDistance(char* depCitySymbol, char* destCitySymbol); // Calculates the total distance between two cities using m_pdCityDistances
	double calculateDistFromDepCity(double elapsedTime, double tripTime, double distBetweenCities); // Calculates the distance (in miles) from the departure city
	double calculateDistToDestination(double distBetweenCities, double distFromStart); // Calculates the distance (in miles) to the destination city
	int getCitySymbolIndex(char* citySymbol); // Returns the index of a city symbol in m_psCitySymbols

public:

	~SimDataCollector(); // Destructor
	int getInstanceNumber(); // Return how many instances of this class there are
	static SimDataCollector* getInstance(); // Return the instance of a SimDataCollector object. Should always return the same object
	void initializeData(); // Initialize all data needed for the simulation. Uses the city and flight data parsers
	int getStartHour(); // Getter for m_iSimStartHour
	int getStartMinute(); // Getter for m_iSimStartMinute
	int getSimSpeedMultiplier(); // Getter for m_iSimSpeedMultiplier
	int getFlightCount(); // Getter for the number of flights
	int updateFlight(int index, int currentHour, int currentMinute, double currentTime); // Updates a flight's data in m_vFlights
	static int calculateTimeHour(double currentTime); // Calculates the current hour given the total currentTime double (the hour is the left side of the decimal)
	static int calculateTimeMinute(double currentTime); // Calculates the current minute given the total currentTime double (the minute is the right side of the decimal * 60)
	void displayScheduledReport(int currentHour, int currentMinute); // Display information about all ongoing flights
	void displayTakeoffReport(int index, int currentHour, int currentMinute); // Display information about a flight that just took off
	void displayLandingReport(int index, int currentHour, int currentMinute); // Display information about a flight that just landed
};