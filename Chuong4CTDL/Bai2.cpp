#include<bits/stdc++.h>
using namespace std;

template <class DataType>
class Stack;

template <class DataType>
class Node{
    private:
        DataType data;
        Node <DataType> *next;
        friend class Stack <DataType>;
    public:
        Node(DataType value): data(value), next(NULL){}
};

template<class DataType>
class Stack{
    private:
        Node <DataType> *head;
    public:
        Stack(): head(NULL){}

        bool empty()const{
            return !head;
        }
        int size()const{
            if(empty()){
                return 0;
            }
            int count = 0;
            for(Node <DataType> *tmp = head; tmp != NULL; tmp = tmp ->next){
                ++count;
            }
            return count;
        }
        void push(const DataType &value){
            if(empty()){
                head = new Node(value);
                return;
            }
            Node <DataType> *tmp = new Node(value);
            tmp -> next = head;
            head = tmp;
        }
        void pop(){
            if(empty()){
                return;
            }
            Node <DataType> *tmp = head;
            head = head ->next;
            delete tmp;
        }
        DataType &top() const{
            if(empty()){
                exit(0);
            }
            return head ->data;
        }

        ~Stack(){
            while(!empty()){
                pop();
            }
        }

};

bool check(string s){
    Stack <char> st;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '{' || s[i] == '(' || s[i] == '['){
            st.push(s[i]);
        }
        else {
            if((s[i] == ')' && st.top()!= '(')||
                (s[i] == ']' && st.top() != '[') ||
                (s[i] == '}' && st.top() != '{'))
                {
                    return false;
                }
            else{
                st.pop();
            }
        }
    }
    return st.empty();
}

bool check2(string s){
    stack<char> st;
    for(char x : s){
    if(x == '{' || x == '(' || x == '['){
        st.push(x);
    }
    else{
        if(st.empty()) return false;
        st.pop();
    }
    }
    return st.empty();
}
int main(){
    string str;
    cout << "Nhap chuoi can kiem tra: "; cin >> str;
    if (check(str)){
        cout << "true";
    }
    else cout << "false";
    return 0;
}