//==========================================================
// Simulation.h
// Header file for the Simulation class.
// 
// Author: Ryan Lynch
// Date: March 2021
//==========================================================

#pragma once

#include "SimDataCollector.h"
#include "Flight.h"

using namespace std;

class Simulation
{
private:

	int m_iInstanceNumber; // Number of instances of this class. Used for singleton design purposes (cannot exceed 1)
	SimDataCollector* sdc; // A pointer to the SimDataCollector object which will hold all of the data used in the simulation
	double m_dSimStartTime; // The start time of the simulation in the form of a double (value before decimal place is the hour, value after is (minute / 60)
	double m_dCurrentSimTime; // Current time of the simulation. Gets updated throughout the simulation (either every second, half-second, or third of a second)
	int m_iCurrentSimHour; // Current hour of the simulation
	int m_iCurrentSimMinute; // Current minute of the simulation
	double m_dNextScheduledReportTime; // Contains the time of the next scheduled report, which will be every 5 seconds
	double m_dUpdateTimeAmount; // Indicates how often the simulation time will need to be updated. Based on the simulation speed multiplier
	int m_iTotalFlights; // Number of flights in the data file
	int m_iFlightsRemaining; // Number of flights left to be completed

	Simulation(); // Default constructor (private for singleton design purposes)

public:

	~Simulation(); // Destructor
	int getInstanceNumber(); // Return how many instances of this class there are
	static Simulation* getInstance(); // Return the instance of a Simulation object. Should always return the same object
	void initializeSimulation(); // Initializes necessary data fields in this class
	void runSimulation(); // Starts the simulation and continues until no flights remain
	void updateFlights(); // Updates flight data (such as longitude/latitude, flags) periodically throughout the simulation
	void generateScheduledReport(); // Outputs data about ongoing flights
	void generateTakeoffReport(int index); // Outputs data about a flight that has just taken off
	void generateLandingReport(int index); // Outputs data about a flight that has just landed
};