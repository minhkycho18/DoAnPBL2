#include "Nguoi.h"
Nguoi::Nguoi()
{
    this->Hoten =  "";
    this->tuoi = 0;
}
Nguoi::~Nguoi()
{
    this->Hoten =  "";
    this->tuoi = 0;
}
//----------------------------------------------------
void Nguoi::setHoten(string& s){
    this->Hoten = s;
}
void Nguoi::setTuoi(int& t){
    this->tuoi = t;
}
string Nguoi::getHoten(){
    return this->Hoten;
}
int Nguoi::getTuoi(){
    return this->tuoi;
}

//----------------------------------------------------------------

void Nguoi::doc(ifstream& in){
    string ht;
    int t;
    cout << this->tuoi;
    // fflush(stdin);
    getline(in,ht);
    in >> t;
    // char ss[5];
	// in.getline( ss, 3 ); 
    // this->setHoten(ht);
    // this->setTuoi(t);
}
void Nguoi::ghi(ofstream& o){
    o << getHoten() << endl;
    o << getTuoi() << endl;
}
void Nguoi::input()
{
    cin.ignore();
    cout << "Nhap Ho Ten: "; fflush(stdin); getline(cin, this->Hoten);
    cout << "Nhap Tuoi: "; cin >> this->tuoi;
}
void Nguoi::output()
{
    cout << "Ho Ten: " << this->Hoten << endl;      
    cout << "Tuoi: " << this->tuoi << endl;
}