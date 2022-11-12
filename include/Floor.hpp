#ifndef _FLOOR_HPP_
#define _FLOOR_HPP_

#include "Room.hpp"
#include <vector>

class Floor {
    private:
        std::vector<Room*> rooms;
        int currentRoom;
        
    public:
        Floor();
        ~Floor(); 
        
        
        int floorSize();

        int getCurrentRoom();

        Room* getRoom(int index = 0);

        void addRoom(Room* newRoom);

        bool connectRooms(int room1, int direction, int room2);

        bool traverse(int direction);
};



#endif