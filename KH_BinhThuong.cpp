#include "KH_BinhThuong.h"
#include <fstream>
KH_BinhThuong::KH_BinhThuong()
{
}

KH_BinhThuong::~KH_BinhThuong()
{
}
void KH_BinhThuong::setLoaiKH(string s){
    this->LoaiKH = s;
}
void KH_BinhThuong::setgia(int a){
    this->gia = a;
}
// void KH_BinhThuong::TinhTien(){
//     int giatienbth = 75000;
//     for(int i=0; i< this->soluong; i++){
//         ve[i].setgiave(giatienbth);
//         this->tongtien += this->ve[i].getgiave();
//     }
// }
void KH_BinhThuong::input( phim& p){
    this->setLoaiKH();
    this->setgia();
    Nguoi::input();
    cout << "Nhap Ngay Dat Ve: " << endl;
    ngaydatve.input();
    cout << "Nhap So Luong Ve Khach Mua: "; cin >> this->soluong;
        //ve = new Vemaybay[this->soluong];
    ve[this->soluong];
    for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input(p);
            ve[i].setgiave(this->gia);
            this->tongtien += this->ve[i].getgiave();
        }
}
void KH_BinhThuong::output(){
    cout << "- Thong Tin Khach Hang: " << endl;
    cout << "Loai Khach Hang: " << this->LoaiKH << endl;
    Nguoi::output();
    cout << "Ngay dat ve: " << endl;
    ngaydatve.output();
    cout << "So Luong Ve Khach Da Mua: " <<  this->soluong << endl;
        cout << "- Thong Tin Chuyen Bay: " << endl;
        for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].output();
            cout << endl;
        }
        cout << "==> Tong Tien = " << this->tongtien;
        cout << endl;
}
void KH_BinhThuong::ghi(ofstream& o) {
    o << this->LoaiKH << endl;
    Nguoi::ghi(o);
    this->ngaydatve.ghi(o);
    o << getSoluong() << endl;
    for(int i=0;i< this->soluong ; i++){
        this->ve[i].ghi(o);
    }
    o << getTongtien() << endl;
}

