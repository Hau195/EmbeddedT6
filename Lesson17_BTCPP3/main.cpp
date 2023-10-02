#include "main.hpp"





int main(int argc, char const *argv[])
{
    
    list <Room> room_database;
    CustomerManager customermanager;
    EmployeeManagement emloyeemanager;

    createRoom(room_database, 10);
    creatCustomer(customermanager, 10);
    createEmployeee(emloyeemanager, 10);
    int selection = 0;

    cout<<"1. Quan li dat phong\n"
        <<"2. Quan li khach hang\n"
        <<"3. Quan li nhan vien\n";

    cin>>selection;

    switch(selection)
    {
        case 1: // Quan li phong
            roomManagerment(room_database, customermanager);
        break;
        case 2:// Quan li khach hang
            CustomerManagementProgramm(customermanager);
        break;
        case 3:
            employeeManager(emloyeemanager);
        break;
        case 4:
        break;
    }

}