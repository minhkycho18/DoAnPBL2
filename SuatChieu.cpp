#include "SuatChieu.h"
SuatChieu::SuatChieu()
{
}

SuatChieu::~SuatChieu()
{
}
void SuatChieu::setTime(string& s){
    this->time = s;
}
string SuatChieu::getTime(){
    return this->time;
}
void SuatChieu::doc(ifstream& in){
    string t;
	fflush(stdin);
	getline(in, t);
    this->setTime(t);  	
}
void SuatChieu::ghi(ofstream& o){
    o << getTime() << endl;
    
}
void SuatChieu::input(){
    cin.ignore();
    fflush(stdin); getline(cin,this->time);
}
void SuatChieu::output(){
    cout << this->time << ", "; 
}
