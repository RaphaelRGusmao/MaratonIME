// @author Raphael R. Gusmao
// Codeforces: 100733G - No Negations
// http://codeforces.com/gym/100733/problem/G
#include <bits/stdc++.h>
using namespace std;

int pos[310], par[310], aux;
set<int> open;

int main(){
    string exp;
    cin >> exp;
    int len = exp.size();
    
    for(int i=0; i<len; i++){
        if(exp[i]=='(' || exp[i]=='['){
            pos[aux] = i;
            aux++;
            if(exp[i]=='[') open.insert(i);
        } else if(exp[i]==')' || exp[i]==']'){
            aux--;
            par[pos[aux]] = i;
            par[i] = pos[aux];
        }
    }
    
    while(!open.empty()){
        aux = *open.begin();
        open.erase(aux);
        for(int i=aux+1; i<par[aux]; i++){
            if(isalpha(exp[i])){
                exp[i] = islower(exp[i]) ?
                         toupper(exp[i]) :
                         tolower(exp[i]) ;
            } else if(exp[i]=='+'){
                exp[i] = '*';
            } else if(exp[i]=='*'){
                exp[i] = '+';
            } else {
                if(exp[i]=='('){
                    exp[i] = '[';
                    exp[par[i]] = ']';
                    open.insert(i);
                } else {
                    exp[i] = '(';
                    exp[par[i]] = ')';
                    open.erase(i);
                }
                i = par[i];
            }
        }
        exp[aux] = '(';
        exp[par[aux]] = ')';
    }
    cout << exp << endl;
    
    return 0;
}