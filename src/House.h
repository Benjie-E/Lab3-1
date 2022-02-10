#pragma once

#include <string>
#include "Room.h"

//a house can never have more than these number of roooms of each type
const int MAX_BEDROOMS = 4;
const int MAX_KITCHENS = 1;
const int MAX_BATHROOMS = 2;
const int MAX_LIVINGROOMS = 5;

//a house with less than the minimum number of rooms of each type will always be worth $0
const int MIN_BEDROOMS = 1;
const int MIN_KITCHENS = 1;
const int MIN_BATHROOMS = 1;
const int MIN_LIVINGROOMS = 0;

//each room must be at least this high to be valid for adding to a house
const int MIN_HEIGHT = 7;

//each room must have at least this square footage for adding to a house
const int MIN_AREA = 25;

class House
{
public:
	//constructor
	House();
	//destructor
	~House(){};

	bool addRoom( const Room& theRoom );
	int getNumBedrooms();
	int getNumBathrooms();
	int getNumKitchens();
	int getNumLivingrooms();

	int getTotalSquareFootage();//sum of the area of all rooms
	int getTotalVolume();//sum of the volume of all rooms
	//can this house be occupied - must have minimum number of rooms by type
	bool isValid();
	string enumerateRooms();//create a string with the descriptions of all the rooms in the house

	string getDescription();
private:
	//add data here!!!
};