#include<iostream>
#include<string>


using namespace std;

typedef enum
{
    QUANLY,
    NHANVIEN
}Ctrinh;

typedef enum
{
    RETURN,
    SET_TABLENUM,
    ADD_DISH,
    EDIT_DISH,
    REMOVE_DISH,
    DISHES_LIST
}Quanly;

typedef enum
{
    TABLE_RETURN,
    ADD_TABLE_DISH,
    EDIT_TABLE_DISH,
    REMOVE_TABLE_DISH,
    DISHES_TABLE_LIST,
    BILL
}Nhanvien;
