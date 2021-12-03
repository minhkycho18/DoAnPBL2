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
    cout << "------------------Danh Sach Phim-------------------------\n";
    for (int i=0;i< m; i++){
        cout << i << "." << endl;
        (this->ds_phim + i)->output();
        cout << endl;
    }
    cout << "---------------------------------------------------------\n";
    // }
}
void QuanLy::Cap_Nhat_Du_Lieu(){
    ifstream tsp,dsp,dskh,tskh;
    int ts;
    tsp.open("tongsophim.txt",ios::in);
    dsp.open("dsphim.txt",ios::in);
    dskh.open("dskhachhang.txt",ios::in);
    tskh.open("tongsophim.txt",ios::in);
    tsp >> this->m;
    this->ds_phim = new phim[this->m];
        for(int i=0; i < this->m; i++)
    {
        (this->ds_phim + i)->doc(dsp);      // Hàm để cập nhật dữ liệu từ file trước khi chạy chương trinh
    }
    tskh >> this->p;
    tskh >> this->n;
    this->ds_khtv = new KH_ThanhVien[this->p];
    this->ds_khbt = new KH_BinhThuong[this->n];
    for(int i=0; i< this->p + this->n ;i++){
        int demTV=0,demBT=0;
        string temp;
        getline(dskh,temp);
        if(temp == "thanhvien"){
            (this->ds_khtv+demTV)->doc(dskh);
            (this->ds_khtv+demTV)->output();
            demTV++;
        } 
        // else 
        // if(temp == "binhthuong"){
        //     demBT++;
        //     (this->ds_khbt+demBT)->doc(dskh);
        // }
    }
    tsp.close();
    dsp.close();
    dskh.close();
    tskh.close();
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
        if(k>=m){
            cout << "\nVi Tri Them Khong Hop Le\n";
        }
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
        if(k>=m){
            cout << "\nVi Tri Xoa Khong Hop Le\n";
        } else {
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
        }
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
void QuanLy::SuaPhim(){  
    int chon;
    while (true)
	{
        int select;
		system("cls");
        this->DisplayMovie();
		cout << "\n1. Bat Dau Sua Phim:";
		cout << "\n0. Ket thuc:";
		cout << endl;
		cout << "\nNhap lua chon: ";
		cin >> chon;
        if(chon == 1) {
            int option;
            cout << "\n Nhap So Thu Tu Phim Muon Sua: "; cin >> select;
            while(select >= this->m){
                cout << "\n Khong Ton Tai Vi Tri Phim, \n Vui Long Nhap Lai.";
                cin >> select;
            }
            while(true){
                system("cls");
                (this->ds_phim+select)->output();
                cout << "\n Chon Thuoc Tinh Muon Sua: ";
                cout << "\n1. Ten Phim:";
                cout << "\n2. The Loai Phim:";
                cout << "\n3. Thoi Luong Phim:";
                cout << "\n0. Ket Thuc";
                cout << endl;
                cout << "\nNhap lua chon: ";
                cin >>  option;
                if(option == 1){
                    string temp;
                    cout << "\nNhap Ten Phim: ";fflush(stdin);getline(cin,temp);
                    (this->ds_phim+select)->setTenPhim(temp);
                } else
                if(option == 2){
                    string temp;
                    cout << "\nNhap The Loai Phim: ";fflush(stdin);getline(cin,temp);
                    (this->ds_phim+select)->setTheLoai(temp);
                } else 
                if(option == 3){
                    int temp;
                    cout << "\n Nhap Thoi Luong Phim: "; cin >> temp;
                    (this->ds_phim+select)->setThoiLuongPhim(temp);
                } else {
                    break;
                }
            }
        } else {
            break;
        }				        
    }
    ofstream dsp;
    dsp.open("dsphim.txt", ios::out);
    for(int i=0; i<this->m; i++){
        (this->ds_phim+i)->ghi(dsp);
    }
    dsp.close();
}
void QuanLy::addCustomer(const int& a,phim& p){
    if(a == 1) {
        KH_ThanhVien tv;
        tv.input(p);
        if(this->p==0){
            this->ds_khtv = new KH_ThanhVien[this->p+1];        
            *(this->ds_khtv + this->p)= tv;
        } else {
            KH_ThanhVien *temp = new KH_ThanhVien[this->p];
            for(int i=0;i < this-> p;i++)
                *(temp+i) = *(this->ds_khtv+i);
            delete[] this->ds_khtv;
            this->ds_khtv = new KH_ThanhVien[this->p+1];
            for(int i=0;i<this->p;i++){
                *(this->ds_khtv+i) = *(temp+i);
            }
            *(this->ds_khtv+this->p) = tv;
            delete[] temp;
        }
            this->p++;
            ofstream dskh,tskh;
            dskh.open("dskhachhang.txt",ios::app);
            tskh.open("tongsoKH.txt",ios::out);
            tskh << this->p << endl;
            tskh << this->n << endl;
            (this->ds_khtv + this->p -1)->ghi(dskh);
            dskh.close();
            tskh.close();
    } else {
        KH_BinhThuong bt;
        bt.input(p);
        if(this->n==0){
            this->ds_khbt = new KH_BinhThuong[this->n+1];        
            *(this->ds_khbt + this->n) = bt;
        } else {
            KH_BinhThuong *temp = new KH_BinhThuong[this->n];
            for(int i=0;i < this-> n;i++)
                *(temp+i) = *(this->ds_khbt+i);
            delete[] this->ds_khbt;
            this->ds_khbt = new KH_BinhThuong[this->n+1];
            for(int i=0;i<n;i++){
                *(this->ds_khbt+i) = *(temp+i);
            }
            *(this->ds_khbt+this->n) = bt;
            delete[] temp;
        }
            this->n++;
            ofstream dskh,tskh;
            dskh.open("dskhachhang.txt",ios::app);
            tskh.open("tongsoKH.txt",ios::out);
            tskh << this->p << endl;
            tskh << this->n << endl;
            (this->ds_khbt + this->n -1)->ghi(dskh);
            dskh.close();
            tskh.close();
    }        
}
void QuanLy::DisplayCustomer(){
    cout << "------------------Danh Sach Khach Hang-------------------------\n";
    for (int i=0;i< this->p; i++){
        cout << i << "." << endl;
        (this->ds_khtv + i)->output();
        cout << endl;
    }
    for (int i=0;i< this->n; i++){
        cout << i << "." << endl;
        (this->ds_khbt + i)->output();
        cout << endl;
    }
    cout << "----------------------------------------------------------------\n";
}
void QuanLy::Datve(){
    int chon;
    char tt;
    while (true)
	{
		system("cls");
        this->DisplayMovie();
		cout << "\n======Vui Long Chon Phim:==============";
		cout << endl;
		cout << "\nNhap lua chon: ";
		cin >> chon;
        system("cls");
        int select;
        cout << "\n===== Ban Co The Thanh Vien Khong ?=====";
        cout << "\n1.Co";
        cout << "\n2.Khong";
        cout << "\n0.Ket Thuc";
        cout << endl;
		cout << "\nNhap lua chon: ";
		cin >> select;
        this->addCustomer(select,*(this->ds_phim+chon));
    }
}
