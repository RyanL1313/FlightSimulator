#include "AircraftFactory.h"

AircraftFactory::~AircraftFactory()
{
	delete m_aff;
}

void AircraftFactory::createSharedAircraft(FlightDataParser*& fdp)
{

}