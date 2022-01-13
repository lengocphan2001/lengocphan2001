#include<bits/stdc++.h>
using namespace std;

class NumberArray{
public:
    double *arr;
    NumberArray(){
    }
    void create(int n){
        arr = new double[n];
        for (int i = 0; i<n; i++)
            &arr[i] = 0.0;
    }
    ~NumberArray(){
        delete[] arr;
    }
    void createArr(int n, double def){
        arr = new double[n];
        for (int i = 0; i<n; i++)
            *arr[i] = def;
    }
    int getSize(){
        return (sizeof(arr) / sizeof(*(arr)));
    }
    double get(int i){
        return arr[i-1];
    }
    void setValue(int i, double x){
        if (i > getSize()){
            cout << "Khong the thay the!";
        }else{
            cout << "Thay the thanh cong!";
            *arr[i-1] = x;
        }
    }
    int getArgMax(){
        int position = 0, n = getSize();
        for (int i = 1; i<n; i++){
            if (arr[i] > arr[position])
                position = i;
        }
        return position;
    }
    int getArgMin(){
        int position = 0, n = getSize();
        for (int i = 1; i<n; i++){
            if (arr[i] < arr[position])
                position = i;
        }
        return position;
    }
    void print(){
        int n = getSize();
        cout << "So luong phan tu: " << n << endl;
        for (int i = 0; i<n; i++){
            cout << "Phan tu thu "<< i + 1 << ": " << arr[i] << endl;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 5;
    double x = 10;
    cout << "Khoi tao mang co doi so truyen vao la n"<< endl;
    NumberArray a;
    a.create(n);
    a.print();
    cout << "Khoi tao mang co doi so truyen vao la n va so thuc x"<< endl;
    NumberArray b;
    b.createArr(n, x);
    b.print();
    cout << "Kich thuoc cua mang: " << b.getSize() << endl;
    cout << "Phan tu thu 2 trong mang: " << b.get(2) << endl;
    cout << "Phan tu thu 10 trong mang: " << b.get(10) << endl;
    cout << "Thay the gia tri tai vi tri thu 3 bang 15"<<endl;
    b.setValue(3, 15.0);
    cout << "Phan tu co gia tri lon nhat trong mang: "<< b.getArgMax() << endl;
    cout << "Phan tu co gia tri nho nhat trong mang: "<< b.getArgMin() << endl;

}
