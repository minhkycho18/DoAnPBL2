#include "QuanLy.h"
#include <fstream>


// void Xem_DS_phim(phim ds_phim[],int& m){
//     for (int i=0;i< m; i++){
//         cout << i << "." << endl;
//         ds_phim[i].output();
//         cout << endl;
//     }
// }
// void Cap_Nhat_Du_Lieu(phim ds_phim[], int& m){
//     ifstream tsp,dsp;
//     tsp.open("tongsophim.txt",ios::in);
//     dsp.open("dsphim.txt",ios::in);
//     tsp >> m;
//     for(int i=0; i < m; i++){
//         ds_phim[i].doc(dsp);        // Hàm để cập nhật dữ liệu từ file trước khi chạy chương trinh
//     }
// }
void Menu(){
    QuanLy ql;
    ql.Cap_Nhat_Du_Lieu();
    system("pause");
    int luachon;    
        while (true)
	{
		system("cls");
		cout << "\n\n\t\t ====== QUAN LY BAN VE ======";
		cout << "\n\t1. Dang Nhap Voi Tu Cach Quan Ly ";	
		cout << "\n\t2. Dang Nhap Voi Tu Cach Nhan Vien Ban ve";
		cout << "\n\t0. Ket thuc";
		cout << "\n\n\t\t ============== END ============";	
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
                    system("cls");
                    ql.ThemPhim();
                } 
                if(luachonQL == 2){
                    system("cls");
                    ql.XoaPhim();
                }
                if(luachonQL == 3){
                    system("cls");
                    ql.SuaPhim();
                }    
                if(luachonQL == 4){
                    system("cls");
                    ql.DisplayMovie();
                    system("pause");
                }
                if(luachonQL == 6){
                    system("cls");
                    ql.DisplayCustomer();
                    system("pause");
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
                if(luachonNV == 1){
                    ql.Datve();
                }
            }
            
        }
        else {
            break;
        }
		
		
	}
}
int main(){
    
    Menu();
    return 0;
}
