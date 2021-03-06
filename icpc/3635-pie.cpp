// @author Raphael R. Gusmao
// ACM-ICPC Live Archive: 3635 - Pie
// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1636
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10010
#define EPS 1e-6

int casos, n, f;
double r, v[MAXN];
const double PI = acos(-1.0);

bool check(double x){
    int soma = 0;
    for(int i=0; i<n; i++){
        soma += floor(v[i]/x);
    }
    return soma >= f;
}

int main(){
    cin >> casos;
    while(casos--){
        cin >> n >> f; f++;
        double maior = 0.0;
        for(int i=0; i<n; i++){
            cin >> r;
            v[i] = PI*r*r;
            if(v[i]>maior) maior = v[i];
        }

        double ini=0.0, fim=maior, meio;
        while(fim-ini>EPS){
            meio = (ini+fim)/2.0;
            if(check(meio)){
                ini = meio;
            } else {
                fim = meio;
            }
        }
        printf("%.4lf\n", ini);
    }
    
    return 0;
}