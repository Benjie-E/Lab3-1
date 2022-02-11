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
#include <sstream>
#include "House.h"
#include <iostream>
#include <array>
using namespace std;

House::House() {
	for (int i = 0; i < MAX_ROOMS; i++)
		roomIndex = rooms;
}

//return false if room has too low a height, too small an area or the house already is at max for that type of room
bool House::addRoom(const Room &theRoom) {
	if (theRoom.getSquareFootage() < MIN_AREA
			|| theRoom.getHeight() < MIN_HEIGHT)
		return false;
	switch (theRoom.getType()) {
	case KITCHEN:
		if (getNumKitchens() < MAX_KITCHENS) {
			*roomIndex++ = theRoom;
			return true;
		}
		break;
	case BATHROOM:
		if (getNumBathrooms() < MAX_BATHROOMS) {
			*roomIndex++ = theRoom;
			return true;
		}
		break;
	case LIVINGROOM:
		if (getNumLivingrooms() < MAX_LIVINGROOMS) {
			*roomIndex++ = theRoom;
			return true;
		}
		break;
	case BEDROOM:
		if (getNumBedrooms() < MAX_BEDROOMS) {
			*roomIndex++ = theRoom;
			return true;
		}
		break;
	default:
		return false;

	}
	return false;
}

int House::getNumBedrooms() {
	return getNumRoom(BEDROOM);
}

int House::getNumBathrooms() {
	return getNumRoom(BATHROOM);
}

int House::getNumKitchens() {
	return getNumRoom(KITCHEN);
}

int House::getNumLivingrooms() {
	return getNumRoom(LIVINGROOM);
}

int House::getNumRoom(RoomType type) {
	int count { 0 };
	for (int i = 0; i < MAX_ROOMS; i++) {
		if (rooms[i].getType() == type && rooms[i].getSquareFootage() > 0)
			count++;
	}
	return count;
}

int House::getTotalSquareFootage() {
	int sum { 0 };
	for (int i = 0; i < MAX_ROOMS; i++)
		sum += rooms[i].getSquareFootage();
	return sum;
}

int House::getTotalVolume() {
	int sum { 0 };
	for (int i = 0; i < MAX_ROOMS; i++)
		sum += rooms[i].getVolume();
	return sum;
}

bool House::isValid() {
	return !(getNumKitchens()<MIN_KITCHENS||getNumBathrooms()<MIN_BATHROOMS||
			getNumLivingrooms()<MIN_LIVINGROOMS||getNumBedrooms()<MIN_BEDROOMS);
	return false;
}

string House::enumerateRooms() {
	stringstream report { "These are the rooms in the house:\n" };
	for (Room *room = rooms; room < roomIndex; room++) {
		report << (*room).getDescription();
	}
	return report.str();
}

string House::getDescription() {
	stringstream theStream;

	theStream << "House has:\n" << getNumRoom(BEDROOM) << " Bedrooms\n"
			<< getNumRoom(BATHROOM) << " Bathrooms\n" << getNumRoom(KITCHEN)
			<< " Kitchens\n" << getNumRoom(LIVINGROOM) << " Livingrooms\n\n"
			<< getTotalSquareFootage() << " Square feet total\n"
			<< getTotalVolume() << " Cubic feet total volume\n";

	if (isValid()) {
		theStream << "House is Valid!\n\n";
	} else {
		theStream << "House is not Valid!\n\n";
	}

	return theStream.str();
}
