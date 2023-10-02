#include <iostream>
#include <string>
#include <list>
using namespace std;

class Dish
{
    private:
        int ID;
        string TM;
        int GIA;
        int SL;
    public:
        Dish(string ten_mon, int gia);
        int get_ID();
        string get_TM();
        int get_Gia();
        int get_SL();
        void set_TM(string ten_mon);
        void set_Gia(int gia);
        void set_SL(int soluong);

};

void Add_dish(list<Dish> &database);
void Edit_TM_byID(list<Dish> &database);
void Edit_gia_byID(list<Dish> &database, int id);
void removebyID(list<Dish> &database, int id);
void get_infor(list<Dish> &database, int id);
void Dish_list(list<Dish> &database);