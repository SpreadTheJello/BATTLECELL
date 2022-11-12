#include "Floor.hpp"

using namespace std;

Floor::Floor() {
    Room* rootRoom = new Room();
    this->rooms.push_back(rootRoom);
    this->currentRoom = 0;
}

Floor::~Floor() {
    for (auto i = rooms.begin(); i != rooms.end(); i ++) {
        delete *i;
    }
}

int Floor::getCurrentRoom() {
    return this->currentRoom;
}

Room* Floor::getRoom(int index) {
    if (index >= this->rooms.size() && index >= 0)
        return nullptr;
    return this->rooms[index];
}

int Floor::floorSize() {
    return this->rooms.size();
}

void Floor::addRoom(Room* newRoom){
    this->rooms.push_back(newRoom);
    
};

// Attempt to put room1 {0:North, 1:East, 2:South, 3:West} of room2
bool Floor::connectRooms(int room1, int direction, int room2){
    if ( direction == 0 &&  this->rooms[room1]->getSouthRoom() == -1  && this->rooms[room2]->getNorthRoom() == -1 ) {
        this->rooms[room2]->setNorthRoom(room1);
        this->rooms[room1]->setSouthRoom(room2);
        return true;
    }
    else if(direction == 1 && this->rooms[room1]->getWestRoom() == -1  && this->rooms[room2]->getEastRoom() == -1 ) {
        this->rooms[room2]->setEastRoom(room1);
        this->rooms[room1]->setWestRoom(room2);
        return true;
    }
    else if(direction == 2 && this->rooms[room1]->getNorthRoom() == -1  && this->rooms[room2]->getSouthRoom() == -1 ) {
        this->rooms[room2]->setSouthRoom(room1);
        this->rooms[room1]->setNorthRoom(room2);
        return true;
    }
    else if(direction == 3 && this->rooms[room1]->getEastRoom() == -1  && this->rooms[room2]->getWestRoom() == -1 ) {
        this->rooms[room2]->setWestRoom(room1);
        this->rooms[room1]->setEastRoom(room2);
        return true;
    }
    return false;
};


bool Floor::traverse(int direction) {
    int* nearby = this->rooms[currentRoom]->getNearbyRooms();
    if (nearby[direction] != -1) {
        this->currentRoom = nearby[direction];
        return true;
    }
    return false;
}
