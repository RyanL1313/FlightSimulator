//==========================================================
// Aircraft.h
// Header file for the Aircraft class.
// 
// Defines an Aircraft object. Each
// Aircraft object has a pointer to its SharedAircraft 
// object along with its current latitude,
// longitude, and altitude.
//
// Author: Ryan Lynch
// Date: April 2021
//==========================================================

#pragma once

#include "SharedAircraft.h"

using namespace std;

class Aircraft
{
private:

	SharedAircraft* m_sa; // Pointer to the SharedAircraft object for this aircraft
	double m_dCurLatitude; // The current latitude of the plane
	double m_dCurLongitude; // The current longitude of the plane
	double m_dCurAltitude; // The current altitude of the plane

public:

	Aircraft(); // Constructor
	~Aircraft(); // Destructor
	
	SharedAircraft* getSharedAircraft(); // Returns a pointer to the SharedAircraft object for this aircraft
	double getCurLatitude(); // Getter for the current latitude
	double getCurLongitude(); // Getter for the current longitude
	double getCurAltitude(); // Getter for the current altitude
	void setSharedAircraft(SharedAircraft* sa); // Setter for the SharedAircraft object for this aircraft
	void setCurLatitude(double lat); // Setter for the current latitude
	void setCurLongitude(double lon); // Setter for the current longitude
	void setCurAltitude(double alt); // Setter for the current altitude
};