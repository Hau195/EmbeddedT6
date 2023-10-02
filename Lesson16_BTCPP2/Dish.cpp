#include "Dish.hpp"

Dish::Dish(string ten_mon, int gia)
{
    static int id = 100;
    ID = id;
    id++;
    TM = ten_mon;
    GIA = gia;
}

int Dish::get_Gia()
{
    return GIA;
}
int Dish::get_ID()
{
    return ID;
}
string Dish::get_TM()
{
    return TM;
}

void Dish::set_TM(string ten_mon)
{
    TM = ten_mon;
}

void Dish::set_Gia(int gia)
{
    this->GIA = gia;
}

int Dish::get_SL()
{
    return SL;
}

void Dish::set_SL(int soluong)
{
    this->SL = soluong;
}
void Add_dish(list<Dish> &database)
{
    string ten_mon;
    int gia;

    cout<<"Nhap Ten mon: ";
    cin>>ten_mon;
    cout<<"Nhap gia: ";
    cin>>gia;

    Dish mon(ten_mon, gia);
    database.push_back(mon);
    cout<<"Da them sv"<<endl;
}

void Edit_TM_byID(list<Dish> &database)
{
    int id;
    cout<<"Moi nhap ID";
    cin>>id;

    string ten_mon;
    bool count = 0;

    for(Dish mon : database)
    {
        if(mon.get_ID() == id)
        {
            cout<<"Nhap Ten mon: ";
            cin>>ten_mon;
            mon.set_TM(ten_mon);
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da cap nhat xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void Edit_gia_byID(list<Dish> &database, int id)
{
    int gia;
    bool count = 0;

    list<Dish>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).get_ID() == id)
        {
            cout<<"Nhap gia: ";
            cin>>gia;
            (*it).set_Gia(gia);
            
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da cap nhat xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void removebyID(list<Dish> &database, int id)
{
    bool count = 0;
    list<Dish>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).get_ID() == id)
        {
            database.erase(it);
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da xoa xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void get_infor(list<Dish> &database, int id)
{   
    list<Dish>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).get_ID() == id)
        {
            cout <<" ID "<<" Ten Mon "<<" Gia "<<endl;
            cout <<(*it).get_ID()<<"  "<<(*it).get_TM()<<"  "<<(*it).get_Gia()<<endl;
        }
        
    }
    
}

void Dish_list(list<Dish> &database)
{
    int num_dish = 0;
    cout<<"STT  ID  Ten mon  Gia"<<endl; 
    for(Dish mon : database)
    {   
        cout<<" "<<num_dish<<"   "<<mon.get_ID()<<"   "<<mon.get_TM()<<"    "<<mon.get_Gia()<<endl;
        num_dish++;
    }
}
