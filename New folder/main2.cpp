// Quan ly dat ve xem phim
// Them phim moi
// Danh sach phim
// Dat ve cho mot phim
// Kiem tra suc chua rap phim

#include <string>
#include <vector>
using namespace std;

enum class LoaiPhong{
    LOAI_THUONG,
    LOAI_TRUNG,
    LOAI_VIP
};

class Phim{
    public:
        Phim(string ten, LoaiPhong loai);
        string getTen();
        LoaiPhong getLoaiPhong();
        int getSoVeDaDat();
        int getSoVeConLai();
        bool datVe(int soLuong);
    private:
        string ten;
        LoaiPhong loai;
        int soVeDaDat;
        int getMaxSoVe();
};

Phim:Phim(string ten, LoaiPhong loai) : ten(ten), loai(loai), soVeDaDat(0) {}

string Phim::getTen(){
    return ten;
}

LoaiPhong Phim::getLoaiPhong(){
    return loai;
}

int Phim::getSoVeDaDat(){
    return soVeDaDat;
}

int Phim::getSoVeConLai(){
    return getMaxSoVe() - soVeDaDat();
}

bool Phim::datVe(int soLuong){
    if(soLuong <= 0 || soLuong > getSoVeConLai()){
        return false;
    }

    soVeDaDat += soLuong;
    return true;
}

int Phim::getMaxSoVe(){
    switch (loai)
    {
    case LoaiPhong::LOAI_THUONG:
        return 50;
        break;
    case LoaiPhong::LOAI_TRUNG:
        return 100;
        break;
    case LoaiPhong::LOAI_VIP:
        return 150;
        break;
    default:
        return 0;
        break;
    }
}