#include "employee.hpp"

Employee::Employee(string nameEmployee, string phoneNumberEmployee, jobPosition position, Schedule schedule)
{
    this->Name = nameEmployee;
    this->phoneNumber = phoneNumberEmployee;
    this->position = position;
    this->schedule = schedule;
}

string Employee::getName()
{
    return this->Name;
}
string Employee::getphoneNumber()
{
    return this->phoneNumber;
}
jobPosition Employee::getPosition()
{
    return this->position;
}
Schedule Employee::getSchedule()
{
    return this->schedule;
}
void Employee::setName(string Name)
{
    this->Name = Name;
}
void Employee::setphoneNumber(string phoneNumber)
{
    this->phoneNumber = phoneNumber;
}
void Employee::setPosition(jobPosition position)
{
    this->position = position;
}
void Employee::setSchedule(Schedule schedule)
{
    this->schedule = schedule;
}



bool User::authenticate(string inputUsername, string inputPassword)
{
    bool checkSignup = (inputUsername == this->username && inputPassword == this->password);
    return checkSignup;
}
string User::getUsername()
{
    return this->username;
}

User::User(string username, string password)
{
    this->username = "hau";
    this->password = "hau123";
}

void EmployeeManagement::addEmployee(Employee &employee)
{
    this->EmployeeDatabase.push_back(employee);
}

bool EmployeeManagement::checkAuthenticate(string inputUsername, string inputPassword )
{
    if(user.authenticate(inputUsername, inputPassword) || inputUsername == "admin")
    {
        this->isAuthenticate = true;
    }
    return isAuthenticate;
}



void addEmployee(EmployeeManagement &emloyeemanager)
{
    string Name;
    string phoneNumber;

    cout<<"Nhap ten NV: ";cin>>Name;
    cout<<"Nhap SDT NV:";cin>>phoneNumber;

    jobPosition position;
    cout<<"Chon position:\n1. JANITOR\n2. RECEPTIONIST\n3. LAUNDRY_STAFF\n4. LUGGAGE_STAFF\n5. GARDENER\n";
    int select;
    cin>>select;
    switch(select)
    {
        case 1:
            position = JANITOR;
        break; 
        case 2:
            position = RECEPTIONIST;
        break; 
        case 3:
            position = LAUNDRY_STAFF;
        break; 
        case 4:
            position = LUGGAGE_STAFF;
        break; 
        case 5:
            position = GARDENER;
        break; 
    }
    
    uint8_t day;
    uint8_t month;
    uint8_t year;
    uint8_t second;
    uint8_t minute;
    uint8_t hour;

    cout<<"day: ";
    cin>>day;cin.ignore();
    cout<<"month: ";
    cin>>month;cin.ignore();
    cout<<"year: ";
    cin>>year;cin.ignore();
    Schedule schedule;

    schedule.Date = {day, month, year};

    cout<<"second: ";cin>>second;cin.ignore();
    cout<<"minute: ";cin>>minute;cin.ignore();
    cout<<"hour: ";cin>>hour;cin.ignore();

    schedule.time = {second, minute, hour};

    Employee employee(Name, phoneNumber,position, schedule);
    emloyeemanager.addEmployee(employee);
    
}

void EmployeeManagement::removeEmployee()
{
    string name;
    string phoneNumber;

    cout<<"Nhap Ten KH muon xoa: ";cin>>name;
    cout<<"Nhap phone number KH muon xoa: ";cin>>phoneNumber;

    vector<Employee>::iterator em_it;
    for(em_it = EmployeeDatabase.begin(); em_it != EmployeeDatabase.end(); em_it++)
    {
        if((*em_it).getName() == name && (*em_it).getphoneNumber() == phoneNumber)
        {
            EmployeeDatabase.erase(em_it);
        }
    }
}

void EmployeeManagement::editEmployee_Name()
{   
    string name;
    string phoneNumber;
    string nametoChange;

    cout<<"Nhap Ten KH muon xoa: ";cin>>name;
    cout<<"Nhap phone number KH muon xoa: ";cin>>phoneNumber;
    
    vector<Employee>::iterator em_it;
    for(em_it = EmployeeDatabase.begin(); em_it != EmployeeDatabase.end(); em_it++)
    {
        if((*em_it).getName() == name && (*em_it).getphoneNumber() == phoneNumber)
        {
            cout<<"Nhap lai Ten: ";cin>>nametoChange;
            (*em_it).setName(nametoChange);
        }
    }
}

void EmployeeManagement::print_Employee()
{
    vector<Employee>::iterator em_it;
    for(em_it = EmployeeDatabase.begin(); em_it != EmployeeDatabase.end(); em_it++)
    {
            cout<<" Name |"<<" phoneNumber |"<<" position |"<<" schedule "<<endl;
            cout<<"  "<<(*em_it).getName()<<"      "<<(*em_it).getphoneNumber()<<"            "<<(*em_it).getPosition()<<"        "
            <<(*em_it).getSchedule().Date.day<<" : "<<(*em_it).getSchedule().Date.month<<" : "<<(*em_it).getSchedule().Date.year<<endl;                                                  
    }
}
void createEmployeee(EmployeeManagement &emloyeemanager, int num)
{
    string name[10]= {"Hau","Ly","Huyen","Lan","Thuy","Nhi","Tha","Na","Ni","Nu"};
    string phoneNumber[10] = {"0905","0906",
                              "0907","0908","0909","0910","0911","0912","0914","0915"};
    for(int i = 0;i < num; i++)
    {
        Schedule schedule;

        schedule.time.hour = 2;
        schedule.time.minute = 2;
        schedule.time.second = 2;

        schedule.Date.day = 2;
        schedule.Date.month = 2;
        schedule.Date.year = 2;

        schedule.status = IN;

        Employee employee(name[i],phoneNumber[i], RECEPTIONIST, schedule);
        emloyeemanager.addEmployee(employee);
    }
}

void employeeManager(EmployeeManagement &emloyeemanager)
{
    string username;
    string password;

    cout<<"Moi nhan username: "; cin>>username;
    cout<<"Moi nhap password: "; cin>>password;
    
    bool checkSignup = emloyeemanager.checkAuthenticate(username, password);
    if(checkSignup == 0) return;

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
                cout<<"1. Add employee\n";
                cout<<"2. Edit employee\n";
                cout<<"3. Remove employee\n";
                cout<<"4. employee list\n";
                cout<<"5. Return\n";
                cout<<"Moi chon CT: ";
                cin>>program_selection;
            break;
            case 1: //Add customer
                addEmployee(emloyeemanager);
            break;
            case 2: //Edit customer
                emloyeemanager.editEmployee_Name();
                program_selection = 0;
            break;
            case 3: //Remove customer
                emloyeemanager.removeEmployee();
                program_selection = 0;
            break;
            case 4:
            {
                emloyeemanager.print_Employee();
                program_selection = 0;
            break;
            }
            case 5:
            break;
        }
    }
}