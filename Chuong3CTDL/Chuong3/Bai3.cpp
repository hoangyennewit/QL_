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
*/


#include <bits/stdc++.h>
using namespace std;

class Node {
private:
    int data;
    Node* next;
    friend class LinkedList;
public:
    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* root;
public:
    LinkedList() : root(nullptr) {}

    bool empty() {
        return !root;
    }

    void push_back(int x) {
        if (empty()) {
            root = new Node(x);
            return;
        }
        Node* curr = root;
        while (curr->next) curr = curr->next;
        curr->next = new Node(x);
    }

    bool found(int x) const {
        for (Node* p = root; p != nullptr; p = p->next) {
            if (p->data == x) {
                return true;
            }
        }
        return false;
    }

    void clear() {
        while (root) {
            Node* p = root;
            root = root->next;
            delete p;
        }
    }

    int count (int x) const {
        int ans(0);
        for (Node* p = root; p != nullptr; p = p->next) {
            ans += (p->data == x);
        }
        return ans;
    }

    LinkedList& operator=(const LinkedList& another) {
        if (this != &another) {
            clear();
            Node* current = another.root;
            while (current) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void insert_sorted(int x) {
        Node* newNode = new Node(x);
        if (empty() || root->data >= x) {
            newNode->next = root;
            root = newNode;
        } else {
            Node* current = root;
            while (current->next != nullptr && current->next->data < x) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    LinkedList intersection(const LinkedList& L1, const LinkedList& L2) {
        LinkedList L3;
        for (Node* p = L1.root; p != nullptr; p = p->next) {
            if (L2.found(p->data) && !L3.found(p->data)) {
                L3.insert_sorted(p->data);
            }
        }
        return L3;
    }

    // LinkedList subList(const LinkedList& L1, const LinkedList& L2) {
    //     LinkedList L4;
    //     Node* p = L1.root;
    //     while (p != nullptr) {
    //         Node* q = L2.root;
    //         Node* start = p;
    //         while (start != nullptr && q != nullptr && start->data == q->data) {
    //             L4.push_back(start->data);
    //             start = start->next;
    //             q = q->next;
    //         }
    //         if (q == nullptr || q->data != start->data) {
    //             L4.clear();
    //         } else {
    //             break;
    //         }
    //         p = p->next;
    //     }
    //     return L4;
    // }



    LinkedList subList(const LinkedList& L1, const LinkedList& L2) {
        LinkedList L4;
        int MAX = 0;
        for (Node* p = L1.root; p != nullptr; p = p->next) {
            if (L2.found(p->data)) {
                int count = L2.count(p->data);
                Node* start = L2.root;
                while (count--) {
                    while (start != nullptr && start->data != p->data) {
                        start = start->next;
                    }
                    Node* curr = start;
                    Node* pre = p;
                    int length = 0;
                    while (curr != nullptr && pre != nullptr && curr->data == pre->data) {
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
                        L4 = temp;
                    }
                }
                break;
            }
        }
        return L4;
    }

    LinkedList remove_min_elements(const LinkedList& L1, const LinkedList& L2) {
        LinkedList L5;
        int min_val = INT_MAX;
        for (Node* p = L2.root; p != nullptr; p = p->next) {
            if (p->data < min_val) {
                min_val = p->data;
            }
        }
        for (Node* p = L1.root; p != nullptr; p = p->next) {
            if (p->data != min_val) {
                L5.push_back(p->data);
            }
        }
        return L5;
    }
    
    
    

    void display() const {
        Node * p = root;
        while(p != NULL){
            cout << p->data;
            if (p -> next != NULL){
                cout << " ";
            }
            p = p->next;
        }
        //cout << '\n';
    }

    ~LinkedList() {
        clear();
    }
};

void init(LinkedList& L) {
    int x;
    while (cin >> x) {
        L.push_back(x);
        if (cin.peek() == '\n' || cin.peek() == EOF) {
            break;
        }
    }
}

int main() {
    LinkedList L1, L2;
    init(L1);
    init(L2);

    LinkedList L3 = L3.intersection(L1, L2);
    LinkedList L4 = L4.subList(L1, L2);
    LinkedList L5 = L5.remove_min_elements(L1, L2);

    //cout << "Danh sách L3: ";
    L3.display();
    cout << endl;
    //cout << "Danh sách L4: ";
    L4.display();
    cout << endl;
    //cout << "Danh sách L5: ";
    L5.display();

    return 0;
}

