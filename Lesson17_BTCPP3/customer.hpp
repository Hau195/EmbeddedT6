#include<iostream>
#include<string>
#include<vector>
#include "employee.hpp"

using namespace std;

typedef struct
{
    typeTime time;
    typeDate date;
    typeStatus status;
}InOutHistory;

class Customer
{
    private:
        uint16_t idRoom;
        string name;
        string phoneNumber;
        string address;
        vector <InOutHistory> IOHistory;
    public:
        Customer(string customerName, string customerPhone, string customerAddress, uint16_t idroom);
        string getName();
        uint16_t getIDroom();
        string getPhoneNumber();
        string getAddress();
        void setName(string name);
        void setIDroom(uint16_t idRoom);
        void setPhoneNumber(string phoneNumber);
        void setAddress(string address);
        void addIOHistory(InOutHistory &IODetails);
        void displayIOHistory();
};

class CustomerManager
{
    private:
        vector<Customer> Customer_database;
    public:
        void add_Customer(Customer &customer);
        void remove_Customer();
        void edit_CustomerName();
        void print_CustomerName();
};

void CustomerManagementProgramm(CustomerManager &customermanager);
void creatCustomer(CustomerManager &customermanager, int numOfCus);