#ifndef vxp_h
#define vxp_h
#include "phim.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class vexemphim
{
protected:  
    phim tenphim;
    string SoGhe;
    int giatien;
    string showtime;
public:
    vexemphim();
    ~vexemphim();
    // ----------------Cụm hàm get set------------------------
    void setShowtime(string&);
    string getShowtime();
    void setSoghe(string&);
    void setgiave( int&);
    string getSoghe();
    int getgiave();
    //-----------------Nhập và suất----------------------------
    void input(phim&);
    void output();
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&);
    void ghi(ofstream&);
};
#endif


