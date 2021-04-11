//===================================================
// main.cpp
// Main class for the program.
//
// Programming Assignment 2
//
// This program simulates the takeoff and landing
// of flights. Data about flights and the cities
// and aircrafts involved in these flights are read
// from the XML files CityData02.xml and 
// AirlineFlightData02.xml. The names of these XML
// files are read in from the FlightSim02.txt file.
// Every second of real time is one minute of
// simulation time. The simulation can be run in 
// 1X, 2X, and 3X time which changes how many
// simulation minutes pass compared to real time.
// Reports are generated about flights every 5
// seconds of real time and also when a flight
// lands or takes off.
//
// For this second iteration of the program, 
// SharedAircraft objects are created using the 
// Abstract Factory design pattern. Three different
// factories exist to create the three different
// types of planes (business, passenger, and
// single engine). 
//
// When these factories create a 
// SharedAircraft object, they add them to the
// singleton instance of the AircraftFlyweightFactory
// class while also making sure that the shared
// aircraft being created is different from all others
// in the flyweight factory. The SharedAircraft objects
// are determined to be different if their makes are
// different.
//
// Aircraft objects are created and stored in Flight 
// objects whenever Flights are created. These Aircraft
// objects store a pointer to a SharedAircraft object
// which is retrieved from the AircraftFlyweightFactory
// class. The SharedAircraft objects contain data
// about a certain make of plane that will not change.
// Since some flights will use the same make of plane to 
// perform the flight, this prevents duplicate Aircraft
// objects from being created. This methodology follows 
// the Flyweight design pattern.
//
// The data parsers are written in CityDataParser.cpp
// and FlightDataParser.cpp. These files were
// provided by Dr. Hauenstein.
//
// Author: Ryan Lynch
// Date: April 2021
//===================================================

#include <iostream>
#include "Simulation.h"

using namespace std;

void printIntroduction(); // Prints the introductory message to the program.

//-----------------------------------
// Main function
//-----------------------------------
int main()
{
	printIntroduction();

	Simulation* flightSim = Simulation::getInstance();
	flightSim->initializeSimulation();
	flightSim->runSimulation();

	return 0;
}

//-------------------------------------------------
// Prints the introductory message to the program.
//-------------------------------------------------
void printIntroduction()
{
	cout << "=======================================================================" << endl;
	cout << "|        Flight Simulator - CS 307-01 Programming Assignment 2         |" << endl;
	cout << "|                         By: Ryan Lynch                               |" << endl;
	cout << "=======================================================================" << endl << endl;
}