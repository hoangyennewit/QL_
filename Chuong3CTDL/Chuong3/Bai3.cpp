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
    Node* pNode;
public:
    LinkedList() : pNode(NULL) {}

    bool empty() {
        return !pNode;
    }

    void push_back(int x) {
        if (empty()) {
            pNode = new Node(x);
            return;
        }
        Node* curr = pNode;
        while (curr->next) curr = curr->next;
        curr->next = new Node(x);
    }

    bool found(int x) const {
        for (Node* p = pNode; p != NULL; p = p->next) {
            if (p->data == x) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        while (pNode) {
            Node* p = pNode;
            pNode = pNode->next;
            delete p;
        }
    }

    int count (int x) const {
        int ans(0);
        for (Node* p = pNode; p != NULL; p = p->next) {
            ans += (p->data == x);
        }
        return ans;
    }

    LinkedList& operator = (const LinkedList& another) {
        if (this != &another) {
            clear();
            Node* current = another.pNode;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    LinkedList subList(const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        int MAX = 0;
        for (Node* p = L1.pNode; p != NULL; p = p->next) {
            if (L2.found(p->data)) {
                int count = L2.count(p->data);
                Node* start = L2.pNode;
                while (count--) {
                    while (start != NULL && start->data != p->data) {
                        start = start->next;
                    }
                    Node* curr = start;
                    Node* pre = p;
                    int length = 0;
                    while (curr != NULL && pre != NULL && curr->data == pre->data) {
                        length++;
                        curr = curr->next;
                        pre = pre->next;
                    }
                    if (length > MAX) {
                        LinkedList temp;
                        MAX = length;
                        for (int i = 0; i < length; ++i) {
                            temp.push_back(start->data);
                            start = start->next;
                        }
                        L3 = temp;
                    }
                }
                break;
            }
        }
        return L3;
    }
/*
    void display() {
        for (Node* p = pNode; p != NULL; p = p->next) {
            cout << p->data << ' ';
        }
        cout << '\n';
    }
*/
    void display(){
        Node * p = pNode;
        while(p != NULL){
            cout << p->data;
            if (p -> next != NULL){
                cout << " ";
            }
            p = p->next;
        }
        cout << '\n';
    }

    ~LinkedList() {
        clear();
    }
};

void init(LinkedList& L) {
    int n; cin >> n;
    while (n--) {
        int x; cin >> x;
        L.push_back(x);
    }
}

int main() {
    LinkedList L1, L2;
    init(L1); 
    init(L2);
    cout << "Danh sách L1:";
    L1.display();
    cout << "Danh sách L2:";
    L2.display();
    LinkedList L3 = L1.subList(L1, L2);
    cout << "Danh sách L3:";
    L3.display();
    return 0;
}
