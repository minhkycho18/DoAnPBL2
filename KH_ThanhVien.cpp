#include "KH_ThanhVien.h"
KH_ThanhVien::KH_ThanhVien()
{
}

KH_ThanhVien::~KH_ThanhVien()
{
}
void KH_ThanhVien::setLoaiKH(string s){
    this->LoaiKH = s;
}
void KH_ThanhVien::setgia(int a){
    this->gia = a;
}
void KH_ThanhVien::input( phim& p){
    this->setLoaiKH();
    this->setgia();
    Nguoi::input();
    cout << "Nhap So Luong Ve Khach Mua: "; cin >> this->soluong;
    ve[this->soluong];
    for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input(p);
            ve[i].setgiave(this->gia);
            this->tongtien += this->ve[i].getgiave();
        }
}

void KH_ThanhVien::output(){
    cout << "- Thong Tin Khach Hang: " << endl;
    cout << "Loai Khach Hang: " << "Khach Hang Thanh Vien" << endl;
    Nguoi::output();
    cout << "So Luong Ve Khach Da Mua: " <<  this->soluong << endl;
        for (int i = 0; i < this->soluong; ++i)
        {
            this->ve[i].output();
            cout << endl;
        }
        cout << "==> Tong Tien = " << this->tongtien;
        cout << endl;
}
void KH_ThanhVien::ghi(ofstream& o) {
    o << this->LoaiKH << endl;
    Nguoi::ghi(o);
    o << getSoluong() << endl;
    for(int i=0;i< this->soluong ; i++){
        this->ve[i].ghi(o);
    }
    o << getTongtien() << endl;
}