#include "main.hpp"
#include "Table.hpp"

Ctrinh CT;
Quanly QL;
Nhanvien NV;

void Quan_ly(list<Table> &table, list <Dish> &database, int &selection)
{
    int select;
    static int table_num = 0;
    int add_select = 0;
    bool count = 0;

    cout<<"Quan ly"<<endl;
    cout<<"1. Set table number"<<endl;
    cout<<"2. Add dish"<<endl;
    cout<<"3. Edit dish"<<endl;
    cout<<"4. Remove dish"<<endl;
    cout<<"5. Dished list"<<endl;
    cout<<"0. Return"<<endl;
    cout<<"Please select program..."<<endl;

    cin>>select;
    QL = Quanly(select);

    switch(QL)
    {
        case RETURN:
            selection = 0;
        break;
        case SET_TABLENUM:
            cout<<"Nhap so ban: ";
            cin>>table_num;

            Set_numofTables(table, table_num);

        break;
        case ADD_DISH:
            while(add_select != 2)
            {
                switch(add_select)
                {
                    case 0:
                        cout<<"Them mon"<<endl;
                        cout<<"Thong tin mon\n"<<endl;
                        Dish_list(database);
                        cout<<"-----------\n"<<endl;
                        cout<<"1. Them mon moi"<<endl;
                        cout<<"2. Quay lai"<<endl;
                        cout<<"Vui long chon CT..."<<endl;

                        cin>>add_select;
                    break;
                    case 1:
                        Add_dish(database);
                        add_select = 0;
                    break;
                }
            }
        break;
        case EDIT_DISH:
            
            while(add_select != 2)
            {
                switch(add_select)
                {
                    case 0:
                        cout<<"Sua mon"<<endl;
                        cout<<"Thong tin mon"<<endl;
                        Dish_list(database);
                        cout<<"-----------"<<endl;
                        int id;
                        cout<<"Moi nhap ID: ";
                        cin>>id;
                        add_select = 3;
                    case 3:
                        for(Dish mon : database)
                        {
                            if(mon.get_ID() == id)
                            {
                                get_infor(mon);
                                count = 1;
                            }
                        }
                        if(count != 0)
                        {}else{cout<<"Khong tim thay ID"<<endl;}
                        cout<<"1. Thay doi gia"<<endl;
                        cout<<"2. Quay lai"<<endl;
                        cout<<"Vui long chon CT..."<<endl;
                        cin>>add_select;
                    break;
                    case 1:
                        Edit_gia_byID(database, id);
                        cout<<"0. Thay doi gia"<<endl;
                        cout<<"2. Quay lai"<<endl;
                        cin>>add_select;
                    break;
                }
            }
            
        break;
        case REMOVE_DISH:
            while(add_select != 2)
            {
                switch(add_select)
                {
                    case 0:
                        cout<<"Xoa mon"<<endl;
                        cout<<"Danh sach mon"<<endl;
                        Dish_list(database);
                        cout<<"-----------"<<endl;
                        int id;
                        cout<<"Moi nhap ID de xoa: ";
                        cin>>id;
                        add_select = 3;
                    case 3:
                        for(Dish mon : database)
                        {
                            if(mon.get_ID() == id)
                            {
                                get_infor(mon);
                                count = 1;
                            }
                        }
                        if(count != 0)
                        {}else{cout<<"Khong tim thay ID"<<endl;}
                        cout<<"1. Xac nhan xoa mon"<<endl;
                        cout<<"2. Quay lai"<<endl;
                        cout<<"Vui long chon CT..."<<endl;
                        cin>>add_select;
                    case 1:
                        removebyID(database, id);
                        add_select = 0;
                }
            }
            break;
        break;
        case DISHES_LIST:
            Dish_list(database);
        break;
        default:
        break;
    }
}

void Nhan_vien(list<Table> &table_list, list <Dish> &database, int &selection)
{
    
    if(table_list.size() == 0)
    {
        selection = 0;
        
    }
    int tb;
    cout<<"So ban:    ";
    for(int i = 0; i < table_list.size(); i++)
    {
        if(i == table_list.size()-1)
        {
            cout<<" "<< i+1 <<endl;
            break;
        }
        cout<<" "<< i+1;
        
    }
    
    cout<<"Trang thai:";
    for(Table tb : table_list)
    {
        cout<<" "<< tb.get_status();
    }
    cout<<""<<endl;
    cout<<"Please select table..."<<endl;
    cin>>tb;



    list<Table>::iterator it_tb;
    for(it_tb = table_list.begin(); it_tb != table_list.end(); it_tb++)
    {
        if((*it_tb).get_TABLE_NUM() == tb)
        {
            int select;
            int add_select = 0;
            bool count = 0;
            
            cout<<"Ban: "<<tb<<endl;
            cout<<"1. Add dish"<<endl;
            cout<<"2. Edit dish"<<endl;
            cout<<"3. Remove dish"<<endl;
            cout<<"4. Dishes list"<<endl;
            cout<<"5. Bill"<<endl;
            cout<<"0. Return"<<endl;
            cout<<"Please select program..."<<endl;

            cin>>select;
            NV = Nhanvien(select);

            switch(NV)
            {
                case RETURN:
                    selection = 0;
                break;
                case ADD_TABLE_DISH:
                    (*it_tb).set_status(true);
                    while(add_select != 2)
                    {
                        switch(add_select)
                        {
                            case 0:
                                cout<<"Them mon"<<endl;
                                cout<<"DS mon"<<endl;
                                Dish_list(database);
                                cout<<"-----------\n"<<endl;
                                
                                cout<<"1. Them mon moi"<<endl;
                                cout<<"2. Quay lai"<<endl;
                                cout<<"Vui long chon CT..."<<endl;
                                cin>>add_select;
                            break;
                            case 1:
                                cout<<"Them mon"<<endl;
                                cout<<"DS mon"<<endl;
                                Dish_list(database);
                                cout<<"-----------\n"<<endl;
                                int id;
                                cout<<"Moi nhap ID: ";
                                cin>>id;
                                get_infor(database, id);

                                int soluong;
                                cout<<"Moi nhap so luong: ";
                                cin>>soluong;    
                                add_select = 4;
                            case 4:
                                Add_dish(database, (*it_tb), id, soluong);
                                add_select = 3;
                            break;
                            case 3:

                                cout<<"Them mon"<<endl;
                                cout<<"DS mon"<<endl;
                                Dish_list(database);
                                cout<<"-----------"<<endl;
                                cout<<"DS mon tai ban"<<endl;
                                Dish_list((*it_tb));
                                cout<<"-----------"<<endl;

                                cout<<"1. Goi them mon"<<endl;
                                cout<<"2. Quay lai"<<endl;
                                cout<<"Vui long chon CT..."<<endl;
                                cin>>add_select;
                            break;
                        }
                    }
                break;
                case EDIT_TABLE_DISH:
                    
                    while(add_select != 2)
                    {
                        switch(add_select)
                        {
                            case 0:
                                cout<<"Sua mon"<<endl;
                                cout<<"DS mon tai ban"<<endl;
                                Dish_list((*it_tb));
                                cout<<"-----------"<<endl;

                                cout<<"1. Sua mon"<<endl;
                                cout<<"2. Quay lai"<<endl;
                                cout<<"Vui long chon CT..."<<endl;
                                cin>>add_select;
                            case 1:
                                cout<<"DS mon tai ban"<<endl;
                                Dish_list((*it_tb));
                                cout<<"-----------"<<endl;
                                int id;
                                cout<<"Moi nhap ID: ";
                                cin>>id;
                                Edit_gia_byID(database, (*it_tb),id);
                                add_select = 0;
                            break;
                        }
                    }
                    
                break;
                case REMOVE_TABLE_DISH:
                    while(add_select != 2)
                    {
                        switch(add_select)
                        {
                            case 0:
                                cout<<"Xoa mon"<<endl;
                                cout<<"Danh sach mon"<<endl;
                                Dish_list(database);
                                cout<<"-----------"<<endl;
                                int id;
                                cout<<"1. Xoa mon"<<endl;
                                cout<<"2. Quay lai"<<endl;
                                cin>>add_select;
                            case 1:
                                cout<<"Moi nhap ID de xoa: ";
                                cin>>id;
                                get_infor(database, id);
                                cout<<"3. Xac nhan xoa"<<endl;
                                cin>>add_select;
                            case 3:
                                removebyID(database, id);
                                add_select = 0;
                        }
                    }
                    break;
                break;
                case DISHES_TABLE_LIST:
                    Dish_list((*it_tb));
                break;
                case BILL:
                    while(add_select != 2)
                    {
                        switch(add_select)
                        {
                            case 0:
                                cout<<"Thanh toan"<<endl;
                                cout<<"Danh sach mon tai ban"<<endl;
                                Dish_list((*it_tb));
                                cout<<"-----------"<<endl;
                                cout<<"Tong thanh toan: "<< Bill((*it_tb));

                                cout<<"1. Thanh toan"<<endl;
                                cout<<"2. Quay lai"<<endl;
                                cin>>add_select;
                            case 1: 
                                cout<<"Da thanh toan"<<endl;
                                (*it_tb).set_status(false);
                                add_select = 2;
                        }
                    }
                break;
                default:
                break;
            }
        }
    }



    
}

// void Chuong_trinh_chinh()
// {
//     switch(CT)
//     {
//         case QUANLY:
//             Quan_ly();
//         break;
//         case NHANVIEN:
//             Nhan_vien();
//         break;
//         default:
//         break;
//     }   
// }

int main(int argc, char const *argv[])
{
    list <Dish> database;

    Dish Ga("Ga", 10);
    Dish Vit("Vit", 15);
    Dish Heo("Heo", 100);
    Dish Bo("Bo", 1000);
    database.push_back(Ga);
    database.push_back(Vit);
    database.push_back(Heo);
    database.push_back(Bo);

    list <Table> table_database;
    int selection = 0;
    while(selection != 3)
    {
        switch(selection)
        {
            case 0:
                cout<<"Chuong trinh chinh\n 1. Quan ly\n 2. Nhan vien\n 3. Dung CT\n Moi chon CT...\n";
                cin>>selection;
            break;
            case 1:
                Quan_ly(table_database, database, selection);
            break;
            case 2:
                Nhan_vien(table_database, database, selection);
            break;
        }

    }
}