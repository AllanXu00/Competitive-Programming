#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

int nodes, goal, a, b, c, d, tree[305], dp[305][605];
vector <int> graph[305];

void dfs(int u){
    dp[u][301] = 1;
    if (graph[u].size()==0){
        dp[u][301+tree[u]] = 0;
        return;
    }
    else if (graph[u].size()==1){
        dfs (graph[u][0]);
        for (int i = -nodes; i <= nodes; i++) dp[u][i+301] = min (dp[graph[u][0]][i+301-tree[u]], dp[u][i+301]);
    }
    else{
        dfs (graph[u][0]);
        dfs (graph[u][1]);
        dp[u][301+tree[u]] = 2;
        for (int i = -nodes; i <= nodes; i++){
            for (int j = -nodes; j <= nodes; j++){
                if(i-j+301-tree[u]>0)
                dp[u][i+301]=min(dp[u][i+301], dp[graph[u][0]][j+301]+dp[graph[u][1]][i-j+301-tree[u]]);
            }
        }
    }
    
}

int main() {
    scan(nodes); scan(goal);
    for (int i = 0; i < nodes; i++){
        scan(a); scan(b); scan(c); 
        tree[a] = b;
        if (tree[a] == 0) tree[a]--;
        for (int j = 0; j < c; j++){
            scan(d); 
            graph[a].push_back(d);
        }
    }
    memset (dp, 0x3f, sizeof dp);
    dfs (0);
    for (int i = 0; i < nodes; i++){
        for (int j = 300; j <= goal+301; j++){
            //cout << dp[i][j] << " ";
        }
        //cout << endl;
    }
    if (dp[0][goal+301] > 300000) dp[0][goal+301] = -1;
    printf ("%d\n", dp[0][goal+301]);
    return 0;
}
