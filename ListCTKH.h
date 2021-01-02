#ifndef _LISTCTKH_H
#define _LISTCTKH_H
#include<iostream>
#include"CongTrinhKhoaHoc.h"
#include"Sach.h"
#include"BaiBao.h"
using namespace std;
template<class T>
class ListCTKH
{
    private:
    string tenTacGia;
    int soLuongCTKH;
    T **data;
    public:
    ListCTKH();
    ListCTKH(string);
    ~ListCTKH();
    friend ostream& operator<<(ostream& o, const ListCTKH& LCT)
    {
        for(int i=0;i<LCT.soLuongCTKH;++i)
            o<<(LCT.data+i).Show();
            o<<endl;
            return o;
    }

    const CongTrinhKhoaHoc operator[](const int);
    void operator=(const ListCTKH&);
    void Add(T *);
    void Input();
    void Update();
    void Remove();
    void ShowList();
    int Find();
};
#endif