#include <bits/stdc++.h>

using namespace std;

struct Mydeque{
    public:
    int a[10000];
    int head = 1000;
    int tail = 1000;
    int sz = 0;

    void push_front(int x){
        head--;
        a[head] = x;
        sz++;
    }
    void push_back(int x){
        a[tail] = x;
        tail++;
        sz++;
    }
    void pop_front(){
        if (head != tail){
            head++;
            sz--;
            //return a[head-1];
        }
    }
    
    void pop_back(){
        if (head != tail){
            tail--;
            sz--;         
        }
    }
    bool is_empty(){
        return head == tail;
    }

    int front(){
        return a[head];
    }

    int back(){
        return a[tail - 1];
    }
    int size(){
        return sz;
    }
};

int main (){
    Mydeque dq;
    string s;
    while (s != "exit"){
        cin >> s;
        if (s == "push_front"){
            int n;
            cin >> n;
            dq.push_front(n);
            cout << "ok" << endl;
        }
        if (s == "push_back"){
            int n;
            cin >> n;
            dq.push_back(n);
            cout << "ok" << endl;
        }
        if (s == "pop_front"){
            if (dq.is_empty()){
                cout << "error" << endl;
            }else{
                cout << dq.front() << endl;
                dq.pop_front();
            }
        }
        if (s == "pop_back"){
            if (dq.is_empty()){
                cout << "error" << endl;
            }else{
                cout << dq.back()<< endl;
                dq.pop_back();
            }
        }
        if (s == "front"){
            if (dq.is_empty()){
                cout << "error" << endl;
            }else{
                cout << dq.front() << endl;
            }
        }
        if (s == "back"){
            if (dq.is_empty()){
                cout << "error" << endl;
            }else{
                cout << dq.back() << endl;
            }
        }
        if (s == "size"){
            cout << dq.size()<< endl;
        }
        if (s == "clear"){
            while (!dq.is_empty()){
                dq.pop_back();
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