#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

class BinarySearch{
    private:
    vector<int> arr;
    public:
    BinarySearch(const vector<int>& array) : arr(array) {}
    int tkNhiPhan (int n, int x, int &i) {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = l + r >> 1;
            if (arr[m] == x) {
                return m;
            }
            else if (arr[m] > x) {
                i++;
                r = m - 1;
            }
            else {
                i++;
                l = m + 1;
            }
        }
        return -1;
    }
    void Search(int n, int x, int count){
        if (tkNhiPhan(n, x, count) == -1) {
            cout << "Khong tim thay";
        }
        else {
            cout << "So lan chia doi cua mang: " << count << '\n';
            int l = 0, r = n - 1, j = 1;
            while (l <= r) {
                int m = l + r >> 1;
                if (arr[m] == x) break;
                else {
                    cout << "Lan " << j++ << ": x = " << x << " nam trong doan [";
                    if (arr[m] > x) {
                        cout << l << ".." << m - 1;
                        r = m - 1;
                    }
                    else {
                        cout << m + 1 << ".." << r;
                        l = m + 1;
                    }
                        cout << "]" << " // mid = " << m << '\n';
                }
            }
        }
    }
};
int main(){
    int n, x;
    //cout << "Nhap so luong phan tu cua mang: " ;
    cin >> n;
    if (n <= 0 || !cin ){
        //cout << " So luong phan tu khong hop le. Vui long nhap lai.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while (n<=0 || !cin);
    
    vector<int> arr(n);
    
    //cout << "Nhap cac phan tu cua mang: ";
    for ( int i = 0; i<n; ++i){
        while (!(cin >> arr[i])){
            //cout << " Gia tri khong hop le. Vui long nhap so nguyen: "<<endl;
            cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    //cout << "Nhap gia tri can tim: ";
    while (!(cin >> x)){
        //cout << "Gia tri khong hop le. Vui long nhap so nguyen: "<<endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    BinarySearch binarySearch(arr);
    binarySearch.Search(n, x, 0);
    return 0;

}