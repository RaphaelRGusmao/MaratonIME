﻿﻿﻿// @author Raphael R. Gusmao
// Spoj Brasil: ACIDO - Acido Ribonucleico Alienigena
// http://br.spoj.com/problems/ACIDO/
#include <bits/stdc++.h>
using namespace std;

bool combina(char a, char b){
    if((a=='C' && b=='F')
    || (a=='F' && b=='C')
    || (a=='B' && b=='S')
    || (a=='S' && b=='B'))
        return true;
    return false;
}

int find_max(string acido){
    stack<char> s;
    int sum = 0;
    for(int i=0; i<acido.size(); i++){
        if(s.empty()){
            s.push(acido[i]);
        } else if(combina(acido[i], s.top())){
            s.pop();
            sum++;
        } else {
            s.push(acido[i]);
        }
    }
    return sum;
}

int main(){
    string acido;
    while(true){
        cin >> acido;
        if(!cin) break;
        cout << find_max(acido) << endl;
    }	
    return 0;
}