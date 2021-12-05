#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack<int> st;
    string s;

    while(s!="exit"){
        cin>>s;
        if(s=="push"){
            int n;
            cin>>n;
            st.push(n);
            cout<<"ok"<<endl;
        }
        if(s=="pop"){
            if (st.size() > 0){
                cout << st.top() << endl;
                st.pop();
            }
            else{
                cout << "error" << endl;
            }
        }
        if(s=="size"){
            cout<<st.size()<<endl;

        }
        if(s=="back"){
            if (st.size() > 0){
                cout << st.top() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
        if (s == "clear") {
            while (!st.empty()) {
                st.pop();
            }
            cout << "ok" << endl;
        }
        if(s=="exit"){
            cout<<"bye"<<endl;
        }
    }

    return 0;
}