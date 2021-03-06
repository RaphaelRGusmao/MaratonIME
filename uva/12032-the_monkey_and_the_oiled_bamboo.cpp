// @author Raphael R. Gusmao
// UVa Online Judge: 12032 - The Monkey and the Oiled Bamboo
// https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3183
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

int t, n;
long long r[MAXN], pulo[MAXN], k, last, maxi;

int main(){    
    cin >> t;
    for(int i=1; i<=t; i++){
        cin >> n;
        last=0; maxi=0;
        for(int j=0; j<n; j++){
            cin >> r[j];
            pulo[j] = r[j]-last;
            maxi = max(maxi, pulo[j]);
            last = r[j];
        }        
        k = maxi;
        bool conseguiu = true;;
        if(n>1){
            for(int j=0; j<n; j++){
                if(k==pulo[j]){
                    k--;
                } else if(k<pulo[j]){
                    conseguiu = false;
                    break;
                }
            }
        }
        cout << "Case " << i << ": " << (conseguiu? maxi : maxi+1) << endl;
    }
    
    return 0;
}