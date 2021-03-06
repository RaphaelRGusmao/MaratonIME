// @author Raphael R. Gusmao
// Spoj Brasil: ALVO13 - Tiro ao Alvo
// http://br.spoj.com/problems/ALVO13/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 100010
int c, t;
long long raio2[MAXN], pontos;

int buscabin(long long x){
    int ini=0, fim=c-1, meio;
    if(x>raio2[fim]) return 0;
    while(ini<fim){
        meio = (ini+fim)/2;
        if(x<=raio2[meio]){
            fim = meio;
        } else {
            ini = meio+1;
        }
    }
    return c-fim;
}

int main(){
    cin >> c >> t;
    for(int i=0; i<c; i++){
        cin >> raio2[i];
        raio2[i] *= raio2[i];
    }
    for(int i=0; i<t; i++){
        long long x, y;
        cin >> x >> y;
        pontos += buscabin(x*x + y*y);
    }
    cout << pontos << endl;
    
    return 0;
}