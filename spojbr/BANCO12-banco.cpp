﻿﻿﻿// @author Raphael R. Gusmao
// Spoj Brasil: BANCO12 - Banco
// http://br.spoj.com/problems/BANCO12/
#include <bits/stdc++.h>
using namespace std;

#define MAXC 11
#define MAXN 1001
#define MAXTEMPO 10301

int fila[MAXN], ini, fim=-1;
int front(){ return fila[ini]; }
int back(){ return fila[fim]; }
int size(){ return fim-ini+1; }
void push(int x){ fila[++fim]=x; }
void pop(){ if(size()>=0) ini++; }
void clear(){ ini=0; fim=-1; }

int chegada[MAXN], tempo[MAXN], livre[MAXC];
int c, n, prox, qtd;

int main() {    
    scanf("%d %d", &c, &n);
    
    for(int i=0; i<n; i++) scanf("%d %d", &chegada[i], &tempo[i]);

    for(int min=0; min<MAXTEMPO; min++){
        while(prox<n && chegada[prox]==min) push(prox++);
        
        bool vaga = true;
        while(size()>0 && vaga){
            vaga = false;
            
            for(int i=0; i<c ; i++){
                if(livre[i]<=min){
                    if(min-chegada[front()]>20) qtd++;
 
                    livre[i] = min+tempo[front()];
                    pop();
                    vaga = true;
                    break;
                }
            }
        }
        if(size()==0 && prox>=n) break;
    }
    
    printf("%d", qtd);
    
    return 0;
}