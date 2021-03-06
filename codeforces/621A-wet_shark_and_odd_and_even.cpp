// @author Raphael R. Gusmao
// Codeforces: 621A - Wet Shark and Odd and Even
// http://codeforces.com/contest/621/problem/A
#include <stdio.h>

int main(){
    long long num=0, soma=0, minImpar=10000000000;
    long n = 0;
    int qtdImpar = 0;

    scanf("%I64d", &n);

    for(int i=0; i<n; i++){
        scanf("%I64d", &num);

        soma += num;

        if(num%2 == 1){
            qtdImpar++;

            if(num < minImpar){
                minImpar = num;
            }
        }
    }

    if(soma%2 == 1){
        soma -= minImpar;
    }

    printf("%I64d\n", soma);

    return 0;
}