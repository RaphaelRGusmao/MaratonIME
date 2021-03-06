// @author Raphael R. Gusmao
// Spoj: ABCPATH - ABC Path
// http://www.spoj.com/problems/ABCPATH/
#include <bits/stdc++.h>
using namespace std;

#define MAXN 55
int h, w, caso, ans;
char mat[MAXN][MAXN];
bool visitado[MAXN][MAXN];
int col[8] = {-1, 0, 1, -1, 1, -1,  0,  1};
int lin[8] = {1,  1, 1,  0, 0, -1, -1, -1};

void dfs(int i, int j, int cont){
    ans = max(ans, cont);
    
    for(int k=0; k<8; k++){
        int vizlin = i + lin[k];
        int vizcol = j + col[k];
        
        if((vizcol>=0 && vizcol<w) &&
        (vizlin>=0 && vizlin<h) &&
        (!visitado[vizlin][vizcol])){            
            if(mat[vizlin][vizcol] == mat[i][j]+1){
                visitado[vizlin][vizcol] = true;
                dfs(vizlin, vizcol, cont+1);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    
    while(++caso){
        cin >> h >> w;
        if(h==0 && w==0) break;
        
        ans = 0;
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                cin >> mat[i][j];
                visitado[i][j] = false;
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(mat[i][j]=='A'){
                    visitado[i][j] = true;
                    dfs(i, j, 1);
                }
            }
        }
        
        cout << "Case " << caso << ": " << ans << endl;
    }
    
    return 0;
}