// @author Raphael R. Gusmao
// Codeforces: 246B - Increase and Decrease
// http://codeforces.com/problemset/problem/246/B
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
int n, a[MAXN];
long long sum;

int main(){
    ios::sync_with_stdio(false);
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
        sum += a[i];
    }
    
    if(sum%n == 0){
        cout << n << endl;
    } else {
        cout << n-1 << endl;
    }
    
    return 0;
}