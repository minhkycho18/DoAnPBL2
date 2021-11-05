#include "khachhang.h"
#include <iostream>
#include <fstream>
using namespace std;
void ThemPhim(phim ds_phim[], int &m){
    phim p;
    p.input();
    ds_phim[m] = p;           // Hàm để thêm phim vào cuối mảng
    m++;
}
void Cap_Nhat_Du_Lieu(phim ds_phim[], int& m){
    ifstream tsp,dsp;
    tsp.open("tongsophim.txt",ios::in);
    dsp.open("dsphim.txt",ios::in);
    tsp >> m;
    for(int i=0; i < m; i++){
        ds_phim[i].doc(dsp);        // Hàm để cập nhật dữ liệu từ file trước khi chạy chương trinh
    }
}
void Menu(khachhang ds_kh[],int n,phim ds_phim[], int m){
    Cap_Nhat_Du_Lieu(ds_phim,m);
    int luachon;    
        while (true)
	{
		system("cls");
		cout << "\n\n\t\t ====== QUAN LY BAN VE ======";
		cout << "\n\t1. Dang Nhap Voi Tu Cach Quan Ly ";	
		cout << "\n\t2. Dang Nhap Voi Tu Cach Nhan Vien Ban ve";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== END ==========";	
		cout << "\nNhap lua chon: ";
		cin >> luachon;
        if(luachon ==1){
            while (true)
            {
                system("cls");
                cout << "\n\n\t\t ====== Bang Hien Thi Quan ly ======";
                cout << "\n\t1. Them Phim Vao Danh Sach Phim ";	
                cout << "\n\t2. Xoa Phim Trong Danh Sach Phim ";	
                cout << "\n\t3. Sua Phim Trong Danh Sach Phim ";	
		        cout << "\n\t4. Xem Danh Sach Phim Hien Tai";
                cout << "\n\t5. Xem Doanh Thu Tong ";
                cout << "\n\t6. Danh Sach Khach Hang Da Mua Ve";
                cout << "\n\t0. Ket Thuc";
                cout << "\n\n\t\t ============== END ============";	
		        cout << "\nNhap lua chon: ";
                int luachonQL;
                cin >> luachonQL;
                if(luachonQL==1) {
                    int chon;
			        while (true)
			        {
				        system("cls");
				        cout << "\n1. Nhap phim:";
				        cout << "\n0. Ket thuc:";
				        cout << endl;
				        cout << "\nNhap lua chon: ";
				        cin >> chon;

				        if (chon == 1)
				        {
				        	cout << "\n Nhap Thong Tin Ve Phim: \n";
        			        ThemPhim(ds_phim,m);
                            ofstream dsp,tsp;
                            dsp.open("dsphim.txt",ios::app);
                            tsp.open("tongsophim.txt",ios::out);
                            ds_phim[m-1].ghi(dsp);
                            tsp << m;
                            dsp.close();
                            tsp.close();
				        }				
				        else
				        {				
					        break;
				        }
                        
			        }
                } 
                if(luachonQL == 2){

                }
                else{
                    break;
                }
            }
            
        } else
        if(luachon==2){
            while (true)
            {
                system("cls");
                cout << "\n\n\t\t ====== Bang Hien Thi Nhan Vien Ban Ve======";
                cout << "\n\t1. Dat ve";
                cout << "\n\t0. Ket Thuc";
                cout << "\n\n\t\t ============== END ============";	
		        cout << "\nNhap lua chon: ";
                int luachonNV;
                cin >> luachonNV;
            }
            
        }
        else {
            break;
        }
		
		
	}
}
int main(){
    
    khachhang kh[100];
    int n=0;
    phim ds_phim[100];
    int m=0;
    Menu(kh,n,ds_phim,m);
    return 0;
}
