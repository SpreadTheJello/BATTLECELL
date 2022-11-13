#ifndef _ROOM_HPP_
#define _ROOM_HPP_

#include <string>
#include "Creature.hpp"
#include "Console.hpp"

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
    int* nearbyRooms = nullptr;
    r_Type roomType;
    bool visited;

    Creature* enemy = nullptr;

    Console* logger = nullptr;

  public:
    Room();
    Room(r_Type type, Creature* creature = nullptr);
    Room(Room& rCopy);

    ~Room();

    void printNearby();

    r_Type getType();
    std::string getRoomString();
    bool setType(r_Type type); // returns false if room already has a type

    Creature* getEnemy();
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