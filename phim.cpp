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
string phim::getTenPhim(){
    return this->tenphim;
}
string phim::getTheLoai(){
    return this->theloai;
}
int phim::getThoiLuongPhim(){
    return this->thoiluongphim;
}

// -----------------------------------------------------------------

void phim::doc(ifstream& in){
    string ht,tl;
    int thoiluong;
	fflush(stdin);
	getline(in, ht);
	getline(in, tl);
	in >> thoiluong;
    char ss[5];
	in.getline( ss, 3 );  
	this->setTenPhim(ht);
	this->setTheLoai(tl);
	this->setThoiLuongPhim(thoiluong);
}
void phim::ghi(ofstream& o){
    o << getTenPhim() << endl;
    o << getTheLoai() << endl;
    o << getThoiLuongPhim() << endl;
}

// -----------------------------------------------------------------

void phim::input(){
    cin.ignore();
    cout << "Nhap Ten Phim: "; fflush(stdin); getline(cin, this->tenphim);
    cout << "Nhap The Loai: "; fflush(stdin); getline(cin, this->theloai);
    cout << "Nhap Thoi Luong Phim: " ; cin >> this->thoiluongphim;
}
void phim::output(){
    cout << "Ten Phim: " << this->tenphim << endl;
    cout << "The Loai: " << this->theloai << endl;
    cout << "Thoi Luong phim: " << this->thoiluongphim << endl;
}
