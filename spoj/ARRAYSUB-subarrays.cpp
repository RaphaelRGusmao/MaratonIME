// @author Raphael R. Gusmao
// Spoj: ARRAYSUB - subarrays
// http://www.spoj.com/problems/ARRAYSUB/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
int n, k;
int a[MAXN];

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> k;
    for(int i=0; i<n-k+1; i++){
        int maxn = 0;
        for(int j=i; j<i+k; j++){
            maxn = max(maxn, a[j]);
        } 
        cout<<maxn;
        if(i<n-k) cout<<" ";
    }
    cout<<endl;
    return 0;
}