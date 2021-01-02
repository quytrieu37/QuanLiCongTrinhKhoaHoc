#include"CongTrinhKhoaHoc.h"
CongTrinhKhoaHoc::CongTrinhKhoaHoc()
{

}
CongTrinhKhoaHoc::CongTrinhKhoaHoc(string _maCongTrinh, int _namXuatBan, bool _khuVucXuatBan)
: maCongTrinh(_maCongTrinh), namXuatBan(_namXuatBan), khuVucXuatBan(_khuVucXuatBan)
{

}
CongTrinhKhoaHoc::~CongTrinhKhoaHoc()
{

}

void CongTrinhKhoaHoc::Show()
{
    cout<<"ma xong trinh CTKH: "<<this->maCongTrinh<<endl;
    cout<<"nam xuat ban CTKH: "<<this->namXuatBan<<endl;
    cout<<"Khu vuc xuat ban CTKH: ";
    if(this->khuVucXuatBan==1)
    cout<<"quoc te";
    else
    cout<<"trong nuoc";
}
void CongTrinhKhoaHoc::Nhap()
{
    // cout<<"nhap loai cong trinh: (1) : bai bao (2) : sach";
    cout<<"nhap ma cong trinh CTKH: ";
    cin.ignore();
    getline(cin, this->maCongTrinh);
    this->namXuatBan=1900;
    while(this->namXuatBan<1990)
    {
        cout<<"nhap nam xuat ban, tu 1990 den nay CTKH: ";
        cin>>this->namXuatBan;
    }
    while (this->khuVucXuatBan<0 || this->khuVucXuatBan>1)
    {
        cout<<endl<<"nhap khu vuc xuat ban CTKH:(0): trong nuoc  (1): quoc te ";
        cin>>this->khuVucXuatBan;
    }
}
void CongTrinhKhoaHoc::setMaCongTrinh(string _maCT)
{
    this->maCongTrinh=_maCT;
}
void CongTrinhKhoaHoc::setNamXuatBan(int _namXB)
{
    while(_namXB<1900)
    {
        cout<<"nhap nam xuat ban tu 1900 ve sau CTKH: ";
        cin>>_namXB;
    }
    this->namXuatBan=_namXB;
}
void CongTrinhKhoaHoc::setKhuVucXuatBan(bool b)
{
    this->khuVucXuatBan = b;
}
string CongTrinhKhoaHoc::getMaCongTrinh()
{
    return maCongTrinh;
}