#ifndef suatchieu_h
#define suatchieu_h
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
class SuatChieu
{
    private:
        string time;
        const int row = 8;
        const int col = 12;
        int ListSelected[96];
    public:
        bool checkAisle(int&, int&);
        void ShowAisleMap();
        SuatChieu();
        ~SuatChieu();
        void setTime(string&);
        string getTime();
        void doc(ifstream&);
        void ghi(ofstream&);
        void input();
        void output();
};


#endif