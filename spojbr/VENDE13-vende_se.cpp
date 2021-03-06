// @author Raphael R. Gusmao
// Spoj Brasil: VENDE13 - Vende-se
// http://br.spoj.com/problems/VENDE13/
#include <bits/stdc++.h>
using namespace std;

int n, k, predio[100010], dist;

int main(){
    cin >> n >> k;
    
    for(int i=0; i<n; i++){
        cin >> predio[i];
    }
    sort(predio, predio+n);
    
    dist = predio[n-1-k] - predio[0];
    for(int i=1; i<=k; i++){
        dist = min(dist, (predio[n-1-k+i] - predio[i]));
    }
    
    cout << dist << endl;
    
    return 0;
}