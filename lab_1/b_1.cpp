#include <bits/stdc++.h>
using namespace std;

struct Myqueue{
    public:
    int a[100000];

    //Для более лаконичной реализации работы, мы будем
    //хранить указатель не на последний элемент, а
    //на следующий за ним (несуществующий).

    //Это, в частности, позволит нам проверять очередь на пустоту
    //простым условием head == tail
    
    int head = 0;    //Индекс первого элемента.
    int tail = 0;    //Индекс элемента, следующего за последним. 
    int sz = 0;   

    void push(int x) {
        a[tail] = x;
        tail++;
        sz++;
    }

    void pop() {
        if (head != tail) {
            head++;
            sz--;
            //return a[head - 1];
        } 
    }
    int top(){
        return a[head];
    }

    int size(){
        return sz;
    }

    bool is_empty() {
        return head == tail;
    }
};

int main (){
    Myqueue q;
    string s;
    while (s != "exit"){
        cin >> s;
        if (s == "push"){
            int n;
            cin >> n;
            q.push(n);
            cout << "ok" << endl;
        }
        if (s == "pop"){
            if(q.is_empty()){
                cout << "error" << endl;
            }else{
                cout << q.top() << endl;
                q.pop();
            }
        }
        if (s == "size"){
            cout << q.size() << endl;
        }
        if (s == "front"){
            if (q.is_empty()){
                cout << "error" << endl;
            }else{
                cout << q.top() << endl;
            }
        }
        if (s == "clear"){
            while (!q.is_empty()){
                q.pop();
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