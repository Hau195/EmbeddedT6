#include <iostream>
#include <string>
#include "main.hpp"

using namespace std;

DoiTuong::DoiTuong()
    {
        Ten = "Tuan";
        Tuoi = 16;
        Gioitinh = "Nam";
    }

DoiTuong::DoiTuong(string ten, int tuoi, string gioitinh)
    {
        static int id = 100;
        ID = id;
        id++;

        Ten = ten;
        Tuoi = tuoi;
        Gioitinh = gioitinh;
    }
DoiTuong::~DoiTuong()
    {
        //*ptr = 100;
        cout<<"Ten: "<<Ten<<endl;
    }

void DoiTuong::nhapThongTin(string ten, int tuoi, string gioitinh)
    {
        Ten = ten;
        Tuoi = tuoi;
        Gioitinh = gioitinh;
    }

void DoiTuong::hienthi()
    {
        cout<<"ID: "<<ID<<endl;
        cout<<"Ten: "<<Ten<<endl;
        cout<<"Tuoi: "<<Tuoi<<endl;
        cout<<"Sex: "<<Gioitinh<<endl;
    }
int DoiTuong::static_var;

void test1()
{
    DoiTuong dt("Hau", 22, "Nam");
    dt.hienthi();
    DoiTuong dt1("Ngoc", 21, "Nu");
    dt1.hienthi();
    DoiTuong dt2("Tuyet", 20, "Nu");
    dt2.hienthi();

}
void test2()
{
    DoiTuong dt("Ly", 22, "Nam");
    dt.hienthi();
    DoiTuong dt1("Oanh", 19, "Nam");
    dt1.hienthi();
    DoiTuong dt2("Nga", 21, "Nu");
    dt2.hienthi();
}

int main(int argc, char const *argv[])
{
    DoiTuong dt, dt1, dt2;

    printf("var = %p\n", &dt.var);
    printf("var = %p\n", &dt1.var);
    printf("var = %p\n", &dt2.var);

    printf("stvar = %p\n", &dt.static_var);
    printf("stvar = %p\n", &dt1.static_var);
    printf("stvar = %p\n", &dt2.static_var);

    // test1();
    // test2();

    //DoiTuong dt("Hau", 22, "Nam"), dt2("Ly", 19, "Nu");
    //dt.nhapThongTin("Hoang", 17, "Nam");
    // dt.hienthi();
    // dt2.hienthi();

    return 0;
}