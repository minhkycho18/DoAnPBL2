#ifndef suatchieu_h
#define suatchieu_h
#include <iostream>
#include <fstream>
using namespace std;
class SuatChieu
{
    private:
        string time;
        int ChairsSelect[9][10];
        const int row = 9;
        const int col = 10;
        int ListSelected[90];
    public:
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