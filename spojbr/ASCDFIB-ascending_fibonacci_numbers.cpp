// @author Raphael R. Gusmao
// Spoj Brasil: ASCDFIB - Ascending Fibonacci Numbers
// http://www.spoj.com/problems/ASCDFIB/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1100001
#define MOD 100000

int t, a, b;
int fib[MAXN], v[MAXN], aux[MAXN];

void countingSort(int len){
    memset(aux, 0, sizeof(aux));
    for(int i=0; i<len; i++){
        aux[v[i]]++;
    }
    int j = 0;
    for(int i=0; i<MAXN; i++){
        while(aux[i]--){
            v[j++] = i;
        }
    }
}

int main(){
    fib[0]=0; fib[1]=1;
    for(int i=2; i<MAXN; i++){
        fib[i] = (fib[i-1] + fib[i-2])%MOD;
    }
    
    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> a >> b;
        cout << "Case " << i << ":";
        
        int cont = 0;
        for(int j=a-1; j<a+b; j++){
            v[cont] = fib[j];
            cont++;
        }
        
        countingSort(cont);
        
        int lim = min(cont, 100);
        for(int j=0; j<lim; j++){
            cout << " " << v[j];
        }        
        cout << endl;
    }
    
    return 0;
}