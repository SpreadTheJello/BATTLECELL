#include "Floor.hpp"
#include "MonsterList.cpp"

class FirstFloor : public Floor {
    public:
        FirstFloor() {
            Room* room1 = new Room();
            this->addRoom(room1);
            Room* room2 = new Room();
            this->addRoom(room2);
            Room* room3 = new Room();
            this->addRoom(room3);
            Room* room4 = new Room();
            this->addRoom(room4);
            
            this->connectRooms(1, 0, 0);
            this->connectRooms(2, 0, 1);
            this->connectRooms(3, 1, 2);
            this->connectRooms(4, 2, 3);
            this->connectRooms(1, 3, 4);
        }
};
