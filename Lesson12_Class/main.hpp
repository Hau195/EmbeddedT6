#include <iostream>
#include <string>

using namespace std;

class DoiTuong{
    private:
        string Ten;
        int Tuoi;
        string Gioitinh;
        int ID;
        int *ptr;

    public:
        DoiTuong();
        DoiTuong(string ten, int tuoi, string gioitinh);
        ~DoiTuong();

        void nhapThongTin(string ten, int tuoi, string gioitinh);
        void hienthi();
        int var;
        static int static_var;
};