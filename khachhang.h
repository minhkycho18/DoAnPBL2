#ifndef kh_h
#define kh_h
#include "vexemphim.h"
#include "Date.h"
#include "Nguoi.h"
#include <fstream>
using namespace std;
class khachhang : public Nguoi
{
protected:
    Date ngaydatve;
    vexemphim ve[50];
    int soluong;
    int tongtien;
public:
    khachhang();
    ~khachhang();
    // ----------------Cụm hàm get set------------------------
    void setsoluong(int&);
    void setTongtien(int&);  
    int getSoluong();
    int getTongtien();
    //-----------------Nhập và suất----------------------------
    virtual void input(phim&) = 0;
    virtual void output() = 0;
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&) ;
    virtual void ghi(ofstream&) = 0;
    // virtual void TinhTien() = 0 ;
    // void Datve();
};
#endif


