// @author Raphael R. Gusmao
// Spoj: 492B - Vanya and Lanterns
// http://codeforces.com/problemset/problem/492/B
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1010
int n;
long long l, a[MAXN], maxDist;

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n >> l;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    
    maxDist = 2*max(a[0], l-a[n-1]);
    for(int i=0; i<n-1; i++){
        maxDist = max(maxDist, a[i+1]-a[i]);
    }
    
    cout << fixed << setprecision(10);
    cout << maxDist/2.0 << endl;
    
    return 0;
}