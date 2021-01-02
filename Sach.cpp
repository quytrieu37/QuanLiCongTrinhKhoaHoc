#include"Sach.h"
Sach::Sach()
{

}
Sach::Sach(string _loaiSach) : loaiSach(_loaiSach)
{

}
Sach::~Sach()
{

}
void Sach::Show()
{
    cout<<"\nMa sach: "<<this->maCongTrinh<<endl;
    cout<<"Nam xuat ban: "<<this->namXuatBan<<endl;
    cout<<"Khu vuc xuat ban: ";
    if(this->khuVucXuatBan==1)
    cout<<"quoc te";
    else
    cout<<"trong nuoc";
    cout<<endl;
    cout<<"Loai sach: "<<this->loaiSach<<endl;
}
void Sach::Nhap()
{
    cout<<"Nhap ma sach: ";
    cin.ignore();
    getline(cin,this->maCongTrinh);
    this->namXuatBan=1900;
    while(this->namXuatBan<1990)
    {
        while(cout<<endl<<"Nhap nam xuat ban, tu 1990 den nay: " && !(cin>> this->namXuatBan))
        {
            cin.clear();
            cin.ignore();
            cout<<"Dau vao sai moi nhap lai!";
        }
    }
    while (this->khuVucXuatBan<0 || this->khuVucXuatBan>1)
    {
        while(cout<<endl<<"Khu vuc xuat ban: (0): trong nuoc  (1): quoc te " && !(cin>> this->khuVucXuatBan))
        {
            cin.clear();
            cin.ignore();
            cout<<"Dau vao sai moi nhap lai!";
        }
    }
    
    cout<<"Nhap loai sach: ";
    cin.ignore();
    getline(cin,this->loaiSach);
}
void Sach::setLoaiSach(string _LS)
{
    this->loaiSach=_LS;
}