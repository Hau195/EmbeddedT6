#include "room.hpp"

uint16_t Room::get_roomNumber()
{
    return roomNumber;
}
bool Room::getIsBooked()
{
    return isBooked;
}
bool Room::getIsCleaning()
{
    return isCleaning;
}
void createRoom(list<Room> &roomdatabase, int numberOfRoom)
{
    for(int i = 0; i < numberOfRoom; i++)
    {
        Room room(100+i);
        roomdatabase.push_back(room);
    }
}
void bookRoom(list<Room> &roomdatabase, CustomerManager &customerManager)
{
    int roomSelection = 0;
    
    for(Room room : roomdatabase)
    {
        cout<<room.get_roomNumber()<<" | ";
    }
    cout<<endl;
    cout<<"------------------------------------------------------"<<endl;
    for(Room room : roomdatabase)
    {
        cout<<room.isAvailable()<<"   | ";
    }
    cout<<endl;
    cout<<"Moi chon phong: ";
    cin>>roomSelection;

    list<Room>::iterator room_it;
    for(room_it = roomdatabase.begin(); room_it != roomdatabase.end(); room_it++)
    {
        if((*room_it).get_roomNumber() == roomSelection)
        {
            (*room_it).bookRoom();
            (*room_it).checkIn();
            cout<<(*room_it).isAvailable()<<endl;
            cout<<(*room_it).getIsBooked()<<endl;
            cout<<(*room_it).getIsCleaning()<<endl;

            cout<<"Nhap thong tin khach hang: "<<endl;

            string name;
            string phoneNumber;
            string address;

            cout<<"Nhap ten KH: ";
            cin>>name;
            cout<<"Nhap SDT KH: ";
            cin>>phoneNumber;
            cout<<"Nhap dia chi KH: ";
            cin>>address;

            uint8_t day;
            uint8_t month;
            uint8_t year;
        
            cout<<"day: ";
            cin>>day;cin.ignore();
            cout<<"month: ";
            cin>>month;cin.ignore();
            cout<<"year: ";
            cin>>year;cin.ignore();
            
            uint8_t second;
            uint8_t minute;
            uint8_t hour;

            cout<<"second: ";cin>>second;cin.ignore();
            cout<<"minute: ";cin>>minute;cin.ignore();
            cout<<"hour: ";cin>>hour;cin.ignore();

            Customer customer(name,phoneNumber, address, roomSelection);

            InOutHistory IOHIS;

            IOHIS.time.hour = hour;
            IOHIS.time.minute = minute;
            IOHIS.time.second = second;

            IOHIS.date.day = day;
            IOHIS.date.month = month;
            IOHIS.date.year = year;

            IOHIS.status = IN;

            customer.addIOHistory(IOHIS);
            customerManager.add_Customer(customer);
            
        }
        
    }
}

void roomManagerment(list<Room> &roomdatabase, CustomerManager &customerManager)
{
    int proSelection = 0;
    while(proSelection != 2)
    {
        switch(proSelection)
        {
            case 0:
                
                for(Room room : roomdatabase)
                {
                    cout<<room.get_roomNumber()<<" | ";
                }
                cout<<endl;
                cout<<"----------------------------------------------------------"<<endl;
                for(Room room : roomdatabase)
                {
                    cout<<room.isAvailable()<<"   | ";
                }
                cout<<endl;
                cout<<"1. Bookroom\n2. Checkout\n0. Return\n";
                cin>>proSelection;
            break;
            case 1://Bookroom
                bookRoom(roomdatabase, customerManager);
                proSelection = 0;
            break;
            case2:

            break;

        }
    }
}