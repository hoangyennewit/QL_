/*
#include<bits/stdc++.h>
using namespace std;

bool snt(int value){
    for(int i = 2; i <= sqrt(value); i ++){
        if(value % i == 0) return false;
    }
    return value > 1;
}

class Node{
    private:   
        int data;
        Node *next;
    public:
        Node();
        Node(int _data) : data(_data), next(NULL) {}
        int getData() const{
            return data;
        }
        void setData(int _data){
            data = _data;
        }
        Node *getNext() const{
            return next;
        }
        void setNext(Node *_next){
            next = _next;
        }
        friend class LinkedList;
};
class LinkedList{
    private:
        Node *pHead;
    public:
        LinkedList(): pHead(NULL){}
        // Them phan tu vao cuoi danh sach
        void addNode(int value) {
            Node* newNode = new Node(value);
            if (pHead == NULL) {
                pHead = newNode;
            } 
            else{
                Node* temp = pHead;
                while (temp ->getNext() != NULL) {
                    temp = temp ->getNext();
                }
                temp ->setNext(newNode);
            }
        }
        void nhapDSLK(){
            int n;
            cout << "Nhap so luong phan tu can them"; cin >> n;
            cout << "Nhap phan tu cua danh sach lien ket:\n";
            for(int i = 0; i < n; i++){
                int value;
                cin >> value;
                addNode(value);
            }
        }

        void LietKeSNT(){
            Node *tmp = pHead;
            while (tmp->getNext() != NULL)
            {
                if(snt(tmp ->getData())){
                    cout << tmp ->getData() << " ";
                }
                tmp = tmp ->getNext();
            }
            
        }
        void printPrimeNum() {
            Node* curr = pHead;
            bool found = false;
            while (curr){
                if (snt(curr->data)){
                    found = true;
                    cout << curr->data << ' ';
                }
                curr = curr->next;
            }
            if (!found) {
                cout << "Danh sach khong co so nguyen to!";
            }
        }
        // sang snt
        void xuatDSLK(){
            cout << "Danh sach lien ket\n";
            while (pHead != NULL)
            {
                cout << pHead ->getData() <<" ";
                pHead = pHead ->getNext();
            }
        }
        ~LinkedList(){
        }
};
int main(){
    LinkedList DSLK;
    cout << "---------Lua Chon---------";
    cout << "\nNhap a: Them phan tu vao cuoi danh sach";
    cout << "\nNhap b: Xuat danh sach lien ket ra man hinh";
    cout << "\nNhap c: Liet ke cac so nguyen to trong danh sach\n";
    DSLK.nhapDSLK();
    DSLK.xuatDSLK();
    DSLK.printPrimeNum();
    return 0;
}*/

#include <bits/stdc++.h>
#define MAX 100
using namespace std;

struct GRAPH {
    int sodinh;
    int a[MAX][MAX];
};

void readGRAPH (string fn, GRAPH &g) {
    ifstream f;
    f.open(fn);
    if (f.is_open()) {
        f >> g.sodinh;
        for (int i = 0; i < g.sodinh; i++)
            for (int j = 0; j < g.sodinh; j++)
                f >> g.a[i][j];
        f.close();
    } else {
        cout << "Khong mo duoc file!!!";
    }
}

void printGRAPH (GRAPH g) {
    cout << "So dinh cua do thi: " << g.sodinh << endl;
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++)
            cout << setw(4) << g.a[i][j];
        cout << endl;
    }
}

int KiemTraMaTranKeHopLe(GRAPH &g) {
    for (int i = 0; i < g.sodinh; i++) {
        if (g.a[i][i] != 0)
            return 0;
    }
    return 1;
}

int KiemTraDoThiVoHuong(GRAPH &g) {
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = i + 1; j < g.sodinh; j++) {
            if (g.a[i][j] != g.a[j][i])
                return 1;
        }
    }
    return 0;
}

int countEdges(GRAPH &g) {
    int count = 0;
    for (int i = 0; i < g.sodinh; i++) {
        for (int j = 0; j < g.sodinh; j++) {
            count += g.a[i][j];
        }
    }
    return KiemTraDoThiVoHuong(g) ? count : count / 2;
}

void printVertexDegrees(GRAPH &g) {
    cout << "Bac cua cac dinh: " << endl;
    if (KiemTraDoThiVoHuong(g)) {
        for (int i = 0; i < g.sodinh; i++) {
            int degree = 0;
            for (int j = 0; j < g.sodinh; j++) {
                degree += g.a[i][j];
            }
            cout << "Dinh " << i + 1 << " co bac " << degree << endl;
        }
    } else {
        for (int i = 0; i < g.sodinh; i++) {
            int inDegree = 0, outDegree = 0;
            for (int j = 0; j < g.sodinh; j++) {
                inDegree += g.a[j][i];
                outDegree += g.a[i][j];
            }
            cout << "Dinh " << i + 1 << ": bac vao = " << inDegree << ", bac ra = " << outDegree << endl;
        }
    }
}

void findSpecificVertices(GRAPH &g) {
    int maxDegree = -1, minDegree = INT_MAX;
    vector<int> evenDegreeVertices, oddDegreeVertices;
    vector<int> isolatedVertices, pendantVertices;

    for (int i = 0; i < g.sodinh; i++) {
        int degree = 0;
        for (int j = 0; j < g.sodinh; j++) {
            degree += g.a[i][j];
        }
        maxDegree = max(maxDegree, degree);
        minDegree = min(minDegree, degree);

        if (degree % 2 == 0) {
            evenDegreeVertices.push_back(i);
        } else {
            oddDegreeVertices.push_back(i);
        }

        if (degree == 0) {
            isolatedVertices.push_back(i);
        } else if (degree == 1) {
            pendantVertices.push_back(i);
        }
    }

    cout << "Dinh co bac lon nhat: " << maxDegree << endl;
    cout << "Dinh co bac nho nhat: " << minDegree << endl;

    cout << "Cac dinh co bac chan: ";
    for (int v : evenDegreeVertices) {
        cout << v + 1<< " ";
    }
    cout << endl;

    cout << "Cac dinh co bac le: ";
    for (int v : oddDegreeVertices) {
        cout << v + 1 << " ";
    }
    cout << endl;

    cout << "Cac dinh co lap: ";
    for (int v : isolatedVertices) {
        cout << v + 1 << " ";
    }
    cout << endl;

    cout << "Cac dinh treo: ";
    for (int v : pendantVertices) {
        cout << v +1 << " ";
    }
    cout << endl;
}

int main() {
    GRAPH g;
    readGRAPH("DoThi.txt", g);
    printGRAPH(g);

    if (!KiemTraMaTranKeHopLe(g)) {
        cout << "Ma tran ke khong hop le\n";
        return 0;
    } else {
        cout << "Ma tran ke hop le\n";
    }

    if (KiemTraDoThiVoHuong(g)) {
        cout << "Do thi khong la do thi vo huong\n";
    } else {
        cout << "Do thi la do thi vo huong\n";
    }

    cout << "So canh cua do thi: " << countEdges(g) << endl;
    printVertexDegrees(g);
    findSpecificVertices(g);

    return 0;
}

