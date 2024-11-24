/*
#include <bits/stdc++.h>
using namespace std;

class Node {
    private:
        int data;
        Node* next;
        friend class LinkedList;
    public:
        Node(int data) : data(data), next(NULL) {}
};

class LinkedList {
    private:
        Node* root;
    public:
        LinkedList() : root(nullptr) {}
        bool empty() {
            return !root;
        }
        void push_back (int x) {
            if (empty()) {
                root = new Node(x);
                return;
            }
            Node* curr = root;
            while (curr->next) curr = curr->next;
            curr->next = new Node(x);
        }
        void push_front (int x) {
            if (empty()) {
                root = new Node(x);
                return;
            }
            Node* newNode = new Node(x);
            newNode->next = root;
            root = newNode;
        }
        void pop_back () {
            if (empty()) {
                return;
            }
            if (!root->next) {
                delete root;
                root = nullptr;
                return;
            }
            Node* rmd = root;
            while (rmd->next->next) rmd = rmd->next;
            Node* ptr = rmd->next;
            rmd->next = nullptr;
            delete ptr;
        }
        void pop_front () {
            if (empty()) {
                return;
            }
            Node* rmd = root;
            root = root->next;
            delete rmd;
        }
        void display () {
            for (Node* p = root; p != nullptr; p = p->next) {
                cout << p->data << ' ';
            }
            cout << '\n';
        }
        void clear () {
            while (!empty()) {
                pop_front();
            }
        }
        bool found (int x) const {
            for (Node* p = root; p != nullptr; p = p->next) {
                if (p->data == x) {
                    return true;
                }
            }
            return false;
        }
        int SUM () const {
            int sum(0);
            for (Node* p = root; p != nullptr; p = p->next) {
                sum += p->data;
            }
            return sum;
        }
        int MAX () const {
            int ans(root->data);
            for (Node* p = root->next; p != nullptr; p = p->next) {
                ans = max(ans, p->data);
            }
            return ans;
        }
        //Phép nối
        LinkedList connectionList (const LinkedList& L1, const LinkedList& L2) {
            LinkedList L3;
            for (Node* p = L1.root; p != nullptr; p = p->next) {
                L3.push_back(p->data);
            }
            for (Node* p = L2.root; p != nullptr; p = p->next) {
                L3.push_back(p->data);
            }
            return L3;
        }
        //Phép hiệu
        LinkedList List_difference (const LinkedList& L1, const LinkedList& L2) {
            LinkedList L3;
            for (Node* current = L1.root; current != nullptr; current = current->next)
                if (!L2.found(current->data)) 
                    L3.push_back(current->data);

            return L3;
        }
        //Phép giao
        LinkedList List_intersection (const LinkedList& L1, const LinkedList& L2) {
            LinkedList L3;
            for (Node* current = L1.root; current != nullptr; current = current->next) {
                if (L2.found(current->data)) {
                    L3.push_back(current->data);
                }
            }
            return L3;
        }
        //Phép hợp
        LinkedList List_union (const LinkedList& L1, const LinkedList& L2) {
            LinkedList L3;
            for (Node* current = L1.root; current != nullptr; current = current->next)
                if (!L3.found(current->data))
                    L3.push_back(current->data);
            for (Node* current = L2.root; current != nullptr; current = current->next)
                if (!L3.found(current->data))
                    L3.push_back(current->data);
            return L3;
        }
        //Danh sách tổng
        LinkedList Sum_List (const LinkedList& L1, const LinkedList& L2) {
            LinkedList L3;
            Node* p1 = L1.root;
            Node* p2 = L2.root;
            while (p1 && p2) {
                L3.push_back((p1->data + p2->data));
                p1 = p1->next;
                p2 = p2->next;
            }
            while (p1) {
                L3.push_back(p1->data);
                p1 = p1->next;
            }
            while (p2) {
                L3.push_back(p2->data);
                p2 = p2->next;
            }
            return L3;
        }
        //Kiểm tra
        bool check (const LinkedList& other) const {
            for (Node* p = root; p != nullptr; p = p->next) {
                if (other.found(p->data)) {
                    return true;
                }
            }
            return false;
        }
        void removeFirstElement (const LinkedList& other) {
            if (!root) return;
            int sumOfList = other.SUM();
            Node* p = root;
            if (p->data > sumOfList) {
                pop_front();
                return;
            }
            Node* pre = p;
            p = p->next;
            while (p) {
                if (p->data > sumOfList) {
                    pre->next = p->next;
                    delete p;
                    break;
                }
                p = p->next;
                pre = pre->next;
            }
        }
        void remove (const LinkedList& other) {
            if (empty()) return;
            int MAX = other.MAX();
            while (!empty() && root->data == MAX) {
                pop_front();
            }
            if (empty()) return;
            Node* pre = root;
            Node* curr = pre->next;
            while (curr) {
                if (curr->data == MAX) {
                    pre->next = curr->next;
                    delete curr;
                    curr = pre->next;
                }
                else {
                    pre = pre->next;
                    curr = curr->next;
                }
            }
        }
};

void init (LinkedList& L) {
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        L.push_back(x);
    }
}

int main () {
    LinkedList L1, L2;
    init(L1); init(L2);
    L1.display();
    L2.display();
    //a
    LinkedList L3 = L1.connectionList(L1, L2);
    L3.display();
    //b
    LinkedList L4  = L1.List_difference(L1, L2);
    L4.display();
    //c
    LinkedList L5  = L1.List_intersection(L1, L2);
    L5.display();
    //d
    LinkedList L6 = L1.List_union(L1, L2);
    L6.display();
    //e
    LinkedList L7 = L1.Sum_List(L1, L2);
    L7.display();
    //f
    cout << (L1.check(L2) ? "YES" : "NO") << '\n';
    //g
    L1.removeFirstElement(L2);
    L1.display();
    //h
    L1.remove(L2);
    L1.display();

    return 0;
}
*/




#include<bits/stdc++.h>
using namespace std;

class DSlienket;
class Node {
    friend class DSlienket
;
private:
    int data;
    Node* next;
public:
    Node(int _data) {
        data = _data;
        next = NULL;
    }
};

class DSlienket{
private:
    Node* pHead;
    Node* pTail;
public:
    DSlienket
() {
        pHead = pTail = NULL;
    }
    int Size() {
        Node* p = pHead;
        int count = 0;
        while (p != NULL) {
            count++;
            p = p->next;
        }
        return count;
    }
    void addFirst(int data) {
        Node* pAdd = new Node(data);
        if (pHead == NULL) {
            pHead = pTail = pAdd;
        }
        else {
            pAdd->next = pHead;
            pHead = pAdd;
        }
    }
    void addLast(int data) {
        Node* pAdd = new Node(data);
        if (pHead == NULL) {
            pHead = pTail = pAdd;
        }
        else {
            pTail->next = pAdd;
            pTail = pAdd;
        }
    }
    void Remove(int x) {
        Node* p = pHead, * tmp = NULL;
        while ((p != NULL) && (p->data != x)) {
            tmp = p;
            p = p->next;
        }
        if (p == NULL) return;
        if (tmp != NULL) {
            if (p == pTail) {
                pTail = tmp;
                pTail->next = NULL;
            }
            tmp->next = p->next;
            delete p;
        }
        else {
            pHead = p->next;
            delete p;
        }
    }
    void SapXep(int flag) {
        Node* p, * q, * t;
        for (p = pHead; p->next != NULL; p = p->next) {
            t = p;
            for (q = p->next; q != NULL; q = q->next) {
                if (flag == 1) { // tang dan
                    if (q->data < t->data) {
                        t = q;
                    }
                }
                if (flag == -1) { // giam dan
                    if (q->data > t->data) {
                        t = q;
                    }
                }
            }
            swap(t->data, p->data);
        }
    }
    bool search(int x) {
        Node* p = pHead;
        while (p != NULL) {
            if (p->data == x) {
                return 1;
            }
            p = p->next;
        }
        return 0;
    }
    void D3(DSlienket L1, DSlienket L2) {
        Node* p1 = L1.pHead;
        Node* p2 = L2.pHead;
        while (p1 != NULL) {
            addLast(p1->data);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            if (!search(p2->data))
                addLast(p2->data);
            p2 = p2->next;
        }
    }
    
    
    
    void D4(DSlienket L1, DSlienket L2) {
        Node* p1 = L1.pHead;
        Node* p2 = L2.pHead;
        while (p1 != NULL) {
            addLast(p1->data);
            p1 = p1->next;
        }
        
        while (p2 != NULL) {
            if (search(p2->data))
                Remove(p2->data);
            p2 = p2->next;
        }
        int n = Size();
        Node* p, * q, * t;
        int i, j;
        for (p = pHead, i = 0; p->next != NULL, i < (n / 2) - 1; p = p->next, i++) {
            t = p;
            for (q = p->next, j = i + 1; q != NULL, j < n / 2; q = q->next, j++) {
                if (q->data > t->data) {
                    t = q;
                }
            }
            swap(t->data, p->data);
        }
        for (p = p->next, i = n / 2; p->next != NULL, i < n - 1; p = p->next, i++) {
            t = p;
            for (q = p->next, j = i + 1; q != NULL, j < n; q = q->next, j++) {
                if (q->data < t->data) {
                    t = q;
                }
            }
            swap(t->data, p->data);
        }
    }
    void D5(DSlienket L1, DSlienket L2) {
        Node* p1 = L1.pHead;
        Node* p2 = L2.pHead;
        int n1 = L1.Size();
        int n2 = L2.Size();
        int max = n1 > n2 ? n1 : n2;
        int min = n1 < n2 ? n1 : n2;
        int i = 0;
        while (i < min) {
            addLast(p1->data + p2->data);
            p1 = p1->next;
            p2 = p2->next;
            i++;
        }
        while (i < max) {
            if (p1 != NULL) {
                addLast(p1->data);
                p1 = p1->next;
            }
            else {
                addLast(p2->data);
                p2 = p2->next;
            }
            i++;
        }
    }
    void display() {
        Node* p = pHead;
        while (p != NULL) {
            cout << p->data;
            if(p->next != NULL) cout << " ";
            p = p->next;
        }
    }
};

void input(DSlienket& DSlienket) {
    string s;
    getline(cin, s);
    char* c = &s[0];
    while (*c != '\0') {
        if (isdigit(*c)) {
            int num = 0;
            while (isdigit(*c)) {
                num = num * 10 + *c - 48;
                c++;
            }
            DSlienket
        .addLast(num);
        }
        else {
            c++;
        }
    }
}



int main() {
    DSlienket L1, L2, D3, D4, D5;
    input(L1);
    input(L2);
    D3.D3(L1, L2);
    D3.SapXep(-1);
    D3.display();
    cout << endl;
    D4.D4(L1, L2);
    D4.display();
    cout << endl;
    D5.D5(L1, L2);
    D5.display();
    
    return 0;
}
