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
    // Cap_Nhat_Du_Lieu(ds_phim,m);
    cout << 1;
    QuanLy ql;
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
                cout << "\n\t4. Sua Phim Trong Danh Sach Phim ";	
                cout << "\n\t3. Khoi Tao Toan Bo Danh Sach Phim ";
		        cout << "\n\t4. Xem Danh Sach Phim Hien Tai";
                cout << "\n\t5. Xem Doanh Thu Tong ";
                cout << "\n\t6. Danh Sach Khach Hang Da Mua Ve";
                cout << "\n\t0. Ket Thuc";
                cout << "\n\n\t\t ============== END ============";	
		        cout << "\nNhap lua chon: ";
                int luachonQL;
                cin >> luachonQL;
                if(luachonQL==1) {
                    // ql.ThemPhim();
                } 
                if(luachonQL == 2){

                }
                if(luachonQL == 3){
                    // int chon;
                    // ofstream clr;
                    // clr.open("dsphim.txt",ios::out);
                    // clr.close();
                    // m=0;
			        // while (true)
			        // {
				        // system("cls");
				        // cout << "\n1. Nhap phim:";
				        // cout << "\n0. Ket thuc:";
				        // cout << endl;
				        // cout << "\nNhap lua chon: ";
				        // cin >> chon;

				        // if (chon == 1)
				        // {
				        // 	cout << "\n Nhap Thong Tin Ve Phim: \n";
        			    //     ThemPhim(ds_phim,m);
                        //     ofstream dsp,tsp;
                        //     dsp.open("dsphim.txt",ios::app);
                        //     tsp.open("tongsophim.txt",ios::out);
                        //     ds_phim[m-1].ghi(dsp);
                        //     tsp << m;
                        //     dsp.close();
                        //     tsp.close();
				        // }				
				        // else
				        // {				
					    //     break;
				        // }
                    // }
                }    
                if(luachonQL == 4){
                    // system("cls");
                    // Xem_DS_phim(ds_phim,m);
                    // system("pause");
                }
                if(luachonQL == 5){
                    
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
    
    Menu();
    return 0;
}
