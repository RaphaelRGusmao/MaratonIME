// @author Raphael R. Gusmao
// Spoj: STPAR - Street Parade
// http://www.spoj.com/problems/STPAR/
#include <bits/stdc++.h>
using namespace std;

bool can;
int n, aux, carro;
stack<int> rua;

int main(){
    while(true){
        cin >> n;
        if(n==0) break;      
        aux = 1;
        can = true;
        while(rua.size()>0){
            rua.pop();
        }
        for(int i=0; i<n; i++){
            cin >> carro;
            if(can){            
                if(!rua.empty()){
                    while(rua.top()==aux){
                        rua.pop();
                        aux++;
                        if(rua.size()==0) break;
                    }
                }
                if(carro!=aux){         
                    if(!rua.empty()){
                        if(carro>rua.top()){
                            can = false;
                        }
                    }
                    rua.push(carro);
                } else {
                    aux++;
                }
                
            }
        }
        cout<<(can?"yes":"no")<<endl;
    }
    return 0;
}