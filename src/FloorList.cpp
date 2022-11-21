#include "Floor.hpp"
#include "MonsterList.cpp"
#include "Creature.hpp"

class FirstFloor : public Floor {
    public:
        FirstFloor() {
            Room* shop = new Room(r_Type::SHOP); // 1
            this->addRoom(shop);

            Room* monster1 = new Room(r_Type::MONSTER, new Zombie()); // 2
            this->addRoom(monster1);
            Room* monster2 = new Room(r_Type::MONSTER, new FlamingSkull()); // 3
            this->addRoom(monster2);
            Room* monster3 = new Room(r_Type::MONSTER, new Skeleton()); // 4
            this->addRoom(monster3);
            Room* monster4 = new Room(r_Type::MONSTER, new Zombie()); // 5
            this->addRoom(monster4);
            Room* monster5 = new Room(r_Type::MONSTER, new Skeleton()); // 6
            this->addRoom(monster5);
            Room* monster6 = new Room(r_Type::MONSTER, new Skeleton()); // 7
            this->addRoom(monster6);
            Room* monster7 = new Room(r_Type::MONSTER, new FlamingSkull()); // 8
            this->addRoom(monster7);

            Room* sideBoss1 = new Room(r_Type::SIDEBOSS, new Vampire()); // 9
            this->addRoom(sideBoss1);
            Room* sideBoss2 = new Room(r_Type::SIDEBOSS, new Necromancer()); // 10
            this->addRoom(sideBoss2);

            Room* floorBoss = new Room(r_Type::FLOORBOSS, new DeathKnight()); // 11
            this->addRoom(floorBoss);

            Room* empty1 = new Room(); // 12
            this->addRoom(empty1);
            Room* empty2 = new Room(); // 13
            this->addRoom(empty2);
            Room* empty3 = new Room(); // 14
            this->addRoom(empty3);
            Room* empty4 = new Room(); // 15
            this->addRoom(empty4);
            Room* empty5 = new Room(); // 16
            this->addRoom(empty5);

            Room* rest1 = new Room(r_Type::REST); // 17
            this->addRoom(rest1);
            Room* rest2 = new Room(r_Type::REST); // 18
            this->addRoom(rest2);
            Room* rest3 = new Room(r_Type::REST); // 19
            this->addRoom(rest3);


            // Connected to 0
            this->connectRooms(1, 1, 0);

            // Connected to 1
            this->connectRooms(2, 0, 1);
            this->connectRooms(3, 1, 1);
            this->connectRooms(12, 2, 1);

            // Connected to 2
            this->connectRooms(17, 1, 2);

            // Connected to 3
            this->connectRooms(4, 2, 3);

            // Connected to 4
            this->connectRooms(15, 1, 4);
            this->connectRooms(13, 2, 4);
            this->connectRooms(12, 3, 4);

            // Connected to 5
            this->connectRooms(7, 1, 5);
            this->connectRooms(14, 2, 5);
            this->connectRooms(9, 3, 5);

            // Connected to 6
            this->connectRooms(14, 0, 6);
            this->connectRooms(19, 1, 6);
            this->connectRooms(15, 2, 6);
            
            // Connected to 7
            this->connectRooms(16, 2, 7);
            
            // Connected to 8
            this->connectRooms(10, 0, 8);
            this->connectRooms(18, 3, 8);
            
            // Connected to 9
            this->connectRooms(5, 1, 9);
            this->connectRooms(17, 2, 6);
            
            // Connected to 10
            this->connectRooms(19, 0, 10);
            this->connectRooms(8, 2, 10);
            this->connectRooms(15, 3, 10);
            
            // Connected to 11
            this->connectRooms(19, 3 , 11);

            // Connected to 12
            this->connectRooms(1, 0, 12);
            this->connectRooms(4, 1, 12);
            
            // Connected to 13
            this->connectRooms(4, 0, 13);
            this->connectRooms(18, 1, 13);
            
            // Connected to 14
            this->connectRooms(5, 0, 14);
            this->connectRooms(6, 2, 14);
            this->connectRooms(17, 2, 14);
            
            // Connected to 15
            this->connectRooms(6, 0, 15);
            this->connectRooms(10, 1, 15);
            this->connectRooms(4, 3, 15);
            
            // Connected to 16
            this->connectRooms(7, 0, 16);
            this->connectRooms(19, 2, 16);
            
            // Connected to 17
            this->connectRooms(9, 0, 17);
            this->connectRooms(14, 1, 17);
            this->connectRooms(2, 3, 17);

            // Connected to 18
            this->connectRooms(8, 1, 18);
            this->connectRooms(13, 3, 18);

            // Connected to 19
            this->connectRooms(16, 0, 19);
            this->connectRooms(11, 1, 19);
            this->connectRooms(10, 2, 19);
            this->connectRooms(6, 3, 19);
    
        }
};
