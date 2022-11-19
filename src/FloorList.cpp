#include "Floor.hpp"
#include "MonsterList.cpp"
#include "Creature.hpp"

class FirstFloor : public Floor {
    public:
        FirstFloor() {
            Room* room1 = new Room(r_Type::SHOP);
            this->addRoom(room1);
            Room* room2 = new Room(r_Type::MONSTER, new Zombie());
            this->addRoom(room2);
            Room* room3 = new Room(r_Type::REST);
            this->addRoom(room3);
            Room* room4 = new Room(r_Type::MONSTER, new Daemon());
            this->addRoom(room4);
            
            this->connectRooms(1, 0, 0);
            this->connectRooms(2, 0, 1);
            this->connectRooms(3, 1, 2);
            this->connectRooms(4, 2, 3);
            this->connectRooms(1, 3, 4);
        }
};
