#include <iostream>
#include <string>
#include <list>
#include "Dish.hpp"
#include <vector>

using namespace std;

class Table
{
    private:
        int TABLE_NUM;
        bool STATUS;
        vector<Dish> Table_data; 
    public:
        Table(bool status);
        bool get_status();
        void set_status(bool status);
        vector<Dish> get_Tabledata();
        void set_Tabledata(Dish &mon);
        void remove_Tabledata(Dish &mon);
        int get_TABLE_NUM();
};

void Set_numofTables(list<Table> &Tabledatabase, int num);

void Add_dish(list<Dish> &database, Table &table, int id, int soluong);

void Edit_gia_byID(list<Dish> &database, Table &table, int id);

void removebyID(list<Dish> &database, Table &table, int id);

void get_infor(Dish &mon);

void Dish_list(Table &table);

int Bill(Table &table);


