#include "SuatChieu.h"

SuatChieu::SuatChieu()
{
    this->ListSelected[96];
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
	getline(in, t);
    this->setTime(t);	
}
void SuatChieu::ghi(ofstream& o){
    o << getTime() << endl;
    
}
void SuatChieu::input(){
    
    fflush(stdin); getline(cin,this->time);
}
void SuatChieu::output(){
    cout << getTime() << ", "; 
}
bool SuatChieu::checkAisle(int& r, int& c){
    int pos = r*10 +c;
    for(int i=0 ; i< this->col*this->row;i++){
        if(pos == this->ListSelected[i]){
            return true;
        } 
    }
    return false;
}
void SuatChieu::ShowAisleMap(){
    char avail= 'O';
    char unavail = 'X';
    cout << "\t";
    for(int i=1 ; i <= this->col ; i++){
        if(i==3 || i==10){
            cout << setw(9) << i;
        } else {
            cout<< setw(5) << i;
        }       
    }
    cout << "\n\n";
    for(int i=1 ;i <= this-> row; i++){
        char temp = 'A';
        temp = temp+i-1;
        cout << temp << "\t";
        for(int j=1;j<= this->col;j++){
            if(checkAisle(i,j)){
                if(j==3 || j==10){
                    cout << setw(9)<<  unavail;
                } else {
                    cout << setw(5) << unavail;        
                }
            } else {
                if(j==3 || j==10){
                    cout << setw(9)<<  avail;
                } else {
                    cout << setw(5) << avail;        
                }
            }
        }
        cout << "\n\n";
    }
}
