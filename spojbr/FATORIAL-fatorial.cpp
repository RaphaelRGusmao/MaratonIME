// @author Raphael R. Gusmao
// Spoj Brasil: FATORIAL - Fatorial
// http://br.spoj.com/problems/FATORIAL/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010

int k, n, digit, pd[MAXN];

int lastDigitFat(long long x){
    if(pd[x]!=0 || x<10) return pd[x];
    bool isDezenaPar = ((((x%100)-(x%10))/10)%2==0)?true:false;
    long long res;
    if(isDezenaPar){
        res = 6 * lastDigitFat(x/5) * lastDigitFat(x%10);
    } else {
        res = 4 * lastDigitFat(x/5) * lastDigitFat(x%10);
    }
    return pd[x] = res%10;
}

int main(){
    int pre[] = {1, 1, 2, 6, 4, 2, 2, 4, 2, 8};
    for(int i=0; i<10; i++){
        pd[i] = pre[i];
    }
    while(++k){
        cin >> n;
        if(!cin) break;
        cout << "Instancia " << k << endl;
        cout << lastDigitFat(n) << endl;
    }
    
    return 0;
}