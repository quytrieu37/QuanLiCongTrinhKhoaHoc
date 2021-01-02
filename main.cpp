#include"ListCTKH.cpp"
int main()
{
    int choose=-1;
    bool dungmain=false;
    ListCTKH<CongTrinhKhoaHoc> list("nguyen quy trieu");
    while(dungmain==false)
    {
        cout<<endl;
        cout<<"CHUONG TRINH QUAN LI CONG TRINH KHOA HOC\n";
        cout<<"****************************************\n";
        cout<<"**   1.Them cong trinh khoa ho        **\n";
        cout<<"**   2.Sua tai vi tri.                **\n";
        cout<<"**   3.Xoa cong trinh khoa hoc.       **\n";
        cout<<"**   4.Hien thi danh sach CTKH.       **\n";
        cout<<"**   5.Tim kiem theo ma cong trinh.   **\n";
        cout<<"**   6.Sap xep danh sach CTKH.        **\n";
        cout<<"**   0.Thoat.                         **\n";
        cout<<"****************************************\n";
        while(cout<<"nhap lua chon: " && !(cin>>choose))
            {
                cin.clear();
                cin.ignore();
                cout<<"dau vao khong hop le!";
            }
        cout<<"\n\n";
        switch (choose)
        {
        case 1:
            list.Input();
            break;
        case 2:
            list.Update();
            break;
        case 3:
            list.Remove();
            break;
        case 4:
            list.ShowList();
            break;
        case 5:
            list.Find();
            break;
        case 0:
            cout<<"Ban da thoat chuong trinh!";
            cout<<"Hen gap lai!";
            dungmain= true;
            break;
        default:
            cout<<"Dau vao khong hop le hay nhap lai!";
            break;
        }
    }
    return 0;
}