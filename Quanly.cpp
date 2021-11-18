#include "QuanLy.h"
#include "fstream"
QuanLy::QuanLy()
{
    this->m=0;
    this->n=0;
    this->p=0;
    this->ds_phim = nullptr;
    this->ds_khbt = nullptr;
    this->ds_khtv = nullptr;
}

QuanLy::~QuanLy()
{
    delete[] this->ds_phim;
    delete[] this->ds_khtv;
    delete[] this->ds_khbt;
}
void QuanLy::DisplayMovie(){  
    if(this->m==0)
    {
        cout <<"\nDanh sach phim trong!\n";
    } else {
    cout << "------------------Danh Sach Phim-------------------------\n";
    for (int i=0;i< m; i++){
        cout << i << "." << endl;
        (this->ds_phim + i)->output();
        cout << endl;
    }
    cout << "---------------------------------------------------------\n";
    }
}
void QuanLy::Cap_Nhat_Du_Lieu(){
    ifstream tsp,dsp;
    tsp.open("tongsophim.txt",ios::in);
    dsp.open("dsphim.txt",ios::in);
    tsp >> this->m;
    this->ds_phim = new phim[this->m];
    for(int i=0; i < this->m; i++){
        (this->ds_phim + i)->doc(dsp);      // Hàm để cập nhật dữ liệu từ file trước khi chạy chương trinh
    }
}
void QuanLy::ThemPhim(){
    int chon;
    while (true)
    {
    system("cls");
    cout << "\n\n\t\t ====== Them Phim ======";
	cout << "\n1. Them Phim Vao Dau";
    cout << "\n2. Them Phim Vao Cuoi";
    cout << "\n3. Them Phim Vao Vi Tri Tuy Chon";
	cout << "\n0. Ket thuc:";
	cout << endl;
	cout << "\nNhap lua chon: ";
	cin >> chon;

	if (chon == 1)
	{
		cout << "\n Nhap Thong Tin Ve Phim: \n";
        phim p;
        p.input();

        if(this->m==0){
            this->ds_phim = new phim[this->m+1];        
            *(this->ds_phim + this->m) = p;
        } else {
            phim *temp = new phim[this->m];
            for(int i=0;i < this-> m;i++)
                *(temp+i) = *(this->ds_phim+i);
            delete[] this->ds_phim;
            this->ds_phim = new phim[this->m+1];
            for(int i=0;i<this->m;i++){
                *(this->ds_phim+i+1) = *(temp+i);
            }
            *(this->ds_phim) = p;
            delete[] temp;
        }
            this->m++;
        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::out);
        tsp.open("tongsophim.txt",ios::out);
        for(int i=0 ; i < this->m; i++){
            (this->ds_phim+i)->ghi(dsp);
        }
        tsp << this->m;
        dsp.close();
        tsp.close();
        system("pause");
	} else
    if(chon == 2){
        cout << "\n Nhap Thong Tin Ve Phim: \n";
        phim p;
        p.input();
        if(this->m==0){
            this->ds_phim = new phim[this->m+1];        
            *(this->ds_phim + this->m) = p;
        } else {
            phim *temp = new phim[this->m];
            for(int i=0;i < this-> m;i++)
                *(temp+i) = *(this->ds_phim+i);
            delete[] this->ds_phim;
            this->ds_phim = new phim[this->m+1];
            for(int i=0;i<m;i++){
                *(this->ds_phim+i) = *(temp+i);
            }
            *(this->ds_phim+this->m) = p;
            delete[] temp;
        }
            this->m++;

        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::out);
        tsp.open("tongsophim.txt",ios::out);
        for(int i=0 ; i < this->m; i++){
            (this->ds_phim+i)->ghi(dsp);
        }
        tsp << this->m;
        dsp.close();
        tsp.close();
        system("pause");
    } else
    if(chon == 3){
        cout << "\n Nhap Thong Tin Ve Phim: \n";
        phim p;
        p.input();
        cout << "\n Nhap Vi Tri Can Them Phim : ";
        int k;
        cin >> k;
        
        phim *temp = new phim[this->m];
        for(int i=0;i < this-> m;i++)
            *(temp+i) = *(this->ds_phim+i);
        delete[] this->ds_phim;
        this->ds_phim = new phim[this->m+1];
        for(int i=0;i<this->m+1;i++){
            if(i<k){
                *(this->ds_phim+i) = *(temp+i);
            } else if(i == k){
                *(this->ds_phim+i) = p;
            }  else {
                *(this->ds_phim+i) = *(temp+i-1);
            }
        }
        delete[] temp;
        this->m++;

        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::out);
        tsp.open("tongsophim.txt",ios::out);
        for(int i=0 ; i < this->m; i++){
            (this->ds_phim+i)->ghi(dsp);
            cout << 1;
        }
        tsp << this->m;
        dsp.close();
        tsp.close();
        system("pause");
    }		
	else
	{				
		 break;
	}  
                        
}			       
}
void QuanLy::XoaPhim()
{   
    int chon;
    while(true)
    {
        system("cls");
        cout << "\n\n\t\t ====== Xoa Phim ====== \n";
        this->DisplayMovie();
	    cout << "\n1. Xoa Phim Dau Tien";
        cout << "\n2. Xoa Phim Cuoi Cung";
        cout << "\n3. Xoa Phim Vi Tri Tuy Chon";
	    cout << "\n0. Ket thuc:";
	    cout << endl;
	    cout << "\nNhap lua chon: ";
	    cin >> chon;
    if (chon == 1)
    {
        if(this->m==0)
        {
            cout <<"\nDanh sach phim trong!\n";
        }
        else
        {   phim *temp = new phim[this->m];
            for(int i=0; i<this->m;i++)
                *(temp+i) = *(this->ds_phim + i);
            delete[] this ->ds_phim;
            this->ds_phim = new phim[this->m -1];
            for(int i=0; i<this->m-1;i++)
                *(this->ds_phim + i) = *(temp + i+1);
        // *(this->ds_phim) = p;
        delete[] temp;
        }
        this->m--;
    ofstream dsp, tsp;
    dsp.open("dsphim.txt", ios::out);
    tsp.open("tongsophim.txt", ios::out);
    for(int i=0; i<this->m; i++){
        (this->ds_phim+i)->ghi(dsp);
    }
    tsp << this->m;
    dsp.close();
    tsp.close();
    system("cls");
    this->DisplayMovie();
    system("pause");
    }
    else
    if(chon==2)
    {
        if(this->m==0)
        {
            cout <<"\nDanh sach phim trong!\n";
        }
        else{
            phim *temp = new phim[this->m];
            for(int i=0;i < this->m-1;i++)
                *(temp+i) = *(this->ds_phim+i);
            delete[] this->ds_phim;
            this->ds_phim = new phim[this->m-1];
            for(int i=0; i<this->m-1; i++)
                *(this->ds_phim + i) = *(temp + i);
        // *(this->ds_phim) = p;
        delete[] temp;
        }
        this->m--;
    ofstream dsp, tsp;
    dsp.open("dsphim.txt", ios::out);
    tsp.open("tongsophim.txt", ios::out);
    for(int i=0; i<this->m; i++){
        (this->ds_phim+i)->ghi(dsp);
    }
    tsp << this->m;
    dsp.close();
    tsp.close();
    this->DisplayMovie();
    system("pause");
    }
    else
    if( chon == 3){
        cout <<"\n Nhap Vi Tri Can Xoa: ";
        int k;
        cin >> k;
        phim *temp = new phim[this->m];
        for(int i=0;i < this->m;i++)
            *(temp+i) = *(this->ds_phim+i);
        delete[] this->ds_phim;
        this->ds_phim = new phim[this->m-1];
        for(int i =0;i<this->m-1;i++){  
            if(i<k){
                *(this->ds_phim + i) = *(temp+i);
            } 
            else {
                *(this-> ds_phim +i) = *(temp +i+1);
            }
        }
        delete[] temp;
        this->m--;
        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::out);
        tsp.open("tongsophim.txt",ios::out);
        for(int i=0 ; i < this->m; i++){
            (this->ds_phim+i)->ghi(dsp);
        }
        tsp << this->m;
        dsp.close();
        tsp.close();
        this->DisplayMovie();
        system("pause");
    }
    else{
        break;
    }
    }
}
