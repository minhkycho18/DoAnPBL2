#include "khachhang.h"
#include <iostream>
#include <fstream>
using namespace std;

khachhang::khachhang(){
    this->tongtien = 0;
}
khachhang::~khachhang(){

}
// -----------------------------------------------------------------


void khachhang::setsoluong(int& sl){
    this->soluong = sl;
}
void khachhang::setTongtien(int& tien){
    this->tongtien = tien;
}

int khachhang::getTongtien(){
    return this->tongtien;
}

int khachhang::getSoluong(){
    return this->soluong;
}
Date khachhang::getDate(){
    return this->ngaydatve;
}
// -----------------------------------------------------------------


void khachhang::doc(ifstream& in){
    int sl,tongt;
    fflush(stdin); 
    Nguoi::doc(in);
    this->ngaydatve.doc(in);
    in >> sl;
    char ss[5];
	in.getline( ss, 3 ); 
    for(int i=0;i<sl ; i++){
        this->ve[i].doc(in);
    }
    in >> tongt;
    this->setsoluong(sl);
    this->setTongtien(tongt);
}
// void khachhang::ghi(ofstream& o) {
//     Nguoi::ghi(o);
//     this->ngaydatve.ghi(o);
//     o << getSoluong() << endl;
//     for(int i=0;i< this->soluong ; i++){
//         this->ve[i].ghi(o);
//     }
//     o << getTongtien() << endl;
// }
// -----------------------------------------------------------------


// void khachhang::input(phim& p){
//     cin.ignore();
//     Nguoi::input();
//     cout << "Nhap Ngay Dat Ve: " << endl;
//     ngaydatve.input();
//     cout << "Nhap So Luong Ve Khach Mua: "; cin >> this->soluong;
//         //ve = new Vemaybay[this->soluong];
//     ve[this->soluong];
//     for (int i = 0; i < this->soluong; ++i)
//         {
//             ve[i].input(p);
//             // this->tongtien += this->ve[i].getgiave();
//         }
// }
// void khachhang::output(){
//     cout << "- Thong Tin Khach Hang: " << endl;
//     Nguoi::output();
//     cout << "Ngay dat ve: " << endl;
//     ngaydatve.output();
//     cout << "So Luong Ve Khach Da Mua: " <<  this->soluong << endl;
//         cout << "- Thong Tin Chuyen Bay: " << endl;
//         for (int i = 0; i < this->soluong; ++i)
//         {
//             ve[i].output();
//             cout << endl;
//         }
//         cout << "==> Tong Tien = " << this->tongtien;
//         cout << endl;
// }


// int giabth = 60000;