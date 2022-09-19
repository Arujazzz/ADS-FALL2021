#include <bits/stdc++.h>
using namespace std;
int n, k, res = 0;
string t;

vector<int> p_f(string s){
   int n = s.size();
   vector<int> pi(n);
   for(int i = 1; i < n; ++i){
       int j = pi[i-1]; //Для подсчёта текущего значения мы заводим переменную j, обозначающую длину текущего рассматриваемого образца.
       while(j > 0 && s[i] != s[j]){ //Тестируем образец длины j, для чего сравниваем символы s[j] и s[i]
           j = pi[j - 1];//Если они совпадают — то полагаем \pi[i] = j+1 и переходим к следующему индексу i+1
       }//Если же символы отличаются, то уменьшаем длину j, полагая её равной \pi[j-1], и повторяем этот шаг алгоритма с начала.
       if(s[i] == s[j]){
           j = j + 1;
       }
       pi[i] = j;
   }//Если мы дошли до длины j=0 и так и не нашли совпадения, то останавливаем 
   return pi; //процесс перебора образцов и полагаем \pi[i] = 0 и переходим к следующему индексу i+1.
}


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t >> k;
        vector<int> p = p_f(t);
        int t_ = t.size();
        int end = p[p.size() - 1];
        res = ((t_ - end)*(k - 1)) + t_;
        cout << res << endl;
    }
    //cout << res;
    return 0;
}