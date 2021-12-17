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
// -----------------------------------------------------------------


void khachhang::doc(ifstream& in){
    int sl,tongt;
    fflush(stdin); 
    Nguoi::doc(in);
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