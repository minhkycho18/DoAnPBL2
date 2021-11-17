
#include "KH_BinhThuong.h"
#include "KH_ThanhVien.h"

class QuanLy 
{
public:
    phim ds_phim[100];
    KH_BinhThuong ds_khbt[100];
    KH_ThanhVien ds_khtv[100];
    int m,n,p;
public:
    QuanLy();
    ~QuanLy();
    void ThemPhim();
    void XoaPhim();
    void SuaPhim();
    void DisplayMovie();
};

