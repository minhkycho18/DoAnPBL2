#ifndef phim_h
#define phim_h

#include <string>
#include<fstream>
using namespace std;

class phim
{
private:
    string tenphim;
    string theloai;
    int thoiluongphim;
public:
    phim();
    ~phim();
    phim(const phim& ); // hàm copy
    // ----------------Cụm hàm get set------------------------
    void setTenPhim(string&);
    void setTheLoai(string&);
    void setThoiLuongPhim(int&);
    string getTenPhim();
    string getTheLoai();
    int getThoiLuongPhim();
    //-----------------Nhập và suất----------------------------
    void input();
    void output();
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&);
    void ghi(ofstream&);
};
#endif
