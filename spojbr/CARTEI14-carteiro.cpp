// @author Raphael R. Gusmao
// Spoj Brasil: CARTEI14 - Carteiro
// http://br.spoj.com/problems/CARTEI14/
#include <bits/stdc++.h>
using namespace std;

int n, m, pos;
map<long long, int> casa;
long long aux, tempo;

int main(){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> aux;
        casa[aux] = i;
    }
    for(int i=0; i<m; i++){
        cin >> aux;
        tempo += abs(casa[aux] - pos);
        pos = casa[aux];
    }
    cout << tempo << endl;
    
    return 0;
}