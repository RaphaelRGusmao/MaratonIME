﻿﻿// @author Raphael R. Gusmao
// Codeforces: 616A - Comparing Two Long Integers
// http://codeforces.com/contest/616/problem/A
#include <bits/stdc++.h>
using namespace std;

char a[1000001];
char b[1000001];

int main() {
    scanf("%s", &a);
    scanf("%s", &b);
    
    bool azero = true;
    bool bzero = true;
    
    unsigned long long iniA = 0;
    for(unsigned long long i=0; i<strlen(a); i++){
        if(a[i] != '0'){
            iniA = i;
            azero = false;
            break;
        }
    }
    unsigned long long iniB = 0;
    for(unsigned long long i=0; i<strlen(b); i++){
        if(b[i] != '0'){
            iniB = i;
            bzero = false;
            break;
        }
    }
    
    unsigned long long lenA = strlen(a)-iniA;
    unsigned long long lenB = strlen(b)-iniB;

    if(azero && !bzero){
        printf("<\n");
    } else if(!azero && bzero){
        printf(">\n");
    } else if(azero && bzero){
        printf("=\n");
    } else {
        if(lenA > lenB){
            printf(">\n");
        } else if(lenA < lenB){
            printf("<\n");
        } else {
            unsigned long long k = 0;
            bool igual = true;
        
            while(k<lenA+1){
                if(a[k+iniA] > b[k+iniB]){
                    printf(">\n");
                    igual = false;
                    break;
                } else if(a[k+iniA] < b[k+iniB]){
                    printf("<\n");
                    igual = false;
                    break;
                }
                k++;
            }
        
            if(igual){
                printf("=\n");
            }
        }
    }
    return 0;
}