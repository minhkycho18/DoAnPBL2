#include "KH_BinhThuong.h"
KH_BinhThuong::KH_BinhThuong()
{
}

KH_BinhThuong::~KH_BinhThuong()
{
}
// void KH_BinhThuong::TinhTien(){
//     int giatienbth = 75000;
//     for(int i=0; i< this->soluong; i++){
//         ve[i].setgiave(giatienbth);
//         this->tongtien += this->ve[i].getgiave();
//     }
// }
void KH_BinhThuong::input( phim& p){
    cin.ignore();
    Nguoi::input();
    cout << "Nhap Ngay Dat Ve: " << endl;
    ngaydatve.input();
    cout << "Nhap So Luong Ve Khach Mua: "; cin >> this->soluong;
        //ve = new Vemaybay[this->soluong];
    ve[this->soluong];
    for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input(p);
            ve[i].setgiave(this->giabth);
            this->tongtien += this->ve[i].getgiave();
        }
}