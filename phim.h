#ifndef phim_h
#define phim_h

#include <string>
#include<fstream>
#include "SuatChieu.h"
using namespace std;

class phim
{
private:
    string tenphim;
    string theloai;
    int thoiluongphim;
    int SLSuat;
    SuatChieu *dssc;
public:
    phim();
    ~phim();
    phim(const phim& ); // hàm copy
    // ----------------Cụm hàm get set------------------------
    void setTenPhim(string&);
    void setTheLoai(string&);
    void setThoiLuongPhim(int&);
    void setSLSuat(int&);
    string getTenPhim();
    string getTheLoai();
    int getThoiLuongPhim();
    int getSLSuat();
    //-----------------Nhập và suất----------------------------
    void input();
    void output();
    void Showtimes();
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&);
    void docKH(ifstream&);
    void ghi(ofstream&);
    void ghiKH(ofstream&);
};
#endif
