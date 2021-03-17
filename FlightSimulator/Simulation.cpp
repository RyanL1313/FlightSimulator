//========================================================
// Simulation.cpp
// Implementation file for the Simulation class.
//
// Author: Ryan Lynch
// Date: March 2021
//========================================================

#include "Simulation.h"
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;
using namespace std::this_thread;
using namespace std::chrono_literals;

//-------------------------------------------------------
// Default constructor
//-------------------------------------------------------
Simulation::Simulation()
{

}

//-------------------------------------------------------
// Destructor
//-------------------------------------------------------
Simulation::~Simulation()
{
	delete sdc; // Free memory used by the SimDataCollector object
}

//---------------------------------------------------
// Return how many instances of this class there are.
//---------------------------------------------------
int Simulation::getInstanceNumber()
{
	return this->m_iInstanceNumber;
}

//---------------------------------------------------
// Returns the only instance of Simulation
// that ever gets created.
//---------------------------------------------------
Simulation* Simulation::getInstance()
{
	static Simulation* theInstance = NULL;
	static int counter = 1;

	if (theInstance == NULL) // First time creating an instance of this class
	{
		theInstance = new Simulation();
		theInstance->m_iInstanceNumber = counter;
		counter++;
	}

	return theInstance;
}

//-------------------------------------------------------
// Initializes necessary data fields in this class.
//-------------------------------------------------------
void Simulation::initializeSimulation()
{
	// Collect all parsed data
	sdc = SimDataCollector::getInstance();
	sdc->initializeData();

	m_dSimStartTime = (double)sdc->getStartHour() + ((double)sdc->getStartMinute() / 60); // Set the double form of the simulation start time (in hours)
	m_dCurrentSimTime = m_dSimStartTime; // This value will start at the simulation start time (in hours) and change throughout the simulation
	m_dNextScheduledReportTime = m_dCurrentSimTime + (5.0 / 60) * sdc->getSimSpeedMultiplier(); // Every 5 * simSpeedMultiplier simulation minutes, a scheduled report for the ongoing flights should print
	m_dUpdateTimeAmount = 1.0 / sdc->getSimSpeedMultiplier() * 1000; // This value indicates the duration in milliseconds that must pass to update the simulation flight data
	m_iTotalFlights = sdc->getFlightCount(); // The number of flights in the flights data file
	m_iFlightsRemaining = m_iTotalFlights; // The number of flights remaining starts out at the total number of flights
}

//--------------------------------------------------------
// Starts the simulation and continues until no flights
// remain.
//--------------------------------------------------------
void Simulation::runSimulation()
{
	cout << "\n*** Starting simulation at " << setfill('0') << setw(2) << sdc->getStartHour() << ":" << setw(2) << sdc->getStartMinute() << " ***" << endl << endl << endl;

	// Loop until all flights are completed
	while (m_iFlightsRemaining > 0)
	{
		this_thread::sleep_for(chrono::milliseconds((int)m_dUpdateTimeAmount)); // Sleeps for 1 second at 1X speed, 0.5 seconds at 2X, and (1/3) seconds at 3X
		m_dCurrentSimTime += 1.0 / 60; // 1 minute of simulation time (1 / 60) hours passes at each update
		m_iCurrentSimHour = SimDataCollector::calculateTimeHour(m_dCurrentSimTime);
		m_iCurrentSimMinute = SimDataCollector::calculateTimeMinute(m_dCurrentSimTime);

		updateFlights(); // Update the data for all flights

		// Time to show the status of all ongoing flights (happens every 5 seconds)
		if (m_dCurrentSimTime >= m_dNextScheduledReportTime)
		{
			generateScheduledReport();
			m_dNextScheduledReportTime += (5.0 / 60) * sdc->getSimSpeedMultiplier(); // Adds 5 * simSpeedMultiplier minutes of simulation time to indicate when the next scheduled report will occur
		}
	}

	cout << "\nAll flights landed! Ending simulation..." << endl << endl;
	this_thread::sleep_for(chrono::milliseconds(3000)); // Sleep for three extra seconds so console doesn't disappear right away
}

//--------------------------------------------------------
// Updates flight data (such as longitude/latitude, flags)
// periodically throughout the simulation.
//--------------------------------------------------------
void Simulation::updateFlights()
{
	int returnUpdate; // The flight status enumerated value that gets returned from sdc->updateFlight()

	// Loop through all flights and call sdc's utility to update the data for each flight
	for (int i = 0; i < m_iTotalFlights; i++)
	{
		returnUpdate = sdc->updateFlight(i, m_iCurrentSimHour, m_iCurrentSimMinute, m_dCurrentSimTime); // Update the flight at this index in the vector

		if (returnUpdate == Flight::TAKEOFF)
			generateTakeoffReport(i); // The update indicates the plane has taken off; report this
		else if (returnUpdate == Flight::ARRIVED)
		{
			generateLandingReport(i); // The update indicates the plane has landed; report this
			m_iFlightsRemaining--; // Decrement the number of flights remaining
		}
	}
}

//--------------------------------------------------------
// Outputs data about ongoing flights.
//--------------------------------------------------------
void Simulation::generateScheduledReport()
{
	sdc->displayScheduledReport(m_iCurrentSimHour, m_iCurrentSimMinute);
}

//--------------------------------------------------------
// Outputs data about a flight that has just taken off.
//--------------------------------------------------------
void Simulation::generateTakeoffReport(int index)
{
	sdc->displayTakeoffReport(index, m_iCurrentSimHour, m_iCurrentSimMinute);
}

//--------------------------------------------------------
// Outputs data about a flight that has just landed.
//--------------------------------------------------------
void Simulation::generateLandingReport(int index)
{
	sdc->displayLandingReport(index, m_iCurrentSimHour, m_iCurrentSimMinute);
}