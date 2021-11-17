
#include "KH_BinhThuong.h"
#include "KH_ThanhVien.h"
#include "fstream"
// #include "khachhang.h"
class QuanLy 
{
public:
    phim *ds_phim;
    KH_BinhThuong *ds_khbt;
    KH_ThanhVien *ds_khtv;
    int m,n,p;
public:
    QuanLy();
    ~QuanLy();
    void ThemPhim();
    void XoaPhim();
    void SuaPhim();
    void DisplayMovie();
};

