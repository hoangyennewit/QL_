#include<bits/stdc++.h>
using namespace std;

class Mang{
    private:   
        vector <int> arr;
    public:
        Mang(){}
        Mang(vector<int> a){
            arr = a;
        }
        void XoaX(int x) {
            for (auto it = arr.begin(); it != arr.end();){
                if (*it == x) {
                    it = arr.erase(it);
                } else 
                {
                    ++it;
                }
            }
        }

        void XuatMang(){
            for(int x: arr){
                cout << x <<" ";
            }
            cout << endl;
        }
};

int main(){
    int n;
    int x;
    do {
        //cout << "nhap gia tri n: ";
        cin >> n;
        if (n <= 0 || !cin) {
        //cout << "So luong phan tu phai la so nguyen duong. Vui long nhap lai."<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while (n<= 0|| !cin);
    vector <int> v;
    for(int i = 0; i < n; i++){
        int k;
        do{
            //cout << "nhap phan tu " << i + 1  <<": ";
            cin >> k;
            if (!cin) {
                //cout << "Gia tri khong hop le. Vui long nhap lai."<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }while (!cin);
        v.push_back(k);
    }
    Mang k(v);
    do{
        //cout << "Nhap gia tri x: ";
        cin >> x;
        if (!cin) {
                //cout << "Gia tri khong hop le. Vui long nhap lai."<<endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }while (!cin);
    k.XoaX(x);
    k.XuatMang();
    return 0;
}