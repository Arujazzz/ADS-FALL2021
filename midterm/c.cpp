#include <bits/stdc++.h>
using namespace std;
 
struct Node {
  int value;
  int ans;
  Node *prev;
  Node(int x) {
    value = x;
    prev = nullptr;
    ans = -1;
  }
};
 
struct Stack {
  private:
    Node *head = nullptr;
    int sz = 0;
  public:
 
    int top() { 
      return head->value; 
    }
   
    void pop() {
      head = head->prev;
      sz--;
    }
 
    int size() { 
      return sz;
    }
 
    bool empty() { 
      return sz == 0; 
    }
 
    int push(int x) {
      Node * node = new Node(x);
      // write your code here
      if (head == nullptr){
        head = node;
      }else{
        int answ = -1;
        Node *sc_node = head;
        while (sc_node != nullptr){
          if (sc_node -> value <= node -> value){
            answ = sc_node -> node;
            break;
          }
          sc_node = sc_node -> prev;
        }
        node -> ans = answ;
        node -> prev = head;
        head = node;
      }
    sz++;
    return node->ans; 
    }        
    
 
}st;
 
int main() {
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    cout << st.push(x);
  }
}