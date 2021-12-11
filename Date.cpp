#include "Date.h"
#include <iostream>
#include <fstream>
using namespace std;
Date::Date(){

}
Date::~Date(){

}
// -----------------------------------------------------------------
void Date::setday(int& d){
    this->day = d;
}
void Date::setmonth(int& m){
    this->month = m;
}
void Date::setyear(int& y){
    this->year = y;
}
int Date::getday(){
    return this->day;
}
int Date::getmonth(){
    return this->month;
}
int Date::getyear(){
    return this->year;
}
// -----------------------------------------------------------------
void Date::doc(ifstream& in){
    int d,m,y;
	// fflush(stdin);
	in >> d;
    in >> m;
    in >> y;
	this->setday(d);
	this->setmonth(m);
    this->setyear(y);
}
void Date::ghi(ofstream& o){
    o << getday() << endl;
    o << getmonth() << endl;
    o << getyear() << endl;
}
// -----------------------------------------------------------------
void Date::input(){
    cout << "Nhap Ngay: ";
    cin >> this->day;
    while(this->day >31 || this->day <=0){
        cout << "Vui Long Nhap Lai:";
        cin >> this->day;
    }
    cout << "Nhap Thang: ";
    cin >> this->month;
    while(this->month >12 || this->month <=0){
        cout << "Vui Long Nhap Lai:";
        cin >> this->month;
    }
    cout << "Nhap Nam: ";
    cin >> this->year;
}
void Date::output(){
     cout << "Ngay/Thang/Nam: " << this->day << "/" << this->month << "/" << this->year << endl;
}