#include<bits/stdc++.h>
using namespace std;

struct DanhSach{
    int a[100];
    int last;
};
void makeNull(DanhSach &l){
    l.last = 0;
}
int emptyList(DanhSach l){
    if (l.last == 0)
        return 0;
    return 1;
}
void insertDanhSach(DanhSach &l){
    cout << "Nhap so phan tu cua day: ";
    cin >> l.last;
    if (l.last > 100){
        cout << "Danh sach day!";
    }else{
        for (int i = 0; i<l.last; i++){
            cout << "Nhap phan tu thu " << i + 1 << ":";
            cin >> l.a[i];
        }
        cout << endl;
    }
}
void hienDanhSach(DanhSach l){
    if (emptyList(l) == 0)
        cout << "Danh sach rong!";
    else{
        for (int i = 0;i <l.last; i++){
            cout << "Phan tu "<< i + 1 << ": " << l.a[i] << endl;
        }
        cout << endl;
    }
}
void nhapX(int &x){
    cout << "Nhap gia tri muon tim kiem: ";
    cin >> x;
}
void timKiem(DanhSach l, int x){
    vector<int> ans;
    int dem = 0;
    for (int i = 0; i<l.last; i++){
        if (l.a[i] == x){
            dem++;
            ans.push_back(i+1);
        }
    }
    if (dem > 0){
        cout << "So lan xuat hien cua " << x << " la: " << dem << " lan" << endl;
        cout << "Cac vi tri xuat hien cua " << x << " la: ";
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }else
        cout << x << " khong xuat hien trong day" << endl;
}
void menu(DanhSach &l, int &x){
    int choose = 0;
    while(choose != 6){
        cout << "1. Khoi tao danh sach so nguyen" << endl;
        cout << "2. Nhap sanh sach" << endl;
        cout << "3. Hien danh sach" << endl;
        cout << "4. Nhap gia tri x" <<endl;
        cout << "5. Tim kiem" << endl;
        cout << "6. Thoat" << endl;
        cout << "Moi chon chuc nang: ";
        cin >> choose;
        switch(choose){
        case 1:
            makeNull(l);
            break;
        case 2:
            insertDanhSach(l);
            break;
        case 3:
            hienDanhSach(l);
            break;
        case 4:
            nhapX(x);
            break;
        case 5:
            timKiem(l, x);
            break;
        default:
            break;
        }
    }
}
int main()
{
    int x;
    DanhSach l;
    menu(l, x);
}
