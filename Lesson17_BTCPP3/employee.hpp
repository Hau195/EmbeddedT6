#include<iostream>
#include<string>
#include<vector>

using namespace std;

typedef enum
{
    JANITOR,
    RECEPTIONIST,
    LAUNDRY_STAFF,
    LUGGAGE_STAFF,
    GARDENER
}jobPosition;

typedef enum
{
    IN,
    OUT
}typeStatus;

typedef struct
{
    int day;
    int month;
    int year;
}typeDate;

typedef struct
{
    int second;
    int minute;
    int hour;
}typeTime;

typedef struct
{
    typeTime time;
    typeDate Date;
    typeStatus status;
}Schedule;

class User
{
    private:
        string username;
        string password;
    public:
        User(string username = "", string password = "");
        string getUsername();
        bool authenticate(string username, string inputPassword);
};

class Employee
{
    private:
        string Name;
        string phoneNumber;
        jobPosition position;
        Schedule schedule;
        
    public:
        Employee(string nameEmployee, string phoneNumberEmployee, jobPosition position, Schedule schedule);
        string getName();
        string getphoneNumber();
        jobPosition getPosition();
        Schedule getSchedule();
        void setName(string Name);
        void setphoneNumber(string phoneNumber);
        void setPosition(jobPosition position);
        void setSchedule(Schedule schedule);
};

class EmployeeManagement
{
    private:
        vector<Employee> EmployeeDatabase;
        bool isAuthenticate;
        User user;
    public:
        bool checkAuthenticate(string inputUsername, string inputPassword );
        void addEmployee(Employee &employee);
        void editEmployee_Name();
        void removeEmployee();
        void print_Employee();
};


void employeeManager(EmployeeManagement &emloyeemanager);
void createEmployeee(EmployeeManagement &emloyeemanager, int num);
