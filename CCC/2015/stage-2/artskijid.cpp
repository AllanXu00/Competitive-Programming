#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

int n, m, x, y, ans, dis, start, dp[30][600005];
vector <pair <int, int> > graph[30];

int dfs (int u, int mask){
	if (dp[u][mask] != -1) return dp[u][mask];
	if (u == n-1) return dp[u][mask] = 0;
	int ans = -1<<30;
	for (int i = 0; i < graph[u].size(); i++){
		if ((mask & (1<<graph[u][i].first)) == 0){
			ans = max (ans, dfs (graph[u][i].first, mask|(1<<graph[u][i].first))+graph[u][i].second);
		}
	}
	return dp[u][mask]=ans;
}

int main() {
    scan(n); scan(m);
    memset (dp, -1, sizeof dp);
    for (int i = 0; i < m; i++){
    	scan(x); scan(y); scan(dis);
    	graph[x].pb(mp(y, dis));
    }
    printf ("%d\n", dfs(0, 1));
	return 0;
}
