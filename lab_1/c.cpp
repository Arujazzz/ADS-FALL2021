#include <iostream>
#include <deque>
using namespace std;
int main (){
    deque <int> d;
    string s;
    while (s != "exit"){
        cin >> s;
        if (s == "push_front"){
            int n;
            cin >> n;
            d.push_front(n);
            cout << "ok" << endl;
        }
        if (s == "push_back"){
            int n;
            cin >> n;
            d.push_back(n);
            cout << "ok" << endl;
        }
        if (s == "pop_front"){
            if (d.size() > 0){
                cout << d.front() <<endl;
                d.pop_front();
            }
            else{
                cout << "error" << endl;
            }
        }
        if (s == "pop_back"){
            if (d.size() > 0){
                cout << d.back() <<endl;
                d.pop_back();
            }
            else{
                cout << "error" << endl;
            }
        }
        if (s == "front"){
            if (d.size() > 0){
                cout << d.front() << endl;
            }
            else{
                cout << "error" << endl;
            }
        }
        if (s == "back"){
            if (d.size() > 0){
                cout << d.back() << endl;
            }
            else{
                cout << "error"<< endl;
            }
        }
        if (s == "size"){
            cout <<d.size() << endl;
        }
        if (s == "clear"){
            while (!d.empty()){
                d.pop_back();
            }
            cout << "ok" << endl;
        }
        if (s == "exit"){
            cout << "bye" <<endl;
            break;
        }
    }

    return 0;
}