#include "khachhang.h"
#include <iostream>
#include <fstream>
using namespace std;

khachhang::khachhang(){

}
khachhang::~khachhang(){

}
// -----------------------------------------------------------------
void khachhang::setHoten(string& s){
    this->Hoten = s;
}
void khachhang::setTuoi(int& t){
    this->tuoi = t;
}
void khachhang::setsoluong(int& sl){
    this->soluong = sl;
}
void khachhang::setTongtien(int& tien){
    this->tongtien = tien;
}
string khachhang::getHoten(){
    return this->Hoten;
}
int khachhang::getTuoi(){
    return this->tuoi;
}
int khachhang::getSoluong(){
    return this->soluong;
}
int khachhang::getTongtien(){
    return this->tongtien;
}
// -----------------------------------------------------------------


void khachhang::doc(ifstream& in){
    string ht;
    int t,sl,tongt;
    fflush(stdin);
    getline(in,ht);
    in >> t;
    this->ngaydatve.doc(in);
    in >> sl;
    for(int i=0;i<sl ; i++){
        this->ve[i].doc(in);
    }
    in >> tongt;
    char ss[5];
	in.getline( ss, 3 ); 
    this->setHoten(ht);
    this->setTuoi(t);
    this->setsoluong(sl);
    this->setTongtien(tongt);
}
void khachhang::ghi(ofstream& o) {
    o << getHoten() << endl;
    o << getTuoi() << endl;
    this->ngaydatve.ghi(o);
    o << getSoluong() << endl;
    for(int i=0;i< this->soluong ; i++){
        this->ve[i].ghi(o);
    }
    o << getTongtien() << endl;
}
// -----------------------------------------------------------------


void khachhang::input(phim& p){
    cin.ignore();
    cout << "Nhap Ho Ten: "; fflush(stdin); getline(cin, this->Hoten);
    cout << "Nhap Tuoi: "; cin >> this->tuoi;
    cout << "Nhap Ngay Dat Ve: " << endl;
    ngaydatve.input();
    cout << "Nhap So Luong Ve Khach Mua: "; cin >> this->soluong;
        //ve = new Vemaybay[this->soluong];
    ve[this->soluong];
    for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input(p);
            this->tongtien += this->ve[i].getgiave();
        }
}
void khachhang::output(){
    cout << "- Thong Tin Khach Hang: " << endl;
    cout << "Ho Ten: " << this->Hoten << endl;
    cout << "Tuoi: " << this->tuoi << endl;
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