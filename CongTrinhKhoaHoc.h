#ifndef _CONGTRINHKHOAHOC_H
#define _CONGTRINHKHOAHOC_H
#include<string>
#include<iostream>
using namespace std;
class CongTrinhKhoaHoc
{
    protected:
        string maCongTrinh;
        int namXuatBan;
        bool khuVucXuatBan;
    public:
        CongTrinhKhoaHoc();
        CongTrinhKhoaHoc(string, int , bool);
        virtual ~CongTrinhKhoaHoc();
        virtual void Show();
        virtual void Nhap();
        string getMaCongTrinh();
        void setMaCongTrinh(string);
        void setNamXuatBan(int);
        void setKhuVucXuatBan(bool);
};
#endif