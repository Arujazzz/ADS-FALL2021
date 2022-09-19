#include <iostream>
#include <stack>
using namespace std;

int main (){
    stack <char> st;
    string s;
    cin >> s;
    char symbol;
    bool result = true;

    for (int i = 0; i < s.size(); i++){
        symbol = s[i];
        if (symbol == '(' || symbol == '[' || symbol == '{'){
            st.push(symbol);
            continue;
        }

        switch (symbol){
        case ')':
            if (!st.empty() && st.top() == '(') st.pop();
            else result = false;
            break;
        
        case ']':
            if (!st.empty() && st.top() == '[') st.pop();
            else result = false;
            break;
        
        case '}':
            if (!st.empty() && st.top() == '{') st.pop();
            else result = false;
            break;

        }
    }

    result = result && st.empty();
    cout << (result ? "yes" : "no") <<endl;
        
    return 0;
}