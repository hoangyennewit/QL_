#include<bits/stdc++.h>
using namespace std;

bool isPerfectNum(int n) {
    int sum = 0;
    for (int i = 1; i <= n / 2; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum == n;
}

bool isPrime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return n > 1;
}

bool isSquareNum(int n) {
    return int(sqrt(n)) == sqrt(n);
}

class Node {
private:
    int data;
    Node* next;
public:
    Node() : data(0), next(NULL) {}
    Node(int data) : data(data), next(NULL) {}
    friend class LinkedList;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(NULL) {}
    void printList() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
    }
    void push_back(int value) {
        if (!head) {
            head = new Node(value);
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node(value);
    }
    void printPrimeNum() {
        Node* curr = head;
        bool found = false;
        while (curr) {
            if (isPrime(curr->data)) {
                found = true;
                cout << curr->data << ' ';
            }
            curr = curr->next;
        }
        if (!found) {
            cout << "Danh sach khong co so nguyen to!";
        }
    }
    int size() {
        int count(0);
        Node* curr = head;
        while (curr) {
            count += 1;
            curr = curr->next;
        }
        return count;
    }
    void clear() {
        Node* ptr;
        while (head) {
            ptr = head;
            head = head->next;
            delete ptr;
        }
    }
    double average() {
        int n = this->size();
        int sum = 0;
        Node* curr = head;
        while (curr) {
            sum += curr->data;
            curr = curr->next;
        }
        return (double)sum * 1.0 / n;
    }
    int count(int value) {
        int countNum = 0;
        Node* curr = head;
        while (curr) {
            countNum += (curr->data == value);
            curr = curr->next;
        }
        return countNum;
    }
    int lastSquare() {
        Node* curr = head;
        int result = -1;
        while (curr) {
            if (isSquareNum(curr->data)) {
                result = curr->data;
            }
            curr = curr->next;
        }
        return result;
    }
    int findPostition(int k) {
        Node* curr = head;
        int n = this->size();
        if (k < 1 || k > n) {
            return -1;
        }
        for (int i = 1; i < k; ++i) {
            curr = curr->next;
        }
        return curr->data;
    }
    int minElement() {
        int result = head->data;
        Node* curr = head;
        while (curr) {
            result = min(result, curr->data);
            curr = curr->next;
        }
        return result;
    }
    void insert(int q, int value) {
        Node* prev = head;
        while (prev) {
            if (prev->data == q) {
                Node* newNode = new Node(value);
                newNode->next = prev->next;
                prev->next = newNode;
                prev = prev->next;
            }
            else {
                prev = prev->next;
            }
        }
    }
    bool found(int value) {
        Node* curr = head;
        while (curr) {
            if (curr->data == value) {
                return true;
            }
            curr = curr->next;
        }
        return false;
    }
    bool pushRandom(int value) {
        if (!this->found(value)) {
            this->push_back(value);
            return true;
        }
        return false;
    }
    void remove_K_element(int k) {
        while (k--) {
            if (!head) {
                head = nullptr;
                return;
            }
            head = head->next;
        }
    }
    void removeValue(int x) {
        Node* curr = head;
        while (curr != nullptr && curr->data == x) curr = curr->next;
        while (curr != nullptr && curr->next != nullptr) {
            if (curr->next->data == x) {
                Node* next = curr->next;
                curr->next = next->next;
                delete next;
            }
            else {
                curr = curr->next;
            }
        }
    }
    void remove(int q) {
        Node* prev = head;
        Node* curr = prev->next;
        while (prev->next) {
            if (prev->data == q) {
                Node* next = prev->next;
                prev->next = next->next;
                delete next;
                prev = prev->next;
            }
            else {
                prev = prev->next;
            }
        }
    }
    void interchangeSort() {
        for (Node* prev = head; prev->next != nullptr; prev = prev->next)
            for (Node* next = prev->next; next != nullptr; next = next->next)
                if (prev->data > next->data)
                    swap(prev->data, next->data);
    }
    void remove_duplicate_elements() {
        LinkedList newList;
        Node* ptr = this->head;
        while (ptr != nullptr) {
            if (!newList.found(ptr->data)) {
                newList.push_back(ptr->data);
            }
            ptr = ptr->next;
        }
        this->clear();
        Node* temp = newList.head;
        while (temp) {
            this->push_back(temp->data);
            temp = temp->next;
        }
    }
    void push_element_into_sortedList(int value) {
        Node* newNode = new Node(value);
        if (head->data > value) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* prev = head;
        Node* curr = prev->next;
        while (curr != nullptr && curr->data <= value) {
            prev = prev->next;
            curr = curr->next;
        }
        newNode->next = curr;
        prev->next = newNode;
    }
    void update() {
        Node* curr = head;
        while (curr) {
            if (isPerfectNum(curr->data)) {
                curr->data = 0;
            }
            curr = curr->next;
        }
    }
    ~LinkedList() {
        this->clear();
    }
};

void Menu() {
    LinkedList myList;
    while (true) {
        system("cls");
        cout << "_________________________MENU_________________________" << endl;
        cout << "a. Them phan tu vao cuoi danh sach" << endl;
        cout << "b. In danh sach" << endl;
        cout << "c. Liet ke so nguyen to trong danh sach" << endl;
        cout << "d. Tinh trung binh cong" << endl;
        cout << "e. Dem so lan xuat hien cua 1 so nguyen" << endl;
        cout << "f. So chinh phuong cuoi cung trong danh sach" << endl;
        cout << "g. Phan tu thu k trong danh sach" << endl;
        cout << "h. Min" << endl;
        cout << "i. Them 1 phan tu sau q" << endl;
        cout << "j. Them 1 phan tu ngau nhien khong co trong danh sach" << endl;
        cout << "k. Xoa k phan tu dau tien" << endl;
        cout << "l. Xoa phan tu co gia tri x" << endl;
        cout << "m. Xoa 1 phan tu sau q" << endl;
        cout << "n. Xoa cac phan tu bi trung lap" << endl;
        cout << "o. Sap xep danh sach tang dan" << endl;
        cout << "p. Them 1 phan tu vao danh sach tang dan" << endl;
        cout << "q. Cap nhat lai cac so hoan thien" << endl;
        cout << "!. Thoat chuong trinh\n";
        cout << "_____________________________________________________" << endl;
        cout << "Nhap lua chon: ";
        char luachon; cin >> luachon;
        if (luachon == 'a') {
            int n;
            cout << "So phan tu can them: "; cin >> n;
            cout << "List: ";
            for (int i = 1; i <= n; ++i) {
                int val; cin >> val;
                myList.push_back(val);
            }
            cout << "Chuc mung ban da them thanh cong!\n";
        }
        else if (luachon == 'b') {
            myList.printList();
            cout << '\n';
        }
        else if (luachon == 'c') {
            myList.printPrimeNum();
            cout << '\n';
        }
        else if (luachon == 'd') {
            cout << "Average: " << myList.average() << '\n';
        }
        else if (luachon == 'e') {
            int val;
            cout << "Nhap so nguyen: "; cin >> val;
            cout << "So lan xuat hien: " << myList.count(val) << '\n';
        }
        else if (luachon == 'f') {
            int answer = myList.lastSquare();
            if (answer == -1) {
                cout << "Khong co so chinh phuong trong danh sach!\n";
            }
            else {
                cout << "So chinh phuong cuoi cung: " << answer << '\n';
            }
        }
        else if (luachon == 'g') {
            int k;
            cout << "Vi tri: "; cin >> k;
            cout << "Phan tu vi tri thu " << k << " la: " << myList.findPostition(k) << '\n';
        }
        else if (luachon == 'h') {
            cout << "Min = " << myList.minElement() << '\n';
        }
        else if (luachon == 'i') {
            int val, q;
            cout << "Gia tri can them: "; cin >> val;
            cout << "Them vao sau phan tu co gia tri: "; cin >> q;
            myList.insert(q, val);
        }
        else if (luachon == 'j') {
            while (true) {
                srand(time(0));
                int val = rand() % 100;
                if (!myList.found(val)) {
                    myList.push_back(val);
                    break;
                }
            }
        }
        else if (luachon == 'k') {
            int k;
            cout << "So phan tu can xoa: "; cin >> k;
            myList.remove_K_element(k);
        }
        else if (luachon == 'l') {
            int x;
            cout << "Xoa phan tu co gia tri: "; cin >> x;
            myList.removeValue(x);
        }
        else if (luachon == 'm') {
            int q;
            cout << "Sau phan tu co gia tri: "; cin >> q;
            myList.remove(q);
        }
        else if (luachon == 'n') {
            myList.remove_duplicate_elements();
            cout << "Xoa thanh cong!\n";
        }
        else if (luachon == 'o') {
            myList.interchangeSort();
        }
        else if (luachon == 'p') {
            int val;
            cout << "Phan tu can them: "; cin >> val;
            myList.push_element_into_sortedList(val);
            cout << "Them thanh cong!\n";
        }
        else if (luachon == 'q') {
            myList.update();
            cout << "Da cap nhat!\n";
        }
        else if (luachon == '!') {
            myList.clear();
            break;
        }
        system("pause");
    }
}

int main() {
	Menu();
    return 0;
}