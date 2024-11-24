#include<bits/stdc++.h>
using namespace std;

template<class DataType>
class Stack;

template <class DataType>
class Node{
    private:
        DataType data;
        Node <DataType> *next;
        friend class Stack <DataType>;
    public:
        Node(DataType values): 
            data(values), next(NULL){}
        
};

template <class DataType>
class Stack{
    private:
        Node <DataType> *p;
    public:
        Stack(): p(NULL){}

        bool empty() const{
            return !p;
        }

        int size() const{
            if(empty()){
                return 0;
            }
            int cnt = 0;
            Node <DataType> *tmp;
            tmp = p;
            while (p != NULL)
            {
                ++cnt;
                p = p ->next;
            }
            return cnt;
        }

        void push(const DataType &value){
            if(empty()){
                p = new Node(value);
                return;
            }
            Node <DataType> *tmp = new Node(value);
            tmp -> next = p;
            p = tmp;
        }
        void pop(){
            if(empty()){
                return;
            }
            Node <DataType> *tmp = p;
            p = p -> next;
            delete tmp;
        }
        DataType& top () const {
            if (empty()) {
                cout << "Empty!\n";
                exit(0);
            }
            return root->data;
        } 

        ~Stack(){
            while(!empty()){
                pop();
            }
        }
};

int DoiCoSo(int n){
    Stack <int> st;
    while(n){
        st.push(n % 2);
        n /= 2;
    }
    long long result = 0;
    while(!st.empty()){
        result = result * 10 + st.top();
        st.pop();
    }
    return result;
}

int main(){
    int n;
    cout << "Nhap N: "; cin >> n;
    cout << DoiCoSo(n);
    return 0;
}