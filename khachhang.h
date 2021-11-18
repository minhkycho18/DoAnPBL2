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
    vexemphim ve[100];
    int soluong;
    unsigned int tongtien;
public:
    khachhang();
    ~khachhang();
    // ----------------Cụm hàm get set------------------------
    void setsoluong(int&);
    void setTongtien(int&);  
    int getSoluong();
    int getTongtien();
    //-----------------Nhập và suất----------------------------
    void input(phim&);
    void output();
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&);
    void ghi(ofstream&);
    virtual void TinhTien() = 0 ;
};
#endif


