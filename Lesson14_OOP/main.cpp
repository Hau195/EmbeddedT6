#include <iostream>
#include <string>

using namespace std;

class Doituong
{
    private:
        
        string TEN;
        int TUOI;
        string DIA_CHI;
    public:
    void themThongTin();
    void hienthi();
};

void Doituong::hienthi()
{
  cout<<"Ten: "<<TEN<<endl;
  cout<<"Tuoi: "<<TUOI<<endl;
  cout<<"Dia chi: "<<DIA_CHI<<endl;
}

void Doituong::themThongTin()
{

}

class SinhVien : public Doituong{
    private:
        int MSSV;
    public:
        SinhVien();
        int getMSSV();
        void themThongTin(string ten, int tuoi, string dia_chi);
        void hienthi();
};

