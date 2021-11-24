#ifndef khbt_h
#define khbt_h
#include "khachhang.h"
#include <fstream>
class KH_BinhThuong : public khachhang
{
    private:
        string LoaiKH ;
        int gia;
        
    public:
        KH_BinhThuong();
        ~KH_BinhThuong();
        void setLoaiKH(string = "binhthuong");
        void setgia(int =75000);
    // Overide
        // void TinhTien();
        void input( phim&);
        void ghi(ofstream&);
};
#endif


