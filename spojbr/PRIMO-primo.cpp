// @author Raphael R. Gusmao
// Spoj Brasil: PRIMO - Primo
// http://br.spoj.com/problems/PRIMO/
#include <stdio.h>
#include <math.h>
 
int main() {
    signed long int N = 0;
    bool isPrimo = false;

    scanf("%I64d", &N);

    if(N<0){
        N = -N;
    }

    if(N==2){
        isPrimo = true;
    } else if(!(N<2 || N%2==0)){
        for(int i=3; i<=sqrt(N); i+=2){
            if(N%i==0){
                goto end;
            }
        }
        isPrimo = true;
    }
    end:

    printf("%s", isPrimo ? "sim\n" : "nao\n");

    return 0;
}