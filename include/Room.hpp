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

class Room {
  protected:
    Room** nearbyRooms = nullptr;
    r_Type roomType;
    bool visited;

    Creature* enemy = nullptr;

  public:
    Room();
    Room(r_Type type, Creature* enemy = nullptr);
    Room(Room& rCopy);

    ~Room();

    r_Type getType();
    bool setType(r_Type type); // returns false if room already has a type

    Creature* getEnemy() const;
    bool setEnemy(Creature* creature); // returns false if room already has an enemy

    void markVisited();
    void markCleared();

    bool isVisited() const;

    Room** getNearbyRooms() const;
    Room* getNorthRoom() const;
    Room* getEastRoom() const;
    Room* getSouthRoom() const;
    Room* getWestRoom() const;

    bool setNorthRoom(Room* room);
    bool setEastRoom(Room* room);
    bool setSouthRoom(Room* room);
    bool setWestRoom(Room* room);
};


#endif