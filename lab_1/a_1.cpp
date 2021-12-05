#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

class Stack{
    public:
    Node *top;
    int sz;

    Stack(){
        top = NULL;
        sz = 0;
    }

    void push(int data){
        Node *node = new Node(data);
        node -> next = top;
        top = node;
        sz++;
    }

    void pop(){
        if (top != NULL){
            top = top -> next;
            sz--;
        }
    }

    int size(){
        return this -> sz;
    }

    bool empty(){
        if (sz == 0)
            return true;
        return false;
    }
};

int main(){
    Stack *st = new Stack();
    string s;
    while (s != "exit"){
        cin >> s;
        if (s == "push"){
            int n;
            cin >> n;
            st ->push(n);
            cout << "ok" << endl;
        }
        if (s == "pop"){
            if (st -> empty()){
                cout << "error" << endl;
            }else{
                cout << st -> top -> data << endl;
                st -> pop();
            }
        }
        if (s == "back"){
            if (st -> empty()){
                cout << "error" << endl;
            }else{
                cout << st -> top -> data << endl;
            }
        }
        if (s == "size"){
            cout << st -> size() << endl;
        }
        if (s == "clear"){
            while(!st->empty()){
                st ->pop();
            }
            cout << "ok" << endl;
        }
        if (s == "exit"){
            cout << "bye" << endl;
            break;
        }
    }

    return 0;
}