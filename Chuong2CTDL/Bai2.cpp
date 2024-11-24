#include<bits/stdc++.h>
using namespace std;

class TimKiem{
    private:
        vector <int> Arr;
    public:
        TimKiem(){}
        TimKiem(vector <int> v){
            Arr = v;
        }
        void ThemPhanTuMang(int n){
            for(int i = 0; i < n; i ++){
                int x;
                //cout <<"nhap phan tu thu " << i + 1 <<" : ";
                cin >> x;
                Arr.push_back(x);
            }
        }
        vector<int> LinearSearch(int x){
            vector <int> newArr;
            for(int i = 0; i < Arr.size(); i ++){
                if(Arr[i] == x){
                    newArr.push_back(i);
                }
            }
            return newArr;
        }
        void XuatMang(int x) {
            vector<int> kq = LinearSearch(x);
            if (kq.empty()) {
                //cout << "Khong tim thay gia tri " << x << " trong mang." << endl;
            } else {
                //cout << "Vi tri cua gia tri can tim la: ";
                for (int pos : kq) {
                    cout << pos << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int n;
    vector<int> k;

    do {
        //cout << "Nhap so luong phan tu: ";
        cin >> n;
        if (n <= 0 || !cin) {
            //cout << "So luong phan tu phai la so nguyen duong. Vui long nhap lai." << endl;
            cin.clear();  
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  
        }
    }while (n <= 0 || !cin);

    TimKiem TK(k);

    TK.ThemPhanTuMang(n);

    int x;
    do {
        //cout << "\nNhap gia tri can tim: ";
        cin >> x;
        if (!cin) {
            //cout << "Gia tri khong hop le. Vui long nhap lai!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    } while (!cin);

    TK.XuatMang(x);
    return 0;
}