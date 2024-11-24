#include<bits/stdc++.h>
using namespace std;

template<class DataType>
class Stack;

template<class DataType>
class Node {
    private:
        DataType data;
        Node<DataType>* next;
        friend class Stack<DataType>;
    public:
        Node(DataType data) : data(data), next(NULL) {}
};

template<class DataType>
class Stack {
    private:
        Node<DataType>* p;
    public:
        Stack() : p(nullptr) {}

        bool empty () const {
            return !p;
        }

        int size () const {
            if (empty()) {
                return 0;
            }
            int result(0);
            for (Node<DataType>* tmp = p; tmp != NULL; p = p->next) {
                result += 1;
            }
            return result;
        }

        void push (const DataType& data) {
            if (empty()) {
                p = new Node(data);
                return;
            }
            Node<DataType>* newTop = new Node(data);
            newTop->next = p;
            p = newTop;
        }

        void pop () {
            if (empty()) {
                return;
            }
            Node<DataType>* tmp = p;
            p = p->next;
            delete tmp;
        }

        DataType& top () const {
            if (empty()) {
                cout << "Empty!\n";
                exit(0);
            }
            return p->data;
        } 

        void display () {
            if (empty()) {
                cout << "Empty!\n";
                exit(0);
            }
            for (Node<DataType>* top = p; top != NULL; top = top->next) {
                cout << top->data << ' ';
            }
            cout << '\n';
        }

        void clear () {
            while (!empty()) {
                pop();
            }
        }

        ~Stack() {
            clear();
        }
};

void quickSort (vector<int>& arr, int left, int right) {
    Stack<pair<int, int>> s;
    s.push({left, right});
    auto partition = [&](vector<int>& arr, int l, int r) {
        int i = l - 1, j = r + 1;
        int pivot = arr[l];
        while (true) {
            do { --j; } while (arr[j] > pivot);
            do { ++i; } while (arr[i] < pivot);
            if (i >= j) {
                return j;
            }
            else {
                swap(arr[i], arr[j]);
            }
        }
    };
    while (!s.empty()) {
        pair<int, int> rmd = s.top();
        s.pop();
        if (rmd.first < rmd.second) {
            int p = partition(arr, rmd.first, rmd.second);
            if (p > rmd.first) {
                s.push({rmd.first, p});
            }
            if (p < rmd.second) {
                s.push({p + 1, rmd.second});
            }
        }
    }
}

int main () {
    vector<int> arr;
    int n; 
    cout << "Nhap so luong phan tu: ";
    cin >> n;
    arr.resize(n);
    cout << "Nhap phan tu cho Stack: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);
    cout << "Phan tu sau khi da duoc sap xep:\n";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    return 0;
}