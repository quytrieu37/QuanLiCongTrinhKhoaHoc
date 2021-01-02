#ifndef _SACH_H
#define _SACH_H
#include<iostream>
#include"CongTrinhKhoaHoc.h"
using namespace std;
class Sach : public CongTrinhKhoaHoc
{
    private:
    string loaiSach;
    public:
    Sach();
    Sach(string);
    virtual ~Sach();
    void Show();
    void Nhap();
    void setLoaiSach(string);

};
#endif