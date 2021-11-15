#include "KH_ThanhVien.h"
KH_ThanhVien::KH_ThanhVien()
{
}

KH_ThanhVien::~KH_ThanhVien()
{
}
void KH_ThanhVien::TinhTien(){
    int giatienbth = 75000;
    for(int i=0; i< this->soluong; i++){
        ve[i].setgiave(giatienbth);
        this->tongtien += this->ve[i].getgiave();
    }
}