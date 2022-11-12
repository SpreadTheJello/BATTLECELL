#ifndef _ROOM_HPP_
#define _ROOM_HPP_

#include <string>
#include "Creature.hpp"

enum r_Type {
    EMPTY,
    MONSTER,
    SIDEBOSS,
    FLOORBOSS,
    SHOP,
    REST,
    CLEARED,
};
// Main Set (floor), 
// Main set contains a list of ID's (rooms)
// List of ID's contain directions (ID's to other rooms)
class Room {
  protected:
    int* nearbyRooms = nullptr;
    r_Type roomType;
    bool visited;

    Creature* enemy = nullptr;

  public:
    Room();
    Room(r_Type type, Creature* creature = nullptr);
    Room(Room& rCopy);

    ~Room();

    void printNearby();

    void printRoomType();

    r_Type getType();
    bool setType(r_Type type); // returns false if room already has a type

    Creature* getEnemy() const;
    bool setEnemy(Creature* creature); // returns false if room already has an enemy

    void markVisited();
    void markCleared();

    bool isVisited() const;

    int* getNearbyRooms() const;
    int getNorthRoom() const;
    int getEastRoom() const;
    int getSouthRoom() const;
    int getWestRoom() const;

    bool setNorthRoom(int room);
    bool setEastRoom(int room);
    bool setSouthRoom(int room);
    bool setWestRoom(int room);
};


#endif