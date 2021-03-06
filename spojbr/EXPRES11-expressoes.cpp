﻿﻿﻿// @author Raphael R. Gusmao
// Spoj Brasil: EXPRES11 - Expressoes
// http://br.spoj.com/problems/EXPRES11/
#include <bits/stdc++.h>
using namespace std;

bool isBemDefinida(string expressao){
    stack<char> parenteses;
    
    for(int j=0; j<expressao.size(); j++){
        if(expressao[j]=='{' || expressao[j]=='[' || expressao[j]=='(') {
            parenteses.push(expressao[j]);
        } else {
            if(parenteses.size()==0) return false;
            if(parenteses.top()=='{'&&expressao[j]=='}'
                || parenteses.top()=='['&&expressao[j]==']'
                || parenteses.top()=='('&&expressao[j]==')') {
                parenteses.pop();
            } else {
                return false;
            }
        }
    }
    
    return parenteses.size()==0;
}

int main() {
    int t;
    string expressao;
    cin >> t;
    
    for(int i=0; i<t; i++){
        cin >> expressao;
        
        cout << (isBemDefinida(expressao) ? 'S' : 'N') << endl;
    }
    
    return 0;
}