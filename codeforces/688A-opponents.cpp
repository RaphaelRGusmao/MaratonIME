// @author Raphael R. Gusmao
// Codeforces: 688A - Opponents
// http://codeforces.com/problemset/problem/688/A
#include <bits/stdc++.h>
using namespace std;

int n, d, maxn, num;
string str;
bool temZero;

int main(){
    cin >> n >> d;
    
    for(int i=0; i<d; i++){
        cin >> str;
        
        temZero = false;
        for(int j=0; j<n; j++){
            if(str[j]=='0'){
                num++;
                temZero = true;
                break;
            }
        }
        if(!temZero){
            num = 0;
        } else {
            maxn = max(maxn, num);
        }
    }
    
    cout << maxn << endl;
    
    return 0;
}