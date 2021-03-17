//========================================================
// SimDataCollector.cpp
// Implementation file for the SimDataCollector class.
//
// Author: Ryan Lynch
// Date: March 2021
//========================================================

#pragma warning(disable : 4018)

#include "SimDataCollector.h"

using namespace std;

//------------------------------------------
// Default constructor
//------------------------------------------
SimDataCollector::SimDataCollector()
{

}

//------------------------------------------
// Destructor
//------------------------------------------
SimDataCollector::~SimDataCollector()
{
	// Delete the parser/file pointers
	delete fdp;
	delete cdp;
	delete dataFileNamesGetter;

	for (int i = 0; i < m_iCityCount; i++)
	{
		delete m_vCities[i]; // Delete a city object pointer in m_vCities
	}

	for (int i = 0; i < m_iAircraftCount; i++)
	{
		delete m_vAircrafts[i]; // Delete an aircraft object pointer in m_vAircrafts
	}

	for (int i = 0; i < m_iFlightCount; i++)
	{
		delete m_vFlights[i]; // Delete a flight object pointer in m_vFlights
	}

	delete[] m_pdCityDistances; // Delete the dynamic array of city distances

	for (int i = 0; i < m_iCityCount; i++)
	{
		delete[] m_psCitySymbols[i]; // Free memory allocated for each individual city symbol
	}
}

//---------------------------------------------------
// Return how many instances of this class there are.
//---------------------------------------------------
int SimDataCollector::getInstanceNumber()
{
	return this->m_iInstanceNumber;
}

//-----------------------------------------------
// Returns the only instance of SimDataCollector
// that ever gets created.
//-----------------------------------------------
SimDataCollector* SimDataCollector::getInstance()
{
	static SimDataCollector* theInstance = NULL;
	static int counter = 1;

	if (theInstance == NULL) // First time creating an instance of this class
	{
		theInstance = new SimDataCollector();
		theInstance->m_iInstanceNumber = counter;
		counter++;
	}

	return theInstance;
}

//-------------------------------------------
// Initialize all city, flight, and aircraft
// data needed by the simulation.
//-------------------------------------------
void SimDataCollector::initializeData()
{
	cdp = cdp->getInstance(); // Set pointer to the CityDataParser object
	fdp = fdp->getInstance(); // Set pointer to the FlightDataParser object
	setDataFileNames(); // Set the char arrays containing the XML data file names

	// Initialize parser data
	cdp->InitCityData(m_sCityDataFileName);
	fdp->InitFlightData(m_sFlightDataFileName);

	setSimSpeedMultiplier(); // Get the simulation speed entered by the user
	setSimStartTime(); // Set the simulation's start hour and minute

	// Set the counts of all object types
	m_iCityCount = cdp->getCityCount();
	m_iAircraftCount = fdp->getAircraftCount();
	m_iFlightCount = fdp->getFlightCount();

	setAllCityData(); // Populates m_vCities with City objects
	setAllAircraftData(); // Populates m_vAircrafts with Aircraft objects
	setAllFlightData(); // Populates m_vFlights with Flight objects
	setAllCityDistances(); // Populates m_pdCityDistances with all of the city distances
	setAllCitySymbols(); // Populates m_psCitySymbols with all of the city symbols
}

//-------------------------------------------------------
// Sets the XML data file names from FlightSim01.txt.
//-------------------------------------------------------
void SimDataCollector::setDataFileNames()
{
	// Get user input for the file containing the data file names
	cout << "Enter the name of the text file containing the city and flight data file names:" << endl;
	cin >> m_sDataFiles;

	dataFileNamesGetter = new fstream();
	dataFileNamesGetter->open(m_sDataFiles, fstream::in);

	if (!dataFileNamesGetter->is_open())
	{
		cout << "The data file containing the names of the XML data files could not be opened. Exiting program..." << endl;
		exit(0);
	}

	// Read each file name from the file
	dataFileNamesGetter->getline(m_sCityDataFileName, 64);
	dataFileNamesGetter->getline(m_sFlightDataFileName, 64);
}

//-------------------------------------------------------
// Gets the simulation speed multiplier from 
// the user.
//-------------------------------------------------------
void SimDataCollector::setSimSpeedMultiplier()
{
	cout << "Enter the speed you want the simulation to run at (either 1 for 1X, 2 for 2X, or 3 for 3X):" << endl;
	cin >> m_iSimSpeedMultiplier;

	// Loop until a valid integer is entered
	while (cin.fail() || (m_iSimSpeedMultiplier < 1 || m_iSimSpeedMultiplier > 3)) // Invalid option
	{
		// Clear error state and flush out input buffer in case of input error
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Error. You must enter either 1, 2, or 3. Try entering the speed again:" << endl;
		cin >> m_iSimSpeedMultiplier;
	}
}

//-------------------------------------------------------
// Sets the starting hour and minute of the simulation.
//-------------------------------------------------------
void SimDataCollector::setSimStartTime()
{
	fdp->getStartTime(&m_iSimStartHour, &m_iSimStartMinute);
}

//-------------------------------------------------------
// Creates all City objects required for the simulation.
//-------------------------------------------------------
void SimDataCollector::setAllCityData()
{
	// Data to be populated for each City object
	char name[32];
	char state[32];
	char symbol[4];
	double latitude;
	double longitude;
	City* tempCity = nullptr;

	for (int i = 0; i < m_iCityCount; i++)
	{
		tempCity = new City();

		cdp->getCityData(name, state, symbol, &latitude, &longitude); // Get a single city's data

		// Set all of the city's data
		tempCity->setName(name);
		tempCity->setState(state);
		tempCity->setSymbol(symbol);
		tempCity->setLatitude(latitude);
		tempCity->setLongitude(longitude);

		m_vCities.push_back(tempCity); // Add the City pointer to the list of cities
	}

	// Free the memory
	tempCity = new City();
	delete tempCity;
	tempCity = nullptr;
}

//-------------------------------------------------------
// Creates all Aircraft objects required for the simulation.
//-------------------------------------------------------
void SimDataCollector::setAllAircraftData()
{
	// Data to be populated for each Aircraft object
	char make[32];
	char description[32];
	double rateOfClimb;
	double wingspan;
	double fuselageLength;
	double cruiseSpeed;
	double cruiseAltitude;
	Aircraft* tempAircraft;

	for (int i = 0; i < m_iAircraftCount; i++)
	{
		tempAircraft = new Aircraft();

		fdp->getAircraftData(make, description, &rateOfClimb, &wingspan, &fuselageLength, &cruiseSpeed, &cruiseAltitude);

		// Set all of the aircraft data
		tempAircraft->setMake(make);
		tempAircraft->setDescription(description);
		tempAircraft->setRateOfClimb(rateOfClimb);
		tempAircraft->setWingspan(wingspan);
		tempAircraft->setFuselageLength(fuselageLength);
		tempAircraft->setCruiseSpeed(cruiseSpeed);
		tempAircraft->setCruiseAltitude(cruiseAltitude);

		m_vAircrafts.push_back(tempAircraft);
	}

	// Free the memory
	tempAircraft = new Aircraft();
	delete tempAircraft;
	tempAircraft = nullptr;
}

//--------------------------------------------------------
// Creates all Flight objects required for the simulation.
//--------------------------------------------------------
void SimDataCollector::setAllFlightData()
{
	char airline[32];
	char planeType[32];
	int flightNumber;
	char departureLocation[4];
	int departureHour;
	int departureMinute;
	char destination[4];
	Flight* tempFlight;

	for (int i = 0; i < m_iFlightCount; i++)
	{
		tempFlight = new Flight();

		fdp->getFlightData(airline, planeType, &flightNumber, departureLocation, &departureHour, &departureMinute, destination);

		// Set all of the flight data
		tempFlight->setAirline(airline);
		tempFlight->setPlaneType(planeType);
		tempFlight->setFlightNumber(flightNumber);
		tempFlight->setDepartureLocation(departureLocation);
		tempFlight->setDepartureHour(departureHour);
		tempFlight->setDepartureMinute(departureMinute);
		tempFlight->setDepartureTime();
		tempFlight->setDestination(destination);

		m_vFlights.push_back(tempFlight);
	}

	// Free the memory
	tempFlight = new Flight();
	delete tempFlight;
	tempFlight = nullptr;
}

//-------------------------------------------------------
// Sets the distances between each set of cities.
//-------------------------------------------------------
void SimDataCollector::setAllCityDistances()
{
	m_pdCityDistances = new double[m_iCityCount * m_iCityCount];
	cdp->getDistTable(&m_pdCityDistances);
}

//-------------------------------------------------------
// Sets all of the city airport symbols.
//-------------------------------------------------------
void SimDataCollector::setAllCitySymbols()
{
	cdp->getCitySymbolsArray(&m_psCitySymbols);
}

//-------------------------------------------------------
// Gets the aircraft associated with a flight's plane
// type.
//-------------------------------------------------------
Aircraft* SimDataCollector::getFlightAircraft(char* planeType)
{
	for (int i = 0; i < m_iAircraftCount; i++)
	{
		if (strcmp(planeType, m_vAircrafts[i]->getMake()) == 0) // Found the requested aircraft
			return m_vAircrafts[i];
	}

	return nullptr;
}

//-------------------------------------------------------
// Gets the city associated with a flight (either
// departure city or destination).
//-------------------------------------------------------
City* SimDataCollector::getFlightCity(char* citySymbol)
{
	for (int i = 0; i < m_iCityCount; i++)
	{
		if (strcmp(citySymbol, m_vCities[i]->getSymbol()) == 0) // Found the requested city
			return m_vCities[i];
	}

	return nullptr;
}

//-------------------------------------------------------
// Calculates how many hours a flight will take and.
// returns this value as a double.
//
// Args: 
// depCitySymbol - The departure city symbol
// destCitySymbol - The destination city symbol
// cruiseSpeed - The cruise speed of the aircraft
// on the flight
//-------------------------------------------------------
double SimDataCollector::calculateTripTime(double distBetweenCities, double cruiseSpeed)
{
	return distBetweenCities / cruiseSpeed; // Returns the trip time in hours
}

double SimDataCollector::calculateTotalDistance(char* depCitySymbol, char* destCitySymbol)
{
	// Get the indices in m_psCitySymbols corresponding to the dep/dest city symbols
	int depCitySymbolIndex = getCitySymbolIndex(depCitySymbol);
	int destCitySymbolIndex = getCitySymbolIndex(destCitySymbol);

	// Get the distance between these cities using m_pdCityDistances
	double distBetweenCities = m_pdCityDistances[depCitySymbolIndex * m_iCityCount + destCitySymbolIndex];

	return distBetweenCities;
}

//-------------------------------------------------------
// Calculates the distance in miles a flight is from its
// departure city.
//
// Args: 
// elapsedTime - The flight's elapsed time in hours
// tripTime - The total time the trip will take in hours
// distBetweenCities - The total distance between 
// the departure and destination cities
//-------------------------------------------------------
double SimDataCollector::calculateDistFromDepCity(double elapsedTime, double tripTime, double distBetweenCities)
{
	return (elapsedTime / tripTime) * distBetweenCities;
}

//-------------------------------------------------------
// Calculates the distance in miles a flight is from its
// destination city.
//
// Args:
// distBetweenCities - Total distance between two cities
// distFromStart - Distance traveled from departure city
//-------------------------------------------------------
double SimDataCollector::calculateDistToDestination(double distBetweenCities, double distFromStart)
{
	return distBetweenCities - distFromStart;
}

//-------------------------------------------------------
// Returns the index of a city symbol in m_psCitySymbols.
//-------------------------------------------------------
int SimDataCollector::getCitySymbolIndex(char* citySymbol)
{
	// Loop through the array of city symbols until a match is found, then return that index
	for (int i = 0; i < m_iCityCount; i++)
	{
		if (strcmp(citySymbol, m_psCitySymbols[i]) == 0)
			return i;
	}

	return -1; // City not found (shouldn't happen)
}

//-------------------------------------------------------
// Gets the simulation starting hour.
//-------------------------------------------------------
int SimDataCollector::getStartHour()
{
	return m_iSimStartHour;
}

//-------------------------------------------------------
// Gets the simulation starting minute.
//-------------------------------------------------------
int SimDataCollector::getStartMinute()
{
	return m_iSimStartMinute;
}

//-------------------------------------------------------
// Gets the simulation speed multiplier.
//-------------------------------------------------------
int SimDataCollector::getSimSpeedMultiplier()
{
	return m_iSimSpeedMultiplier;
}

//-------------------------------------------------------
// Gets the number of flights.
//-------------------------------------------------------
int SimDataCollector::getFlightCount()
{
	return m_iFlightCount;
}

//-------------------------------------------------------------------
// Updates a flight's data.
//
// Returns an enumerated value to indicate the status of the flight
// after the updates: either COMPLETE, TAKEOFF, ONGOING, or ARRIVED.
//-------------------------------------------------------------------
int SimDataCollector::updateFlight(int index, int currentHour, int currentMinute, double currentTime)
{
	int flightStatus = -1; // The status of the flight returned from this function
	Flight* theFlight = m_vFlights[index]; // A pointer to the flight located at the requested index
	Aircraft* thePlane = getFlightAircraft(theFlight->getPlaneType()); // Get a pointer to the Aircraft object for this flight
	City* depCity = getFlightCity(theFlight->getDepartureLocation()); // Get a pointer to the City object corresponding to the departure city
	City* destCity = getFlightCity(theFlight->getDestination()); // Get a pointer to the City object corresponding to the destination city

	theFlight->setCurrentHour(currentHour); // Set the flight's current hour
	theFlight->setCurrentMinute(currentMinute); // Set the flight's current minute
	theFlight->setCurrentTime(currentTime); // Set the flight's current time 

	if (theFlight->getCompleteFlag() == false) // Only need to update flights that haven't landed
	{
		if (theFlight->getOngoingFlag() == false) // Looking at flights that haven't taken off yet
		{
			if (currentTime >= theFlight->getDepartureTime()) // Time for this flight to take off
			{
				theFlight->setOngoingFlag(true); // Flag the flight as ongoing

				theFlight->setCurrentAltitude(0); // Initialize the current altitude to 0
				theFlight->setCurrentSpeed(thePlane->getCruiseSpeed()); // Set the current speed to the cruise speed of this aircraft type
				theFlight->setRateOfClimb(thePlane->getRateOfClimb()); // Se the flight's rate of climb to the aircraft's rate of climb
				theFlight->setCruiseAltitude(thePlane->getCruiseAltitude()); // Set the flight's cruise altitude to the aircraft's cruise altitude

				theFlight->setCurrentLongitude(depCity->getLongitude()); // Initialize the longitude to the departure city's longitude
				theFlight->setCurrentLatitude(depCity->getLatitude()); // Initialize the latitude to the departure city's latitude
				theFlight->setDepCityLongitude(depCity->getLongitude()); // Set departure city longitude
				theFlight->setDepCityLatitude(depCity->getLatitude()); // Set departure city latitude
				theFlight->setDestCityLongitude(destCity->getLongitude()); // Set destination city longitude
				theFlight->setDestCityLatitude(destCity->getLatitude()); // Set destination city latitude

				theFlight->setDepCityName(depCity->getName()); // Set full departure city name
				theFlight->setDepStateName(depCity->getState()); // Set full departure state name
				theFlight->setDestCityName(destCity->getName()); // Set full destination city name
				theFlight->setDestStateName(destCity->getState()); // Set full departure city name

				theFlight->setTotalDistance(calculateTotalDistance(depCity->getSymbol(), destCity->getSymbol())); // Set the distance between the departure city and destination
				theFlight->setTripTime(calculateTripTime(theFlight->getTotalDistance(), thePlane->getCruiseSpeed())); // Set the flight duration in hours
				theFlight->setDistanceFromStart(0); // Set the flight's distance from its departure city (initially 0)
				theFlight->setDistanceToDestination(theFlight->getTotalDistance()); // Initialize the distance to the destination city to the total distance between the cities

				theFlight->setEstArrivalTime(theFlight->getDepartureTime() + theFlight->getTripTime()); // The arrival time will be the current time plus the time of the trip (in hours)
				theFlight->setEstArrivalHour(); // Set the estimated arrival hour
				theFlight->setEstArrivalMinute(); // Set the estimated arrival minute

				theFlight->calculateAltitudeChangeTimes(); // Calculate when the flight will reach the cruise altitude (might not happen) and when it needs to descend

				flightStatus = Flight::TAKEOFF;

			}
		}
		else // This is an ongoing/arriving flight. Update its data
		{
			if (currentTime >= theFlight->getEstArrivalTime()) // Time for this flight to land
			{
				theFlight->setOngoingFlag(false); // No longer ongoing
				theFlight->setCompleteFlag(true); // Set flight complete flag

				theFlight->setCurrentAltitude(0); // Set altitude to 0
				theFlight->setCurrentSpeed(0); // Set current speed to 0

				theFlight->setCurrentLongitude(destCity->getLongitude()); // Initialize the latitude to the destination city's longitude
				theFlight->setCurrentLatitude(destCity->getLatitude()); // Initialize the latitude to the destination city's latitude

				theFlight->setDistanceFromStart(theFlight->getTotalDistance()); // Distance from start is the total distance traveled in the flight
				theFlight->setDistanceToDestination(0); // Arrived at the destination

				flightStatus = Flight::ARRIVED;
			}
			else // This flight is still ongoing
			{
				// Calculate current latitude
				theFlight->updateLatitude();
				// Calculate current longitude
				theFlight->updateLongitude();
				// Calculate distances
				theFlight->updateDistanceFromCities();
				// Calculate current altitude
				theFlight->updateAltitude();

				flightStatus = Flight::ONGOING;
			}
		}
	}

	if (flightStatus == -1) // The first if condition failed, meaning the flight is complete
		flightStatus = Flight::COMPLETE;

	// Free the memory
	theFlight = new Flight();
	depCity = new City();
	destCity = new City();
	thePlane = new Aircraft();
	delete theFlight, depCity, destCity, thePlane;
	theFlight, depCity, destCity, thePlane = nullptr;

	return flightStatus; // Return the status of the flight to determine if any reports need to be generated
}

//--------------------------------------------------------
// Calculates an hour given a decimal time
// double (the hour is the left side of the decimal).
//
// Returns the hour.
//--------------------------------------------------------
int SimDataCollector::calculateTimeHour(double currentTime)
{
	int simHour = (int)currentTime; // The left side of the decimal is the current sim hour

	return simHour;
}

//--------------------------------------------------------
// Calculates a minute given a decimal time
// (the minute is the right side of the decimal * 60)
//
// Returns the minute.
//--------------------------------------------------------
int SimDataCollector::calculateTimeMinute(double time)
{
	int simHour = (int)time; // The left side of the decimal is the current sim hour
	double dSimMinute = time - simHour; // Now only the decimal is left, which is the minutes in fraction form
	dSimMinute = dSimMinute * 60; // Convert the minutes fraction to minutes

	return (int)dSimMinute; // Return the minute integer
}

//-------------------------------------------------------
// Displays information about all ongoing flights.
// Gets called every 5 seconds of real time.
//-------------------------------------------------------
void SimDataCollector::displayScheduledReport(int currentHour, int currentMinute)
{
	cout << "=======================================================================" << endl;
	cout << "|    Flight Simulation - Status report on all flights enroute.        |" << endl;
	cout << "=======================================================================" << endl;
	cout << "Current clock time: " << setfill('0') << setw(2) << currentHour << ":" << setw(2) << currentMinute << endl << endl;

	for (int i = 0; i < m_iFlightCount; i++)
	{
		if (m_vFlights[i]->getOngoingFlag() == true) // Only print out the status of ongoing flights
		{
			cout << m_vFlights[i]->getAirline() << " Flight " << m_vFlights[i]->getFlightNumber() << " - " << m_vFlights[i]->getPlaneType() << endl;
			cout << "\tDeparts: " << m_vFlights[i]->getDepartureLocation() << " (" << m_vFlights[i]->getDepCityLatitude() << ", " << m_vFlights[i]->getDepCityLongitude() << ") ";
			cout << "at " << setfill('0') << setw(2) << m_vFlights[i]->getDepartureHour() << ":" << setw(2) << m_vFlights[i]->getDepartureMinute() << endl;
			cout << "\tArrives: " << m_vFlights[i]->getDestination() << " (" << m_vFlights[i]->getDestCityLatitude() << ", " << m_vFlights[i]->getDestCityLongitude() << ") ";
			cout << "at " << setfill('0') << setw(2) << m_vFlights[i]->getEstArrivalHour() << ":" << setw(2) << m_vFlights[i]->getEstArrivalMinute() << endl;
			cout << "\tCurrent location: (" << m_vFlights[i]->getCurrentLatitude() << ", " << m_vFlights[i]->getCurrentLongitude() << ")" << endl;
			cout << "\t\t" << m_vFlights[i]->getDistanceFromStart() << " miles from " << m_vFlights[i]->getDepartureLocation() << ", " << m_vFlights[i]->getDistanceToDestination();
			cout << " miles to " << m_vFlights[i]->getDestination() << endl;
			cout << "\tCurrent Speed: " << m_vFlights[i]->getCurrentSpeed() << " MPH" << endl;
			cout << "\tCurrent altitude: " << m_vFlights[i]->getCurrentAltitude() << " feet" << endl;
		}
	}

	cout << "=======================================================================" << endl << endl << endl << endl << endl;
}

//---------------------------------------------------------
// Displays information about a flight that is taking off.
//---------------------------------------------------------
void SimDataCollector::displayTakeoffReport(int index, int currentHour, int currentMinute)
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Now departing: " << m_vFlights[index]->getAirline() << " flight " << m_vFlights[index]->getFlightNumber() << ", " << m_vFlights[index]->getPlaneType() << endl;
	cout << "\tFrom " << m_vFlights[index]->getDepCityName() << ", " << m_vFlights[index]->getDepStateName() << endl;
	cout << "\t\tenroute to " << m_vFlights[index]->getDestCityName() << ", " << m_vFlights[index]->getDestStateName() << endl;
	cout << "Estimated Time of Arrival: " << setfill('0') << setw(2) << m_vFlights[index]->getEstArrivalHour() << ":" << setw(2) << m_vFlights[index]->getEstArrivalMinute() << endl;
	cout << "Current clock time: " << setfill('0') << setw(2) << currentHour << ":" << setw(2) << currentMinute << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl << endl << endl << endl;
}

//---------------------------------------------------------
// Displays information about a flight that is landing.
//---------------------------------------------------------
void SimDataCollector::displayLandingReport(int index, int currentHour, int currentMinute)
{
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
	cout << "Now arriving: " << m_vFlights[index]->getAirline() << " flight " << m_vFlights[index]->getFlightNumber() << ", " << m_vFlights[index]->getPlaneType() << endl;
	cout << "\t\tAt " << m_vFlights[index]->getDestCityName() << ", " << m_vFlights[index]->getDestStateName() << endl;
	cout << "\t\tFrom " << m_vFlights[index]->getDepCityName() << ", " << m_vFlights[index]->getDepStateName() << endl;
	cout << "Current clock time: " << setfill('0') << setw(2) << currentHour << ":" << setw(2) << currentMinute << endl;
	cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl << endl << endl << endl << endl;
}