﻿﻿// @author Raphael R. Gusmao
// Peking Online Judge: 2719 - Faulty Odometer
// http://poj.org/problem?id=2719
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

char n[10];

int main() {
    cin >> n;
    
    long long v[11];
    v[0] = 1;
    v[1] = 1;
    v[2] = 1;
    double ten = 1;
    for(int i=3; i<11; i++){
        ten *= 10;
        v[i] = 9*v[i-1]+ten;
    }
    
    while(strlen(n)!=1 || n[0]!='0'){
        long long num = 0;
        long long qtd = 0;
        int len = strlen(n);
        ten = 0.1;
        
        for(int i=0; i<len; i++){
            int x = (int)n[i]-48;
            num = num*10 + x;
        }
        
        for(int i=len-1; i>=0; i--){
            int x = (int)n[i]-48;
            int casa = len-i;
            ten *= 10;
            
            if(x > 4){
                if(i==len-1){
                    qtd++;
                } else {
                    qtd += (x-1)*v[casa]+ten;
                }
            } else if(x < 4){
                if(i!=len-1){
                    qtd += x*v[casa];
                }
            }
        }
        cout << num << ": " << num-qtd << endl;
        
        cin >> n;
    }
    
    return 0;
}