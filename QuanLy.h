
#include "KH_BinhThuong.h"
#include "KH_ThanhVien.h"
#include "fstream"
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
    //----------------------------Phim---------------------------------
    void Cap_Nhat_Du_Lieu();
    void ThemPhim();
    void XoaPhim();
    void SuaPhim();
    void DisplayMovie();
    //----------------------------KhachHang--------------------------------
    void Datve();
    void DisplayCustomer();
    void addCustomer(const int&, phim&);
    void DisplayRevenue();
};

