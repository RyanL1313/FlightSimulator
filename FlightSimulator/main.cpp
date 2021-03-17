//===================================================
// main.cpp
// Main class for the program.
//
// This program simulates the takeoff and landing
// of flights. Data about flights and the cities
// and aircraft involved in these flights are read
// from the XML files CityData01.xml and 
// AirlineFlightData01.xml. The names of these XML
// files are read in from the FlightSim01.txt file.
// Every second of real time is one minute of
// simulation time. The simulation can be run in 
// 1X, 2X, and 3X time which changes how many
// simulation minutes pass compared to real time.
// Reports are generated about flights every 5
// seconds of real time and also when a flight
// lands or takes off.
//
// The data parsers are written in CityDataParser.cpp
// and FlightDataParser.cpp. These files were
// provided by Dr. Hauenstein.
//
// Author: Ryan Lynch
// Date: March 2021
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
	cout << "|        Flight Simulator - CS 307-01 Programming Assignment 1         |" << endl;
	cout << "|                         By: Ryan Lynch                               |" << endl;
	cout << "=======================================================================" << endl << endl;
}