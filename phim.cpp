#include "phim.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
phim::phim(){

}
phim::~phim(){

}
phim::phim(const phim& p){
    this->tenphim = p.tenphim;
    this->theloai = p.theloai;
    this->thoiluongphim = p.thoiluongphim;
}

// -----------------------------------------------------------------

void phim::setTenPhim(string& s){
    this->tenphim = s;
}
void phim::setTheLoai(string& s){
    this->theloai = s;
}
void phim::setThoiLuongPhim(int& a){
    this->thoiluongphim = a;
}
void phim::setSLSuat(int& a){
    this->SLSuat = a;
}
string phim::getTenPhim(){
    return this->tenphim;
}
string phim::getTheLoai(){
    return this->theloai;
}
int phim::getThoiLuongPhim(){
    return this->thoiluongphim;
}
int phim::getSLSuat(){
    return this->SLSuat;
}

// -----------------------------------------------------------------

void phim::doc(ifstream& in){
    string ht,tl;
    int thoiluong;
    int sl;
	fflush(stdin);
	getline(in, ht);
	getline(in, tl);
	in >> thoiluong;
    in >> sl;
    this->dssc = new SuatChieu[sl];
    for (int i = 0; i < sl; i++)
    {
    (this->dssc + i)->doc(in);
    } 
    
    char ss[5];
	in.getline( ss, 3 ); 
	this->setTenPhim(ht);
	this->setTheLoai(tl);
	this->setThoiLuongPhim(thoiluong);
    this->setSLSuat(sl);
}
void phim::ghi(ofstream& o){
    o << getTenPhim() << endl;
    o << getTheLoai() << endl;
    o << getThoiLuongPhim() << endl;
    o << getSLSuat() << endl;
    for (int i = 0; i < getSLSuat(); i++)
    {
        (this->dssc + i)->ghi(o);
    }
}

// -----------------------------------------------------------------

void phim::input(){
    cin.ignore();
    cout << "Nhap Ten Phim: "; fflush(stdin); getline(cin, this->tenphim);
    cout << "Nhap The Loai: "; fflush(stdin); getline(cin, this->theloai);
    cout << "Nhap Thoi Luong Phim: " ; cin >> this->thoiluongphim;
    cout << "Nhap So Luong Suat Chieu: " ; cin >> this->SLSuat;
    this->dssc = new SuatChieu[this->SLSuat];
    for (int i = 0; i < this->SLSuat; i++)
    {
        cout << i+1 << ". " ;
        (this->dssc + i)->input();
        cout << endl;
    }
    
}
void phim::output(){
    cout << "Ten Phim: " << this->tenphim << endl;
    cout << "The Loai: " << this->theloai << endl;
    cout << "Thoi Luong phim: " << this->thoiluongphim << endl;
    cout << "Suat Chieu : " ;
    for (int  i = 0; i < this->SLSuat; i++)
    {
        (this->dssc + 0)->output();
    }
    
}
