#include "SuatChieu.h"
SuatChieu::SuatChieu()
{
    this->ListSelected[96];
    this->count = 0;
}

SuatChieu::~SuatChieu()
{
}
void SET_COLOR(int color)
{
	WORD wColor;
     

     HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
     CONSOLE_SCREEN_BUFFER_INFO csbi;
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
          wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
}
void SuatChieu::setTime(string& s){
    this->time = s;
}
string SuatChieu::getTime(){
    return this->time;
}
void SuatChieu::doc(ifstream& in){
    string t;
    int dem;
    int temp;
	getline(in, t);
    in >> dem;
    for(int i=0;i<dem;i++){
        char ss[5];
	    in.getline( ss, 3 ); 
        in>>temp;
        this->addAisle(temp);
    }
    char ss[5];
	in.getline( ss, 3 ); 
    this->setTime(t);	
}
void SuatChieu::ghi(ofstream& o){
    o << getTime() << endl;
    o << this->count << endl;
    for(int i=0; i<this->count;i++){
        o << this->ListSelected[i] << endl;
    }
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
        if(i==2 || i==8){
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
                SET_COLOR(4);
                if(j==2 || j==8){
                    cout << setw(9)<<  unavail;
                } else {
                    cout << setw(5) << unavail;        
                }
            } else {
                SET_COLOR(2);
                if(j==2 || j==8){
                    cout << setw(9)<<  avail;
                } else {
                    cout << setw(5) << avail;        
                }
            }
        }
        cout << "\n\n";
        SET_COLOR(7);
    }
}
void SuatChieu::addAisle(int& a){
    this->ListSelected[count] = a;
    this->count++;
}
