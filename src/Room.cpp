#include "Room.hpp"

using namespace std;



/* Constructors */


// Default Constructor
Room::Room() {
    this->roomType = r_Type::EMPTY;
    this->nearbyRooms = new int[4];
    this->visited = false;
    
    nearbyRooms[0] = -1; // North Room
    nearbyRooms[1] = -1; // East Room
    nearbyRooms[2] = -1; // South Room
    nearbyRooms[3] = -1; // West Room
}

// New Room Constructor.
Room::Room(r_Type type, Creature* creature) {
    this->roomType = type;
    this->nearbyRooms = new int[4];
    this->visited = false;
    if (enemy != nullptr) {
        this->enemy = creature;
    }
    
    nearbyRooms[0] = -1; // North Room
    nearbyRooms[1] = -1; // East Room
    nearbyRooms[2] = -1; // South Room
    nearbyRooms[3] = -1; // West Room
}

// Copy Room Constructor.
Room::Room(Room& rCopy) {
    this->roomType = rCopy.getType();
    this->nearbyRooms = rCopy.getNearbyRooms();

    this->visited = false;
    this->enemy = rCopy.getEnemy();
}

// Destructor
Room::~Room() {
    delete[] nearbyRooms;
}


/* Room Functions */

// m_floor->getRoom(m_floor->getCurrentRoom())->printNearby();
// Prints nearby rooms.
void Room::printNearby() {
    cout << "Nearby: {N " << this->nearbyRooms[0] << "; E "<< this->nearbyRooms[1] << "; S "<< this->nearbyRooms[2] << "; W "<< this->nearbyRooms[3] << " }" << endl;
}

// Returns roomType
r_Type Room::getType() {
    return this->roomType;
}

// Marks room as cleared.
void Room::markCleared() {
    this->roomType = r_Type::CLEARED;
}

// Marks room as visited.
void Room::markVisited() {
    this->visited = true;
}

// Returns visited.
bool Room::isVisited() const{
    return this->visited;
}

// Returns enemy in room.
Creature* Room::getEnemy() const {
    return this->enemy;
}

// Attempts to set room's enemy. Returns false if there is already an enemy in the room.
bool Room::setEnemy(Creature* creature) {
    if(this->enemy == nullptr) {
        this->enemy = creature;
        return true;
    }
    return false;
}



/* Nearby Room Getters */

// Returns nearby rooms. (North, East, South, West)
int* Room::getNearbyRooms() const{
    return this->nearbyRooms;
}

// Returns Northern room.
int Room::getNorthRoom() const{
    return this->nearbyRooms[0];
}

// Returns Eastern room.
int Room::getEastRoom() const{
    return this->nearbyRooms[1];
}

// Returns Southern room.
int Room::getSouthRoom() const{
    return this->nearbyRooms[2];
}

// Returns Western room.
int Room::getWestRoom() const{
    return this->nearbyRooms[3];
}



/* Nearby Room Setters */


// Attempts to set Northern room. Returns false if there is already a Northern room.
bool Room::setNorthRoom(int room) {
    if (this->nearbyRooms[0] == -1) {
        this->nearbyRooms[0] = room;
        return true;
    }
    return false;
}

// Attempts to set Eastern room. Returns false if there is already a Northern room.
bool Room::setEastRoom(int room) {
    if (this->nearbyRooms[1] == -1) {
        this->nearbyRooms[1] = room;
        return true;
    }
    return false;
}

// Attempts to set Southern room. Returns false if there is already a Northern room.
bool Room::setSouthRoom(int room) {
    if (this->nearbyRooms[2] == -1) {
        this->nearbyRooms[2] = room;
        return true;
    }
    return false;
}

// Attempts to set Western room. Returns false if there is already a Northern room.
bool Room::setWestRoom(int room) {
    if (this->nearbyRooms[3] == -1) {
        this->nearbyRooms[3] = room;
        return true;
    }
    return false;
}
