#include"BaiBao.h"
BaiBao::BaiBao()
{

}
BaiBao::BaiBao(string _tenCongTrinh, int _soTacGia) : tenCongTrinh(_tenCongTrinh), soTacGia(_soTacGia)
{

}
BaiBao::~BaiBao()
{

}
void BaiBao::Show()
{
    cout<<"Ma bai bao: "<<this->maCongTrinh<<endl;
    cout<<"Ten bai bao: "<<this->tenCongTrinh<<endl;
    cout<<"So luong tac gia: "<<this->soTacGia<<endl;
    cout<<"Nam xuat ban: "<<this->namXuatBan<<endl;
    cout<<"Khu vuc xuat ban: ";
    if(this->khuVucXuatBan==1)
    cout<<"quoc te";
    else
    cout<<"trong nuoc";
    cout<<endl;
}

void BaiBao::Nhap()
{
    cout<<"\nNhap ma bai bao: ";
    cin.ignore();
    getline(cin,this->maCongTrinh);
    
    cout<<endl<<"Nhap ten bai bao: ";
	getline(cin, this->tenCongTrinh);
    this->namXuatBan=1900;
    while(this->namXuatBan <1990)
    {
        while(cout<<endl<<"Nhap nam xuat ban, tu 1990 den nay: " && !(cin>>this->namXuatBan))
        {
            cin.clear();
            cin.ignore();
            cout<<"Dau vao sai nhap lai!";
        }
    }
    

    while(cout<<endl<<"Nhap khu vuc xuat ban:(0): trong nuoc  (1): quoc te " && !(cin>> this->khuVucXuatBan || this->khuVucXuatBan<0 || this->khuVucXuatBan>1))
    {
        cin.clear();
        cin.ignore();
        cout<<"Dau vao sai nhap lai!";
    }
    while(cout<<endl<<"Nhap so tac gia: " && !(cin>> this->soTacGia))
    {
        cin.clear();
        cin.ignore();
        cout<<"Dau vao sai moi nhap lai!";
    }
}
void BaiBao::setTenCongTrinh(string _tenCT)
{
    this->tenCongTrinh= _tenCT;
}
void BaiBao::setSoTacGia(int _soTG)
{
    this->soTacGia= _soTG;
}