// @author Raphael R. Gusmao
// Timus Online Judge: 1086 - Cryptography
// http://acm.timus.ru/problem.aspx?num=1086
#include <bits/stdc++.h>
using namespace std;

#define MAXN 15002
int n, k, primo[MAXN], ind;

bool isPrimo(int num){
    if(num==2) return true;
    if(num>2 && num%2!=0){
        int sq = sqrt(num);
        for(int i=3; i<=sq; i+=2){
            if(num%i==0) return false;
        }
        return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    
    primo[++ind] = 2;
    for(int i=3; ind<MAXN; i+=2){
        if(isPrimo(i)){
            primo[++ind] = i;
        }
    }
    
    cin >> n;
    while(n--){
        cin >> k;
        cout << primo[k] << endl;
    }
    
    return 0;
}