// @author Raphael R. Gusmao
// ACM-ICPC Live Archive: 6915 - Leveling Ground
// https://icpcarchive.ecs.baylor.edu/index.php?option=onlinejudge&page=show_problem&problem=4927
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000010
int casos, n, m, alturaMin;
int altura[MAXN];
long long custoMin;
long long custoAte[MAXN];
string land;

int main(){
    ios::sync_with_stdio(false);
    
    cin >> casos;
    for(int t=1; t<=casos; t++){
        cin >> n >> m;
        cin >> land;
        
        altura[0] = 0;
        alturaMin = 0;
        for(int i=1; i<n; i++){
            altura[i] = altura[i-1];
            if(land[i-1]=='/') altura[i]++;
            if(land[i]=='\\') altura[i]--;
            alturaMin = min(alturaMin, altura[i]);
        }
        
        for(int i=0; i<n; i++){
            altura[i] -= alturaMin;
        }
        
        for(int i=1; i<=n; i++){
            custoAte[i] = altura[i-1]*2;
            if(land[i-1]=='/' || land[i-1]=='\\'){
                custoAte[i]++;
            }
            custoAte[i] += custoAte[i-1];
        }
        
        custoMin = 10000000000000LL;
        deque<long long> q, ind;
        for(int i=0; i<m-1; i++){
            while(!q.empty() && altura[i]<=q.back()){
                q.pop_back();
                ind.pop_back();
            }
            q.push_back(altura[i]);
            ind.push_back(i);
        }
        for(int i=m-1; i<n; i++){
            if(!ind.empty() && i+1-ind.front()>m){
                q.pop_front();
                ind.pop_front();
            }
            
            while(!q.empty() && altura[i]<=q.back()){
                q.pop_back();
                ind.pop_back();
            }
            q.push_back(altura[i]);
            ind.push_back(i);
            
            long long custoTemp = custoAte[i+1]-custoAte[i+1-m] - 2LL*m*q.front();
            custoMin = min(custoMin, custoTemp);
        }
        
        cout << fixed << setprecision(1);
        cout << "Case #" << t << ": " << 1.0*custoMin/2.0 << endl;
    }
}