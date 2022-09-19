#include <iostream>
#include <vector>
using namespace std;

const int N = 26;

class Node{
    public:
    char value;
    Node *ch[N];
    int cnt;

    Node (char value){
        this -> value = value;
        for (int i = 0; i < N; i++)
            this -> ch[i] = NULL;
        cnt = 1;
    }
};

class Trie{
    public:
    Node *root;
    int cnt;
    Trie(){
        root = new Node('*');
        this -> cnt = 0;
    }

    void insert(string s){
        Node *cur = root;
        for (int i = 0; i < s.size(); i++){
            if (cur -> ch[s[i] - 'a'] != NULL){
                cur = cur -> ch[s[i] - 'a'];
                cur -> cnt += 1;
            }else{
                Node *node = new Node(s[i]);
                cur -> ch[s[i] - 'a'] = node;
                cur = node;
                this -> cnt ++;

                if (i == s.size() - 1){
                    
                }
            }
        }
    }
};
/*
int main(){
    Trie *trie = new Trie();
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++){
        cin >> s;
        trie -> insert(s);
    }
    cout << trie -> cnt;

    return 0;
}*/ 

/*
int main (){
    Trie *trie = new Trie();
    string s;
    cin >> s;
    vector <string> str;
    for (int i = 0; i < s.size(); i++){
        str.push_back(s.substr(i, s.size() + 1));
    }
    for (int i = 0; i < str.size(); i++){
        trie -> insert(str[i]);
    }
    cout << trie -> cnt;
    return 0;
}*/