/*
Author:       Benjie
Class:        CSI-240-03
Assignment:   Lab 3-1
Date Assigned:1/31/2022
Due Date:     2/11/2022 14:30
Description:
Add and describe rooms of a house.
Certification of Authenticity:
    I certify that this is entirely my own work, except where I have given
    fully-documented references to the work of others. I understand the
    definition and consequences of plagiarism and acknowledge that the assessor
    of this assignment may, for the purpose of assessing this assignment:
        - Reproduce this assignment and provide a copy to another member of
academic staff; and/or
        - Communicate a copy of this assignment to a plagiarism checking
          service (which may then retain a copy of this assignment on its
          database for the purpose of future plagiarism checking)
*/
#pragma once

#include <string>
#include "Room.h"

//a house can never have more than these number of roooms of each type
const int MAX_BEDROOMS = 4;
const int MAX_KITCHENS = 1;
const int MAX_BATHROOMS = 2;
const int MAX_LIVINGROOMS = 5;
const int MAX_ROOMS = MAX_BEDROOMS+MAX_KITCHENS+MAX_BATHROOMS+MAX_LIVINGROOMS;
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
public:	//constructor
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
	int getNumRoom(RoomType type);
	Room rooms[MAX_ROOMS];
	Room* roomIndex;
};
