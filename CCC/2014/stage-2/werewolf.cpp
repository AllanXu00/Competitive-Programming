#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define ll long long 

long long n, w, m, x, y, ans, ar[205], dp[205][205][2]; char a;  vector<pair <ll, bool>> graph[205]; bool visit[205];

void dfs (ll u){
	visit[u] = true;  
	dp[u][0][0] = dp[u][1][1] = 1; 
	for (int i = 0; i < graph[u].size(); i++){
		int v = graph[u][i].first, p = graph[u][i].second;
	    if (!visit[v]) dfs(v);
	//	if (u ==0) cout << v << endl;
		for (int j = w; j >= 0; j--){
		    ll tmp1=0, tmp2=0;
			for (int k = 0; k <= j; k++){
				tmp1 = (tmp1 + dp[u][j-k][0] * (dp[v][k][0] + dp[v][k][1])) %1000000007;
				tmp2 = (tmp2 + dp[u][j-k][1] * dp[v][k][!p]) %1000000007; 
			//	if (u == 0 && j == 2) cout << dp[u][j-k][0] << ' ' << v  << ' ' << j << ' ' << k << ' ' << dp[v][k][0] << ' ' << dp[v][k][1] << endl;
			}
			dp[u][j][0] = tmp1; dp[u][j][1] = tmp2; 
		}
	}
}

int main() {
	scanf("%lld%lld%lld", &n, &w, &m);
	for (int i = 0; i < m; i++){
		scanf(" %c%lld%lld", &a, &x, &y);
		if (a == 'A') graph[x].pb(mp(y, 1));
		else graph[x].pb(mp(y, 0));
		ar[y]++;
	}
	for (int i = 1; i <= n; i++){
		if (!ar[i]){
			graph[0].pb(mp(i, 1));
		}
	}
	dfs(0); 
	//cout << dp[1][2][1] + dp[1][2][0] << endl;
	printf ("%lld\n", dp[0][w][0]%1000000007);
	return 0;
}
