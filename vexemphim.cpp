#include "vexemphim.h"
#include <fstream>

vexemphim::vexemphim(){

}
vexemphim::~vexemphim(){
    
}
// -----------------------------------------------------------------
void vexemphim::setSoghe(string& s){
    this->SoGhe = s;
}
void vexemphim::setgiave( int& gt){
    this->giatien = gt;
}
string vexemphim::getSoghe(){
    return this->SoGhe;
}
int vexemphim::getgiave(){
    return this->giatien;
}

// -----------------------------------------------------------------

void vexemphim::doc(ifstream& in){
    string sg;
    int gia;
    // fflush(stdin);
    getline(in,sg);
    this->tenphim.docKH(in);
    in >> gia;
    // char ss[5];
	// in.getline( ss, 3 ); 
    this->setSoghe(sg);
    this->setgiave(gia);
}
void vexemphim::ghi(ofstream& o){
    o << getSoghe() << endl;
    this->tenphim.ghiKH(o);
    o << getgiave() << endl;
}

// -----------------------------------------------------------------

void vexemphim::input(phim& p){
    this->tenphim = p;
    cout << "Nhap so ghe" ; fflush(stdin); getline(cin,this->SoGhe);
}
void vexemphim::output(){
    cout << "So ghe: " << this->SoGhe << endl;
    this->tenphim.output();
    cout << "GiaVe: " << this->giatien << endl;
}


