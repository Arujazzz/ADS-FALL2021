#include <iostream>
using namespace std;
struct node{
    int val;
    node * next;
    node * prev;
    node(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

struct st{
    private:
        int sz;
        node * tail;
    
    public:
    st(){
        tail = NULL;
        sz = 0;
    }

    void back(){
        if(tail != NULL){
            cout<< tail->val;
        }else{
            cout << "error"<<endl;
        }
    }

    void push(int x){
        sz++;
        node * item = new node(x);
        if(tail == NULL){
            tail = item;
        }else{
                tail->next = item;
                item->prev = tail;
                tail = item;
        }
        cout<< "ok"<<endl;
    }

    void pop(){
        if(tail != NULL){
            sz--;
            cout<< tail->val<<endl;
            tail = tail->prev;
            if(tail != NULL){
                tail->next = NULL;
            }
        }else{
            cout<<"error"<<endl;
        }
    }

    bool empty(){
        return tail == NULL;
    }

    void clear(){
        sz = 0;
        tail = NULL;
        cout<< "ok"<<endl;
    }

    void size(){
        cout<< sz<<endl;
    }

};


int main(){
    st s;

    while (true){
        string c;
        cin>>c;
        if (c == "exit") {
            cout<<"bye";
            break;
        }
        if (c == "size") s.size();
        if (c == "push"){
            int x;
            cin >> x;
            s.push(x);
        }
        if (c == "pop") s.pop();
        if (c == "back") s.back();
        if (c == "clear") s.clear();
    }


    return 0;
}