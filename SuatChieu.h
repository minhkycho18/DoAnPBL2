#ifndef suatchieu_h
#define suatchieu_h
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;
class SuatChieu
{
    private:
        string time;
        const int row = 9;
        const int col = 9;
        int ListSelected[81];
        int count;
    public:
        void addAisle(int&);
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
        friend void SET_COLOR(int);
};


#endif