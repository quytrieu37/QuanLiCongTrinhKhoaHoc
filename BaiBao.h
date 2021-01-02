#ifndef _BAIBAO_H 
#define _BAIBAO_H
#include<iostream>
#include"CongTrinhKhoaHoc.h"
using namespace std;
class BaiBao : public CongTrinhKhoaHoc
{
    private:
    string tenCongTrinh;
    int soTacGia;
    public:
    BaiBao();
    BaiBao(string, int);
    virtual ~BaiBao();
    void Show();
    void Nhap();
    void setTenCongTrinh(string);
    void setSoTacGia(int);
};
#endif