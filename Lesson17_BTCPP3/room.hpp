#include<iostream>
#include<string>
#include <list>
#include "customer.hpp"

using namespace std;

// typedef enum
// {
//     AVAILABLE,
//     BOOKED,
//     ISCLEANING
// }RoomStatus;



class Room
{
    private:
        uint16_t roomNumber;
        bool isBooked;
        bool isCleaning;
    public:
        Room(uint16_t room_number)
        {
            this->roomNumber = room_number;
            isBooked = false;
            isCleaning = false;
        }
        uint16_t get_roomNumber();
        bool getIsBooked();
        bool getIsCleaning();
        bool isAvailable()
        {
            return isBooked & !isCleaning;
        }
        void bookRoom()
        {
            isBooked = true;
        }
        void checkIn()
        {
            isBooked = true;
            isCleaning = false;
        }
        void checkOut()
        {
            isBooked = false;
            isCleaning = true;
        }
};

void roomManagerment(list<Room> &roomdatabase, CustomerManager &customerManager);
void bookRoom(list<Room> &roomdatabase, CustomerManager &customerManager);
void createRoom(list<Room> &roomdatabase, int numberOfRoom);
