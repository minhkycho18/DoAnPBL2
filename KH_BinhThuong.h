#ifndef khbt_h
#define khbt_h
#include "khachhang.h"
class KH_BinhThuong : public khachhang
{
    private:
        const string LoaiKH = "binhthuong";
        const int giabth=75000;
    public:
        KH_BinhThuong();
        ~KH_BinhThuong();
    // Overide
        // void TinhTien();
        void input( phim&);
};
#endif


