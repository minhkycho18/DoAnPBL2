#include "QuanLy.h"
QuanLy::QuanLy()
{
    this->m=0;
    this->n=0;
    this->p=0;
    this->ds_phim[this->m];
    // this->ds_khbt[this->n];
    // this->ds_khtv[this->p];
}

QuanLy::~QuanLy()
{
}
void QuanLy::ThemPhim(){
    int chon;
    while (true)
    {
    system("cls");
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

        if(m==0){
            this->ds_phim[m] = p;           
            this->m++;
        } else {
            for(int i=0;i<m;i++){
                this->ds_phim[i+1]= this->ds_phim[i];
            }
            this->ds_phim[0] = p;
            this->m++;
        }

        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::out);
        tsp.open("tongsophim.txt",ios::out);
        for(int i=0 ; i < m; i++){
            this->ds_phim[i].ghi(dsp);
        }
        tsp << m;
        dsp.close();
        tsp.close();
	}	
    if(chon == 2){
        cout << "\n Nhap Thong Tin Ve Phim: \n";
        phim p;
        p.input();
        ds_phim[m] = p;           
        m++;
        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::app);
        tsp.open("tongsophim.txt",ios::out);
        ds_phim[m-1].ghi(dsp);
        tsp << m;
        dsp.close();
        tsp.close();
    }
    if(chon == 3){
        cout << "\n Nhap Thong Tin Ve Phim: \n";
        phim p;
        p.input();
        cout << "\n Nhap Vi Tri Can Them Phim : ";
        int k;
        cin >> k;
        for (int i = n - 1; i >= k - 1; i--)
            this->ds_phim[i+1] = this->ds_phim[i];
        this->ds_phim[k-1] = p;
        m++;
        ofstream dsp,tsp;
        dsp.open("dsphim.txt",ios::out);
        tsp.open("tongsophim.txt",ios::out);
        for(int i=0 ; i < m; i++){
            this->ds_phim[i].ghi(dsp);
        }
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