#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

ll n, x, y, ar[1000005]; bool visit[1000005]; ll tot, tmp, bes = 10000000000000, ans;
vector <ll> dp[1000005], graph[1000005];

void dfs (int pos){
	if (visit[pos]) return;
	visit[pos] = true; bool ch=false; 
	ll dirt = 0, vis = 0; 
	if (graph[pos].size() > 1){
		for (int i = 0; i < graph[pos].size(); i++){
			if (!visit[graph[pos][i]]){
				dfs(graph[pos][i]);
				for (int j = 0; j < graph[graph[pos][i]].size(); j++){
					if (graph[graph[pos][i]][j] != pos) dp[pos][i] += dp[graph[pos][i]][j];
					if (graph[graph[pos][i]][j] != pos) dirt += dp[graph[pos][i]][j];
				}
				
				dp[pos][i] += ar[graph[pos][i]];
				dirt += ar[graph[pos][i]];
			}
			else{ vis = i; ch = true; }
		}
		if (ch){ dp[pos][vis] = tot - dirt - ar[pos]; }
//		if (pos == 6) cout << dirt << endl;
	}
	else dp[pos][0] = tot - ar[pos];
//	cout << pos << ":" << endl;
//	for (int i = 0; i < graph[pos].size(); i++){
//		cout << graph[pos][i] << ' ' << dp[pos][i] << endl;
//	}
}

int main() {
	scan(n); if (n <= 1) {cout << 0 << endl; return 0; }
	for (int i = 0; i < n; i++){ scan(ar[i]); tot += ar[i]; }
	for (int i = 1; i < n; i++){
		scan(x); scan(y);
		graph[x].pb(y);
		graph[y].pb(x);
		dp[x].pb(0); dp[y].pb(0);
	}
	for (int i = 0; i < n; i++){
		if (graph[i].size() > 1){
			dfs(i);
			break;
		}
		if (i == n-1){
			for (int j = 0; j < n; j++) dfs(j);
		}
	}
	for (int i = 0; i < n; i++){
		for (int j = 0; j < dp[i].size(); j++){
			tmp = max (tmp, dp[i][j]);
		}
//		cout << i << ' ' << tmp << endl;
		if (tmp < bes){
			bes = tmp;
			ans = i;
		}
		tmp = 0;
	}
	cout << ans << endl;
	return 0;
}
