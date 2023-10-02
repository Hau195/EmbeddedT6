#include <iostream>
#include <string>
#include <list>

using namespace std;

typedef enum
{
    NAM,
    NU
}Gioi_tinh;

typedef enum
{
    GIOI,
    KHA,
    TB,
    YEU

}Hoc_luc;


class SinhVien
{
    private:
        int ID;
        string TEN;
        int TUOI;
        Gioi_tinh GT;
        double DIEM_TOAN;
        double DIEM_LY;
        double DIEM_HOA;
        double DIEM_TB;
        Hoc_luc HOC_LUC;
    public:
        SinhVien()
        {
            ID = 1;
            TEN = "H";
            TUOI = 22;
            GT = NAM;
            DIEM_TOAN = 5;
            DIEM_LY = 5;
            DIEM_HOA = 5;
        }
        SinhVien(string TEN, int TUOI, Gioi_tinh GT, int DIEM_TOAN, int DIEM_LY, int DIEM_HOA);
    
        int getID();
        void setID(int ID);
        string getTen();
        void setTen(string Ten);
        int getTuoi();
        void setTuoi(int Tuoi);
        Gioi_tinh getGT();
        void setGT(Gioi_tinh Gioitinh);
        double getDiemToan();
        void setDiemToan(double diemtoan);
        double getDiemLy();
        void setDiemLy(double diemly);   
        double getDiemHoa();
        void setDiemHoa(double diemhoa);
        double get_DTB();
        Hoc_luc get_HocLuc(); 
};

SinhVien::SinhVien(string TEN, int TUOI, Gioi_tinh GT, int DIEM_TOAN, int DIEM_LY, int DIEM_HOA)
{
    static int id = 1000;
    ID = id;
    id++;

    this->TEN = TEN;
    this->TUOI = TUOI;
    this->GT = GT;
    this->DIEM_TOAN = DIEM_TOAN;
    this->DIEM_LY = DIEM_LY;
    this->DIEM_HOA = DIEM_HOA;
}
int SinhVien::getID()
{
    return ID;
}
void SinhVien::setID(int id)
{
    ID = id;
}
string SinhVien::getTen()
{
    return TEN;
}
void SinhVien::setTen(string Ten)
{
    TEN = Ten;
}
int SinhVien::getTuoi()
{
    return TUOI;
}
void SinhVien::setTuoi(int Tuoi)
{
    TUOI = Tuoi;
}
Gioi_tinh SinhVien::getGT()
{
    return GT;
}
void SinhVien::setGT(Gioi_tinh Gioitinh)
{
    GT = Gioitinh;
}
double SinhVien::getDiemToan()
{
    return DIEM_TOAN;
}
void SinhVien::setDiemToan(double diemtoan)
{
    DIEM_TOAN = diemtoan;
}
double SinhVien::getDiemLy()
{
    return DIEM_LY;
}
void SinhVien::setDiemLy(double diemly)
{
    DIEM_LY = diemly;
}   
double SinhVien::getDiemHoa()
{
    return DIEM_HOA;
}
void SinhVien::setDiemHoa(double diemhoa)
{
    DIEM_HOA = diemhoa;
}
double SinhVien::get_DTB()
{
    DIEM_TB = (DIEM_HOA + DIEM_LY + DIEM_TOAN)/3;
    return DIEM_TB;
}
Hoc_luc SinhVien::get_HocLuc()
{   
    if(get_DTB() >= 8)
    {
        HOC_LUC = GIOI;
    }
    else if(get_DTB() >= 6 && get_DTB() < 8)
    {
        HOC_LUC = KHA;
    }
    else if(get_DTB() >= 5 && get_DTB() < 6)
    {
        HOC_LUC = TB;
    }
    else if(get_DTB() < 5)
    {
        HOC_LUC = YEU;
    }
    return HOC_LUC;
}    

void get_infor(SinhVien &sv)
{
    cout <<"ID: "<<sv.getID()<<"  ";
    cout <<"Ten: "<<sv.getTen()<<"  ";
    cout <<"Tuoi: "<<sv.getTuoi()<<"  ";
    cout <<"Gioi tinh: "<<sv.getGT()<<"  ";
    cout <<"Diem Toan: "<<sv.getDiemToan()<<"  ";
    cout <<"Diem Hoa: "<<sv.getDiemHoa()<<"  ";
    cout <<"Diem Ly: "<<sv.getDiemLy()<<"  ";
    cout <<"Diem TB: "<<sv.get_DTB()<<"  ";
    cout <<"Hoc luc: "<<sv.get_HocLuc()<<endl;
}

void themSinhVien(list<SinhVien> &database)
{
    int ID;
    string TEN;
    int TUOI;
    Gioi_tinh GT;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;
    int gioitinh;

    cout<<"Nhap Ten SV: ";
    cin>>TEN;
    cout<<"Nhap tuoi SV: ";
    cin>>TUOI;
    cout<<"Nhap gioi tinh: ";
    cin>>gioitinh;
    cout<<"Nhap diem toan: ";
    cin>>DIEM_TOAN;
    cout<<"Nhap diem ly: ";
    cin>>DIEM_LY;
    cout<<"Nhap diem hoa: ";
    cin>>DIEM_HOA;

    GT = Gioi_tinh(gioitinh);
    SinhVien sv(TEN, TUOI, GT, DIEM_TOAN, DIEM_LY, DIEM_HOA);
    database.push_back(sv);
    cout<<"Da them sv"<<endl;
}

void CapnhapSV_boiID(list<SinhVien> &database)
{
    int id;
    cout<<"Moi nhap ID";
    cin>>id;

    int ID;
    string TEN;
    int TUOI;
    Gioi_tinh GT;
    double DIEM_TOAN;
    double DIEM_LY;
    double DIEM_HOA;
    bool count = 0;

    for(SinhVien sv : database)
    {
        if(sv.getID() == id)
        {
            cout<<"Nhap Ten SV: ";
            cin>>TEN;
            sv.setTen(TEN);
            cout<<"Nhap tuoi SV: ";
            cin>>TUOI;
            sv.setTuoi(TUOI);
            cout<<"Nhap gioi tinh: ";
            int gioitinh;
            cin>>gioitinh;
            GT = Gioi_tinh(gioitinh);
            sv.setGT(GT);
            cout<<"Nhap diem toan: ";
            cin>>DIEM_TOAN;
            sv.setDiemToan(DIEM_TOAN);
            cout<<"Nhap diem ly: ";
            cin>>DIEM_LY;
            sv.setDiemLy(DIEM_LY);
            cout<<"Nhap diem hoa: ";
            cin>>DIEM_HOA;
            sv.setDiemHoa(DIEM_HOA);
            count = 1;
        }
    }
    if(count != 0)
    {
        cout<<"Da cap nhat xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void xoaSV_boiID(list<SinhVien> &database)
{
    int id;
    cout<<"Moi nhap ID";
    cin>>id;

    bool count = 0;
    list<SinhVien>::iterator it;
    for(it = database.begin(); it != database.end(); it++)
    {
        if((*it).getID() == id)
        {
            database.erase(it);
            count = 1;;
        }
    }
    if(count != 0)
    {
        cout<<"Da xoa xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}
}

void timkiem_theoTen(list<SinhVien> &database)
{
    string ten;
    cout<<"Moi nhap ten";
    cin>>ten;

    bool count = 0;

    for(SinhVien sv : database)
    {
        if(sv.getTen() == string(ten))
        {
            get_infor(sv);
            count = 1;;
        }
    }
    if(count != 0)
    {
        cout<<"Da xoa xong"<<endl;
    }else{cout<<"Khong tim thay ID"<<endl;}

}

bool compare_string(string arr1, string arr2)
{
    int i = 0;
    while(1)
    {
        if(arr1[i] > arr2[i])
        {
            return true;
        }else if(arr1[i] < arr2[i]){
            return false;
        }
        if(arr1[i] == '\0')
        {
            return true;
        }
        i++;
    }
}

void sapxep_theoDTB(list<SinhVien> &database)
{
    list<SinhVien>::iterator it;
    list<SinhVien>::iterator it2;

    SinhVien sv;

    for(it = database.begin(); it != database.end(); it++)
    {
        for(it2 = next(it,1); it2 != database.end(); it2++)
        {
            if((*it).get_DTB() > (*(it2)).get_DTB())
            {
                sv = *it;
                *it = *(it2);
                *(it2) = sv;
                cout<<(*it).get_DTB()<<endl;
                cout<<(*it2).get_DTB()<<endl;
            }
            
        }
    }
    cout<<"Done";
}

void sapxep_theoTen(list<SinhVien> &database)
{
    list<SinhVien>::iterator it;
    list<SinhVien>::iterator it2;

    SinhVien sv;

    for(it = database.begin(); it != database.end(); it++)
    {
        for(it2 = next(it,1); it2 != database.end(); it2++)
        {
            if(compare_string((*it).getTen(), (*(it2)).getTen()))
            {
                sv = *it;
                *it = *(it2);
                *(it2) = sv;
                cout<<(*it).get_DTB()<<endl;
                cout<<(*it2).get_DTB()<<endl;
            }
            
        }
    }
    cout<<"Done";
}

void hienthi_DSSV(list<SinhVien> &database)
{
    for(SinhVien sv : database)
    {
        get_infor(sv);
    }
}

int main(int argc, char const *argv[])
{
    list <SinhVien> database;
    int selection = 0;
    while(selection != 8)
    {
        cout<<"Moi chon tac vu\n 1. Them SV\n 2. Cap nhat SV theo ID\n 3. xoa SV theo ID\n 4. tim kiem theo ten\n 5. sap xep theo DTB\n 6. sap xep theo ten\n 7. Hien thi DSSV\n 8.Stop\n";
        cin>>selection;
        switch(selection)
        {
            case 1:
                themSinhVien(database);
                selection = 0;
                break;
            case 2:
                CapnhapSV_boiID(database);
                selection = 0;
                break;
            case 3:
                xoaSV_boiID(database);
               selection = 0;
                break;
            case 4:
                timkiem_theoTen(database);
                selection = 0;
                break;
            case 5:
                sapxep_theoDTB(database);
                selection = 0;
                break;
            case 6:
                sapxep_theoTen(database);
                selection = 0;
                break;
            case 7:
                hienthi_DSSV(database);
                selection = 0;
                break;        
        }
    }
    return 0;
}
