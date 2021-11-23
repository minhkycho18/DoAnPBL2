#ifndef khtv_h
#define khtv_h
#include "khachhang.h"
class KH_ThanhVien : public khachhang
{
    private:
        string LoaiKH;
        int giatv;
    public:
        KH_ThanhVien();
        ~KH_ThanhVien();
    // Overide
    // void TinhTien();
    void input(phim&);
};
#endif

