#include "KH_BinhThuong.h"
KH_BinhThuong::KH_BinhThuong()
{
}

KH_BinhThuong::~KH_BinhThuong()
{
}
void KH_BinhThuong::TinhTien(){
    int giatienbth = 75000;
    for(int i=0; i< this->soluong; i++){
        ve[i].setgiave(giatienbth);
        this->tongtien += this->ve[i].getgiave();
    }
}