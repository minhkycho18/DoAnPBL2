#include "vexemphim.h"
#include <fstream>

vexemphim::vexemphim(){

}
vexemphim::~vexemphim(){
    
}
// -----------------------------------------------------------------
void vexemphim::setShowtime(string& s){
    this->showtime = s;
}
string vexemphim::getShowtime(){
    return this->showtime;
}
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
    string sg,sc;
    int gia;
    // fflush(stdin);
    getline(in,sc);
    getline(in,sg);
    this->tenphim.docKH(in);
    in >> gia;
    char ss[5];
	in.getline( ss, 3 );
    this->setShowtime(sc); 
    this->setSoghe(sg);
    this->setgiave(gia);
}
void vexemphim::ghi(ofstream& o){
    o << getShowtime() << endl;
    o << getSoghe() << endl;
    this->tenphim.ghiKH(o);
    o << getgiave() << endl;
}

// -----------------------------------------------------------------

void vexemphim::input(phim& p){
    int time;
    this->tenphim = p;
    cout << "Chon Suat Chieu:\n";
    cout << "==============="<< this->tenphim.getTenPhim() << "===============" << endl;
    this->tenphim.Showtimes();
    cout << "==========================================================\n";
    cout << "Nhap Lua Chon " << "(<" << this->tenphim.getSLSuat()-1 <<"): " ;
    cin >> time;
    while(time >= this->tenphim.getSLSuat()){
        cout << "Vui Long Nhap Lai: ";
        cin >> time;
    }
    this->showtime = (this->tenphim.dssc+time)->getTime();
    cout << "Nhap so ghe: " ; fflush(stdin); getline(cin,this->SoGhe);
}
void vexemphim::output(){
    cout << "Suat Chieu: " << this->showtime << endl;
    cout << "So ghe: " << this->SoGhe << endl;
    this->tenphim.output();
    cout << "GiaVe: " << this->giatien << endl;
}


