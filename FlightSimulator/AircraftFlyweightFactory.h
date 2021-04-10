#include "SharedAircraft.h"
#include <vector>
#include <string.h>

#pragma warning(disable : 4996)

using namespace std;

class AircraftFlyweightFactory
{
private:
	vector<SharedAircraft*> m_AllSharedAircrafts; // Vector of pointers to all distinct SharedAircraft objects

	AircraftFlyweightFactory(); // Private constructor for Singleton purposes
public:
	~AircraftFlyweightFactory(); // Destructor
	static AircraftFlyweightFactory* getInstance(); // Get the single instance of this class
	bool addSharedAircraft(SharedAircraft* sharedAC); // Adds a new SharedAircraft object to m_iAllSharedAircrafts
	SharedAircraft* getSharedAircraft(char* make); // Gets the SharedAircraft object corresponding to the specified make.
};