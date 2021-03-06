// @author Raphael R. Gusmao
// ACM-ICPC Live Archive: 3475 - P-Networks
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&category=227&page=show_problem&problem=1476
#include <bits/stdc++.h>
using namespace std;

#define MAXN 30
int n, len, v[MAXN], element[MAXN];
vector<int> net;
bool possivel;

void bubbleSort(){
    for(int i=n-1; i>0; i--){
        for(int j=0; j<i; j++){
            if(v[j]>v[j+1]){
                swap(v[j], v[j+1]);
                net.push_back(j+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    while(true){
        cin >> n;
        if(n==0) break;
        
        possivel = true;
        memset(element, 0, sizeof(element));
        net.clear();
        for(int i=0; i<n; i++){
            cin >> v[i];
            if(element[v[i]]++ != 0){
                possivel = false;
            }
        }
        
        if(possivel){
            bubbleSort();
            len = net.size();
            cout << len;
            for(int i=0; i<len; i++){
                cout << " " << net[i];
            }
            cout << endl;
        } else {
            cout << "No solution" << endl;
        }
    }
}