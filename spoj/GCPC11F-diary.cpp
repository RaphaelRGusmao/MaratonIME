﻿﻿﻿// @author Raphael R. Gusmao
// Spoj: GCPC11F - Diary
// http://www.spoj.com/problems/GCPC11F/
#include <bits/stdc++.h>
using namespace std;

int letra[91];
char enc[1001];

int main() {
    int c = 0;
    cin >> c;
    
    cin.getline(enc,1001);
    
    while(c--){
        bool possible = true;
        
        for(int i=65; i<91; i++){
            letra[i] = 0;
        }
        
        cin.getline(enc,1001);
            
        for(int i=0; i<strlen(enc); i++){
            letra[enc[i]]++;
        }
        
        int maxQtd = 0;
        for(int i=65; i<91; i++){
            maxQtd = max(maxQtd, letra[i]);
        }
        
        int letAparec = 0;
        for(int i=65; i<91; i++){
            if(letra[i] == maxQtd){
                if(letAparec == 0){
                    letAparec = i;
                } else {
                    possible = false;
                    break;
                }
            }
        }
        
        if(possible){
            int dist = letAparec-'E';
            if(dist<0){
            	dist = 'Z'-'E' + letAparec-'A'+1;
            }
            for(int i=0; i<strlen(enc); i++){
                if(enc[i]!=32){
                    enc[i] -= dist;
                    if(enc[i]>90){
                        enc[i] -= 26;
                    } else if(enc[i]<65){
                        enc[i] += 26;
                    }
                }
            }
            cout << abs(dist) << " " << enc << endl;
        } else {
            cout << "NOT POSSIBLE" << endl;
        }
    }

    return 0;
}