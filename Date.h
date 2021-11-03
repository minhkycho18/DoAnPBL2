#include <iostream>
#include <fstream>
using namespace std;
class Date
{
private:
    int day,month,year;
public:
    Date();
    ~Date();
    // ----------------Cụm hàm get set------------------------
    void setday(int&);
    void setmonth(int&);
    void setyear(int&);
    int getday();
    int getmonth();
    int getyear();
    //-----------------Nhập và suất----------------------------
    void input();
    void output();
    //-----------------Các phương thức đọc và ghi file---------
    void doc(ifstream&);
    void ghi(ofstream&);
};



