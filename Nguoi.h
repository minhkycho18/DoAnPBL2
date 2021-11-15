#include <iostream>
#include <fstream>
using namespace std;
class Nguoi
{
protected:
    string Hoten;
    int tuoi;
public:
    Nguoi(); 
    ~Nguoi();
    //----------------------------------------------
    void setHoten(string&);
    void setTuoi(int&);
    string getHoten();
    int getTuoi();
    //-----------------------------------------------
    void doc(ifstream&);
    void ghi(ofstream&);
    void input();  
    void output();
    
};