// @author Raphael R. Gusmao
// Spoj Brasil: PROIBIDO - Numero Proibido
// http://br.spoj.com/problems/PROIBIDO/
#include <bits/stdc++.h>
using namespace std;

int n;
unsigned long long p, x;
set<unsigned long long> proibido;

int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> p;
        proibido.insert(p);
    }
    while(true){
        cin >> x;
        if(!cin) break;
        cout << (proibido.find(x)!=proibido.end()? "sim" : "nao") << endl;
    }
    
    return 0;
}