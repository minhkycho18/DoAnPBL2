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
    int numb1,numb2,temp;
    int dem=0;
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
    (this->tenphim.dssc+time)->ShowAisleMap();
    cout << "\n Vui Long Nhap Theo Cu Phap:\n";
    cout << "\n Vi Du: Ghe so 9, Day C : C9";
    cout << "\nNhap so ghe: " ; fflush(stdin); getline(cin,this->SoGhe);
    bool test = (int)this->SoGhe[0] <65 || (int)this->SoGhe[0] > 74;
    numb1 = (int)(this->SoGhe[0])-64;
    numb2 = (int)(this->SoGhe[1]-'0');
    while(test == 1  || this->SoGhe.length()!=2 || (this->tenphim.dssc+time)->checkAisle(numb1,numb2) == true ){
        if((this->tenphim.dssc+time)->checkAisle(numb1,numb2) == true)
        cout << "So Ghe nay da ton tai,Vui Long Nhap Lai:";
        else 
        cout << "Khong Hop Le,Vui Long Nhap Lai:";
        getline(cin,this->SoGhe);
        numb1 = (int)(this->SoGhe[0])-64;
        numb2 = (int)(this->SoGhe[1]-'0');
        test = (int)this->SoGhe[0] <65 || (int)this->SoGhe[0] > 74;
    }
    //-----convert string to int
    temp = numb1*10 + numb2;
    (this->tenphim.dssc+time)->addAisle(temp);
}
void vexemphim::output(){
    cout << "Suat Chieu: " << this->showtime << endl;
    cout << "So ghe: " << this->SoGhe << endl;
    this->tenphim.output();
    cout << "GiaVe: " << this->giatien << endl;
}


