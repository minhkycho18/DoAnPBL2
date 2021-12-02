#ifndef khtv_h
#define khtv_h
#include "khachhang.h"
class KH_ThanhVien : public khachhang
{
    private:
        string LoaiKH;
        int gia;
    public:
        KH_ThanhVien();
        ~KH_ThanhVien();
        void setLoaiKH(string = "thanhvien");
        void setgia(int =55000);
    // Overide
    // void TinhTien();
    void input(phim&);
    void output();
    void ghi(ofstream&);
};
#endif

