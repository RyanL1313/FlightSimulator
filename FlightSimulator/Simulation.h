#pragma once

#include "SimDataCollector.h"

using namespace std;

class Simulation
{
private:

	SimDataCollector* sdc;

public:

	void initializeSimulation();
	void runSimulation();
	void updateFlights();

};