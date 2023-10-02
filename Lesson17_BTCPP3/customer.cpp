#include "customer.hpp"

bool done_flag = 0;

Customer::Customer(string customerName, string customerPhone, string customerAddress, uint16_t idroom)
{
    this->name = customerName;
    this->phoneNumber = customerPhone;
    this->address = customerAddress;
    this->idRoom = idroom;
}
uint16_t idRoom;
        string name;
        string phoneNumber;
        string address;
string Customer::getName()
{
    return name;
}
uint16_t Customer::getIDroom()
{
    return idRoom;
}
string Customer::getPhoneNumber()
{
    return phoneNumber;
}
string Customer::getAddress()
{
    return address;
}

void Customer::addIOHistory(InOutHistory &IODetails)
{
    this->IOHistory.push_back(IODetails);
}

void Customer::displayIOHistory()
{
    for(InOutHistory IOH : this->IOHistory)
    {
        cout<<IOH.time.hour<<" : "<<IOH.time.minute<<" : "<<IOH.time.second<<"  -  ";
        cout<<IOH.date.day<<" : "<<IOH.date.month<<" : "<<IOH.date.year<<"  -  ";
        cout<<IOH.status<<endl;
    }
}
void Customer::setName(string name)
{
    this->name = name;
}
void Customer::setIDroom(uint16_t idRoom)
{
    this->idRoom = idRoom;
}
void Customer::setPhoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Customer::setAddress(string address)
{
    this->address = address;
}


void CustomerManager::add_Customer(Customer &customer)
{
    this->Customer_database.push_back(customer);
}

void CustomerManager::remove_Customer()
{
    string name;
    uint16_t idRoom;
    string nametoChange;
    cout<<"Nhap Ten KH muon xoa: ";cin>>name;
    cout<<"Nhap idRoome KH muon xoa: ";cin>>idRoom;

    vector<Customer>::iterator cus_it;
    for(cus_it = Customer_database.begin(); cus_it != Customer_database.end(); cus_it++)
    {
        if((*cus_it).getName() == name && (*cus_it).getIDroom() == idRoom)
        {
            Customer_database.erase(cus_it);
        }
    }
}

void CustomerManager::edit_CustomerName()
{   
    string name;
    uint16_t idRoom;
    string nametoChange;
    cout<<"Nhap Ten KH muon Edit: ";cin>>name;
    cout<<"Nhap idRoom KH muon Edit: ";cin>>idRoom;
    
    vector<Customer>::iterator cus_it;
    for(cus_it = Customer_database.begin(); cus_it != Customer_database.end(); cus_it++)
    {
        if((*cus_it).getName() == name && (*cus_it).getIDroom() == idRoom)
        {
            cout<<"Nhap lai Ten: ";cin>>nametoChange;
            (*cus_it).setName(nametoChange);
        }
    }
}

void CustomerManager::print_CustomerName()
{
    vector<Customer>::iterator cus_it;
    for(cus_it = Customer_database.begin(); cus_it != Customer_database.end(); cus_it++)
    {
            cout<<" Room ID |"<<" Ten |"<<"Phone number |"<<" address "<<endl;
            cout<<"  "<<(*cus_it).getIDroom()<<"     "<<(*cus_it).getName()<<"        "<<(*cus_it).getPhoneNumber()<<"        "<<(*cus_it).getAddress()<<endl;
               
    }
    done_flag = 1;
}

void creatCustomer(CustomerManager &customermanager, int numOfCus)
{
    string name[10]= {"Hau","Ly","Huyen","Lan","Thuy","Nhi","Tha","Na","Ni","Nu"};
    string phoneNumber[10] = {"0905","0906",
                              "0907","0908","0909","0910","0911","0912","0914","0915"};
    for(int i = 0;i < numOfCus; i++)
    {
        Customer customer(name[i],phoneNumber[i],"Hoa Hao", i+100);

        InOutHistory IOHIS;

        IOHIS.time.hour = 2;
        IOHIS.time.minute = 2;
        IOHIS.time.second = 2;

        IOHIS.date.day = 2;
        IOHIS.date.month = 2;
        IOHIS.date.year = 2;

        IOHIS.status = IN;

        customer.addIOHistory(IOHIS);
        customermanager.add_Customer(customer);
    }
}

void CustomerManagementProgramm(CustomerManager &customermanager)
{
    int program_selection = 0;
    uint16_t room_num;
    string nameofcus;
    string phoneNumberofcus;
    string addressofcus;
    uint8_t dayofcus;
    uint8_t monthofcus;
    uint8_t yearofcus;
    uint8_t secondofcus;
    uint8_t minuteofcus;
    uint8_t hourofcus;
    while(program_selection != 5)
    {
        switch(program_selection)
        {
            case 0: //Init
                cout<<"1. Add customer\n";
                cout<<"2. Edit customer\n";
                cout<<"3. Remove customer\n";
                cout<<"4. Customerlist\n";
                cout<<"5. Return\n";
                cout<<"Moi chon CT: ";
                cin>>program_selection;
            break;
            case 1: //Add customer
            {
                cout<<"Nhap thong tin khach hang: "<<endl;

                cout<<"Nhap phong: ";
                cin>>room_num;
                cout<<"Nhap ten KH: ";
                cin>>nameofcus;
                cout<<"Nhap SDT KH: ";
                cin>>phoneNumberofcus;
                cout<<"Nhap dia chi KH: ";
                cin>>addressofcus;
            
                cout<<"day: ";
                cin>>dayofcus;cin.ignore();
                cout<<"month: ";
                cin>>monthofcus;cin.ignore();
                cout<<"year: ";
                cin>>yearofcus;cin.ignore();
                
                

                cout<<"second: ";cin>>secondofcus;cin.ignore();
                cout<<"minute: ";cin>>minuteofcus;cin.ignore();
                cout<<"hour: ";cin>>hourofcus;cin.ignore();

                Customer customer(nameofcus,phoneNumberofcus, addressofcus, room_num);

                InOutHistory IOHIS;

                IOHIS.time.hour = hourofcus;
                IOHIS.time.minute = minuteofcus;
                IOHIS.time.second = secondofcus;

                IOHIS.date.day = dayofcus;
                IOHIS.date.month = monthofcus;
                IOHIS.date.year = yearofcus;

                IOHIS.status = IN;

                customer.addIOHistory(IOHIS);
                customermanager.add_Customer(customer);
                program_selection = 0;
            break;
            }
            case 2: //Edit customer
                customermanager.edit_CustomerName();
                program_selection = 0;
            break;
            case 3: //Remove customer
                customermanager.remove_Customer();
                program_selection = 0;
            break;
            case 4:
            {
                customermanager.print_CustomerName();
                cin>>program_selection;
                
            break;
            }
            case 5:

            break;
        }
    }
}