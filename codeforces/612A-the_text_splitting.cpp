// @author Raphael R. Gusmao
// Codeforces: 612A - The Text Splitting
// http://codeforces.com/contest/612/problem/A
#include <stdio.h>
#include <string.h>

int main() {
    char s[100] = "";
    int n = 0;
    int p = 0;
    int q = 0;
    
    int pNum = 0;
    int qNum = 0;
    
    scanf("%d %d %d", &n, &p, &q);
    scanf("%s", &s);
    
    while(n > 0){
        if(n%p == 0){
            pNum += n/p;
            n = 0;
            break;
        } else if(n%q == 0){
            qNum += n/q;
            n = 0;
            break;
        }
        
        n -= (q+p);
        pNum++;
        qNum++;
    }
    
    if(n == 0){
        printf("%d\n", (pNum + qNum));
        
        for(int i=1; i <= pNum*p; i++){
            printf("%c", (s[i-1]));
            
            if(i%p == 0){
                printf("\n");
            }
        }
        
        for(int i=(pNum*p)+1; i <= strlen(s); i++){
            printf("%c", (s[i-1]));
            
            if((i-pNum*p)%q == 0){
                printf("\n");
            }
        }
    } else {
        printf("-1\n");
    }
    
    return 0;
}