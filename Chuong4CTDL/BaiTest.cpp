/*
#include<bits/stdc++.h>
using namespace std;

template <class DataType>
class Stack;

template <class DataType>
class Node{
    private:
        DataType data;
        Node <DataType> *next;
        friend class Stack<DataType>;
    public:
        Node(DataType value): data(value), next(NULL){}
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
            for(Node <DataType>* tmp = p; tmp != NULL; tmp = tmp ->next){
                ++cnt;
            }
            return cnt; 
        }
        void push(const DataType &value){
            if(empty()){
                p = new Node(value);
            }
            Node <DataType> *tmp = new Node(value);
            tmp ->next = p;
            p = tmp;
        }
        void pop(){
            if(empty()){
                return;
            }
            Node<DataType> *tmp = p;
            p = p ->next;
            delete tmp;
        }
        DataType &top() const{
            if(empty()){
                exit(0);
            }
            return p ->data;
        }
        ~Stack(){
            while(!empty()){
                pop();
            }
        }
};

int priority (const char& chr) {
    if (chr == '^')
        return 4;
    if (chr == '%' || chr == '*' || chr == '/')
        return 3;
    if (chr == '+' || chr == '-')
        return 2;
    return 1;
}

bool Operator(char &c){
    return c == '+' || c == '-' || c == '*'||
        c == '/';
}
bool Operand(char c){
    return isalpha(c);
}
string hauTo (const string& trungTo) {
    Stack<char> s;
    string result;
    for (int i = 0; i < trungTo.length(); ++i) {
        if (Operand(trungTo[i])) {
            int j = i;
            string temp;
            while (j < trungTo.length() && Operand(trungTo[j])) {
                temp.push_back(trungTo[j]);
                j++;
            }
            result += (temp + ' ');
            i = j - 1;
        }
        else {
            if (trungTo[i] == '(') {
                s.push(trungTo[i]);
            }
            else if (trungTo[i] == ')') {
                while (!s.empty() && s.top() != '(') {
                    result.push_back(s.top());
                    result.push_back(' ');
                    s.pop();
                }
                if (!s.empty() && s.top() == '(') s.pop();
            }
            else {
                while (!s.empty() && priority(s.top()) >= priority(trungTo[i])) {
                    result.push_back(s.top());
                    result.push_back(' ');
                    s.pop();
                }
                s.push(trungTo[i]);
            }
        }
    }
    while (!s.empty()) {
        result.push_back(s.top());
        result.push_back(' ');
        s.pop();
    }
    while (result.back() == ' ') result.pop_back();
    return result;
}


int main(){
    string trungTo;
    cout << "Nhap bieu thuc can chuyen tu trung to sang hau to: ";    
    getline(cin, trungTo);
    int i = 0;
    while (i < trungTo.length()) {
        if (trungTo[i] == ' ') {
            trungTo.erase(i, 1);
        }
        else {
            i++;
        }
    }
    string HauTo = hauTo(trungTo);
    cout << "Bieu thuc hau to la:\n" << HauTo;
    return 0;
    return 0;
}
*/