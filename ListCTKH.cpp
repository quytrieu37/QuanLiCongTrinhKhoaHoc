#include"ListCTKH.h"
template<class T>
ListCTKH<T>::ListCTKH()
{
    this->data=nullptr;
    this->soLuongCTKH=0;
    this->tenTacGia="";
}
template<class T>
ListCTKH<T>::ListCTKH(string _tenTacGia)
{
    this->soLuongCTKH=0;
    this->tenTacGia=_tenTacGia;
    this->data= nullptr;
}
template<class T>
ListCTKH<T>::~ListCTKH()
{
    delete[] this->data;
}
template<class T>
const CongTrinhKhoaHoc ListCTKH<T>::operator[](const int index)
{
    if(index <0 || index >= this->soLuongCTKH)
    {
        throw "invalid index!";
    }
    return this->data+index;
}
template<class T>
void ListCTKH<T>::operator=(const ListCTKH& l)
{
    this->soLuongCTKH =l.soLuongCTKH;
    this->tenTacGia = l.tenTacGia;
    this->data= new T*[this->soLuongCTKH];
    for(int i=0;i<l.soLuongCTKH;++i)
    {
        this->data[i] = l.data[i];
    }
}

template<class T>
void ListCTKH<T>::Add(T *ct)
{
    if(this->soLuongCTKH ==0)
    {
        this->data = new T*[this->soLuongCTKH+1];
        this->data[this->soLuongCTKH] = ct;
    }
    else
    {
        T **temp =new T*[this->soLuongCTKH];
        for(int i =0; i<this->soLuongCTKH;++i)
        {
            // temp[i] = this->data[i];
            *(temp +i) = *(this->data+i);
        }

        this->data= new T*[this->soLuongCTKH+1];

        for(int i=0;i<this->soLuongCTKH;++i)
        {
            *(this->data+ i) = *(temp +i);
        }
        *(this->data + this->soLuongCTKH)= ct;
        delete[] temp;
    }
    this->soLuongCTKH++;
}

template<class T>
void ListCTKH<T>::Input()
{
    int loai=0;
    T *ct;
    while(loai<1 || loai > 2)
    {
        while(cout<<"Loai cong trinh: (1): bai bao (2): sach: " && !(cin>> loai))
        {
            cin.clear();
            cin.ignore();
            cout<<"Dau vao sai moi nhap lai!";
        }
    }
    if(loai == 1)
    {
        ct = new BaiBao();
        ct->Nhap();
        this->Add(ct);
    }
    if(loai ==2)
    {
        ct = new Sach();
        ct->Nhap();
        this->Add(ct);
    }
}


template<class T>
void ListCTKH<T>::Remove()
{
    int index;
    while(cout<<"Nhap vi tri can xoa: " && !(cin>> index))
    {
        cin.clear();
        cin.ignore();
        cout<<"Dau vao khong hop le moi nhap lai!"<<endl;
    }
    if(index >= 0 && index < this->soLuongCTKH)
    {
        T **temp= new T*[this->soLuongCTKH];
        for(int i=0;i<this->soLuongCTKH;++i)
        {
            temp[i]=this->data[i];
        }
        this->data= new T*[this->soLuongCTKH-1];
        for(int i=0;i<this->soLuongCTKH;++i)
        {
            this->data[i] = temp[i];
        }
        for(int i=index; i<this->soLuongCTKH;++i)
        {
            this->data[i] = temp[i+1];
        }
        cout<<"Da xoa cong trinh khoa hoc co ma: "<<index<<endl;
        delete[] temp;
        this->soLuongCTKH--;
    }
    else 
    {
        cout<<"Dau vao khong hop le!"<<endl;
    }
}
template<class T>
void ListCTKH<T>::ShowList()
{
    for(int i=0; i<this->soLuongCTKH;++i)
    {
        this->data[i]->Show();
        cout<<"------------------------------------------"<<endl;
        cout<<"------------------------------------------"<<endl;
        cout<<"------------------------------------------"<<endl;
    }
}
template<class T>
int ListCTKH<T>::Find()
{
    string _ma;
    cout<<"Nhap ma cong trinh can tim: ";
    fflush(stdin);
    getline(cin, _ma);
    for(int i=0;i<this->soLuongCTKH;++i)
    {
        if(this->data[i]->getMaCongTrinh() == _ma)
        {
            cout<<"\nVi tri cua cong trinh: "<<i;
            cout<<"\n";
            return i;
        }
    }
        cout<<"Khong tim thay doi tuong tren moi kiem tra lai!"<<endl;
        return this->Find();
}

template<class T>
void ListCTKH<T>::Update()
{
    int index = this->Find();
    this->data[index]->Show();
    cout<<"\nNhap truong can thay doi: \n"<<endl;
    if(BaiBao* bb = dynamic_cast<BaiBao*>(data[index]))
    {
        bool dung= false;
        int chon=-1;
        while (dung ==false)
        {
            cout<<endl;
            cout<<"** 1.Ma bai bao.         **\n";
            cout<<"** 2.Ten bai bao.        **\n";
            cout<<"** 3.So luong tac gia.   **\n";
            cout<<"** 4.Nam xuat ban.       **\n";
            cout<<"** 5.Khu vuc xuat ban.   **\n";
            cout<<"** 6.Tat ca.             **\n";
            cout<<"** 0.Dung update         **\n";
            while(cout<<"nhap lua chon: " && !(cin>>chon))
            {
                cin.clear();
                cin.ignore();
                cout<<"dau vao khong hop le!";
            }
            cout<<"\n";
            switch (chon)
            {
            case 1:
            {
                string mact;
                cout<<"Nhap ma cong trinh";
                cin.ignore();
                getline(cin,mact);
                this->data[index]->setMaCongTrinh(mact);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
                
            case 2:
            {
                string tenct;
                cout<<"Nhap ten cong trinh";
                cin.ignore();
                getline(cin, tenct);
                static_cast<BaiBao*>(this->data[index])->setTenCongTrinh(tenct);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 3:
            {
                int sotg;
                while(cout<<"nhap so tac gia: " && !(cin>> sotg))
                {
                    cin.clear();
                    cin.ignore();
                    cout<<"dau vao khong hop le!";
                }
                static_cast<BaiBao*>(this->data[index])->setSoTacGia(sotg);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 4: 
            {
                int namxb=1900;
                while(namxb < 1990)
                {
                    while(cout<<"\nnhap nam xuat ban: "&& !(cin>>namxb))
                    {
                        cin.clear();
                        cin.ignore();
                        cout<<"dau vao khong hop le!";
                    }
                }
                this->data[index]->setNamXuatBan(namxb);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 5:
            {
                bool kvxb=-1;
                while(kvxb<0 || kvxb >1)
                {
                    while(cout<<"Nhap khu vuc xuat ban: (0) trong nuoc (1) quoc te: " && !(cin>>kvxb))
                    {
                        cin.clear();
                        cin.ignore();
                        cout<<"dau vao khong hop le!";
                    }
                }
                this->data[index]->setKhuVucXuatBan(kvxb);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 6:
            {
                this->data[index]->Nhap();
                this->data[index]->Show();
                break;     
            }
            case 0:
            {
                cout<<"Hoan thanh update!"<<endl;
                dung =true;
                break;
            }
            default:
            {
                cout<<"Nhap sai moi nhap lai";
                break;
            }
            }
        }
    }
    else
    {
        bool dung2 = false;
        int chon2=-1;
        while (dung2 == false)
        {
            cout<<endl;
            cout<<"** 1.Ma sach.            **\n";
            cout<<"** 2.Loai sach.          **\n";
            cout<<"** 3.Nam xuat ban.       **\n";
            cout<<"** 4.Khu vuc xuat ban.   **\n";
            cout<<"** 5.Tat ca.             **\n";
            cout<<"** 0.Dung update         **\n";
            while(cout<<"nhap lua chon: " && !(cin>>chon2))
            {
                cin.clear();
                cin.ignore();
                cout<<"dau vao khong hop le!";
            }
            switch (chon2)
            {
            case 1:
            {
                string mact;
                cout<<"Nhap ma cong trinh";
                cin.ignore();
                getline(cin,mact);
                this->data[index]->setMaCongTrinh(mact);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 2:
            {
                string loaisach;
                cout<<"Nhap loai sach";
                cin.ignore();
                getline(cin, loaisach);
                static_cast<Sach*>(this->data[index])->setLoaiSach(loaisach);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 3:
            {
                int namxb=1900;
                while(namxb < 1990)
                {
                    while(cout<<"\nnhap nam xuat ban: "&& !(cin>>namxb))
                    {
                        cin.clear();
                        cin.ignore();
                        cout<<"dau vao khong hop le!";
                    }
                }
                this->data[index]->setNamXuatBan(namxb);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 4:
            {
                bool kvxb=-1;
                while(kvxb<0 || kvxb >1)
                {
                    while(cout<<"Nhap khu vuc xuat ban: (0) trong nuoc (1) quoc te: " && !(cin>>kvxb))
                    {
                        cin.clear();
                        cin.ignore();
                        cout<<"dau vao khong hop le!";
                    }
                }
                this->data[index]->setKhuVucXuatBan(kvxb);
                this->data[index]->Show();
                cout<<endl;
                break;
            }
            case 5:
            {
                this->data[index]->Nhap();
                this->data[index]->Show();
                break;   
            }  
            case 0:
            {
                cout<<"Hoan thanh update!"<<endl;
                dung2=true;
                break;
            }
            default:
            {
                cout<<"Nhap sai moi nhap lai";
                break;
            }
            }
        }
    }
}

