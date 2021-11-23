#include "KH_ThanhVien.h"
KH_ThanhVien::KH_ThanhVien()
{
}

KH_ThanhVien::~KH_ThanhVien()
{
}
// void KH_ThanhVien::TinhTien(){
//     int giatienbth = 75000;
//     for(int i=0; i< this->soluong; i++){
//         ve[i].setgiave(giatienbth);
//         this->tongtien += this->ve[i].getgiave();
//     }
// }
void KH_ThanhVien::input( phim& p){
    cin.ignore();
    this->LoaiKH = "binhthuong";
    this->giatv = 55000;
    Nguoi::input();
    cout << "Nhap Ngay Dat Ve: " << endl;
    ngaydatve.input();
    cout << "Nhap So Luong Ve Khach Mua: "; cin >> this->soluong;
        //ve = new Vemaybay[this->soluong];
    ve[this->soluong];
    for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input(p);
            ve[i].setgiave(this->giatv);
            this->tongtien += this->ve[i].getgiave();
        }
}