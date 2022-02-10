#include <sstream>
#include "House.h"

using namespace std;

House::House()
{
	//stub
}

//return false if room has too low a height, too small an area or the house already is at max for that type of room
bool House::addRoom( const Room& theRoom )
{
	//stub
	return true;
}

int House::getNumBedrooms()
{
	//stub
	return 0;
}

int House::getNumBathrooms()
{
	//stub
	return 0;
}

int House::getNumKitchens()
{
	//stub
	return 0;
}

int House::getNumLivingrooms()
{
	//stub
	return 0;
}

int House::getTotalSquareFootage()
{
	//stub
	return 0;
}

int House::getTotalVolume()
{
	//stub
	return 0;
}

bool House::isValid()
{
	//stub
	return false;
}

string House::enumerateRooms()
{
	//stub
	string report = "These are the rooms in the house:\n";

	return report;
}

string House::getDescription()
{
	stringstream theStream;

	theStream	
		<< "House has:\n"
		<< getNumBedrooms() << " Bedrooms\n"
		<< getNumBathrooms() << " Bathrooms\n"
		<< getNumKitchens() << " Kitchens\n"
		<< getNumLivingrooms() << " Livingrooms\n\n"
		<< getTotalSquareFootage() << " Square feet total\n"
		<< getTotalVolume() << " Cubic feet total volume\n";

	if( isValid() )
	{
		theStream << "House is Valid!\n\n";
	}
	else
	{
		theStream << "House is not Valid!\n\n";
	}

	return theStream.str();
}