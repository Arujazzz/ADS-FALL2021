#include <bits/stdc++.h>
using namespace std;

char nextGreatestLetter(vector <char> letters, char target){
    int l = 0;
    int r = letters.size();
    while (l < r){
        int mid = l + (r-l) /2;
        if (letters[mid] <= target) l = mid + 1;
        else r = mid;
    }
    return letters[l % letters.size()];
}


int main (){
    vector <char> letters;
    int n;
    cin >> n;
    char letter;
    for (int i=0; i<n; i++){
        cin >> letter;
        letters.push_back(letter);
    }
    
    char target;
    cin >> target;

    cout << nextGreatestLetter(letters, target);

    return 0;
}