// @author Raphael R. Gusmao
// Spoj Brasil: BALE11 - Bale
// http://br.spoj.com/problems/BALE11/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010

struct BIT{
    int tree[MAXN], maxVal;
    
    int read(int idx){
        int sum = 0;
        while(idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    void update(int idx, int val){
        while(idx <= maxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
};

int n, x, qtd;
BIT bit;

int main(){
    cin >> n;
    bit.maxVal = n;
    for(int i=1; i<=n; i++){
        cin >> x;
        bit.update(x, 1);
        qtd += bit.read(n) - bit.read(x);
    }
    cout << qtd << endl;
    
    return 0;
}