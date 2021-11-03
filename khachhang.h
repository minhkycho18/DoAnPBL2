#include "vexemphim.h"
#include "Date.h"
#include <fstream>
using namespace std;
class khachhang
{
private:
    string Hoten;
    Date ngaydatve;
    int tuoi;
    vexemphim ve[100];
    int soluong;
    int tongtien;
public:
    khachhang();
    ~khachhang();
    // ----------------Cụm hàm get set------------------------
    void setHoten(string&);
    void setTuoi(int&);
    void setsoluong(int&);
    void setTongtien(int&);
    string getHoten();
    int getTuoi();
    int getSoluong();
    int getTongtien();
    //-----------------Nhập và suất----------------------------
    void input(phim&);
    void output();
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&);
    void ghi(ofstream&);
};



