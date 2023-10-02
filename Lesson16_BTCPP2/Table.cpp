#include "Table.hpp"


Table::Table(bool status)
{
    static int table_num = 1;
    TABLE_NUM = table_num;
    table_num++;

    this->STATUS = status;
}

bool Table::get_status()
{
    return STATUS;
}

void Table::set_status(bool status)
{
    this->STATUS = status;
}

void Table::set_Tabledata(Dish &mon)
{
    this->Table_data.push_back(mon);
}
void Table::remove_Tabledata(Dish &mon)
{
    vector<Dish>::iterator it;
    for(it = this->Table_data.begin(); it != this->Table_data.end(); it++)
    {
        if((*it).get_ID() == mon.get_ID())
        {
            Table_data.erase(it);
        }
    }
}

vector<Dish> Table::get_Tabledata()
{
    return Table_data;
}

int Table::get_TABLE_NUM()
{
    return TABLE_NUM;
}

void Set_numofTables(list<Table> &Tabledatabase, int num)
{   
    for(int i = 0; i < num; i++)
    {
        Table Tb(false);
        Tabledatabase.push_back(Tb);
    }
}

void Add_dish(list<Dish> &database, Table &table, int id, int soluong)
{
    bool count = 0;

    list<Dish>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).get_ID() == id)
        {
            (*it).set_SL(soluong);
            table.set_Tabledata(*it);
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da cap nhat xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
    cout<<"Da them sv"<<endl;
}

void Edit_gia_byID(list<Dish> &database, Table &table, int id)
{
    int soluong;
    bool count = 0;

    list<Dish>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).get_ID() == id)
        {
            cout<<"Nhap so luong: ";
            cin>>soluong;
            (*it).set_SL(soluong);
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da cap nhat xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void removebyID(list<Dish> &database, Table &table, int id)
{
    bool count = 0;
    list<Dish>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).get_ID() == id)
        {
            table.remove_Tabledata(*it);
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da xoa xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void get_infor(Dish &mon)
{
    cout <<" ID "<<" Ten Mon "<<" Gia "<<endl;
    cout <<mon.get_ID()<<"  "<<mon.get_TM()<<"  "<<mon.get_Gia()<<endl;
}

void Dish_list(Table &table)
{
    int num_dish = 0;
    cout<<"STT  ID  Ten mon  Gia   SL"<<endl; 
    for(Dish mon : table.get_Tabledata())
    {   
        cout<<" "<<num_dish<<"   "<<mon.get_ID()<<"   "<<mon.get_TM()<<"    "<<mon.get_Gia()<<"     "<<mon.get_SL()<<endl;
        num_dish++;
    }
}
int Bill(Table &table)
{
    int sum;
    for(Dish bill : table.get_Tabledata())
    {
        sum += bill.get_Gia();
    }
    return sum;
}