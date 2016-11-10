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

int n, x, y; string a;
map <int, string> f;
vector <int> pts, star, graph[105], rev[105];
vector <string> ans;
bool ch, visit[105];

void dfs (int u){
	if (visit[u]){ return; ch = false; }
	ans.pb(f[u]);
	visit[u] = true; 
	if (rev[u].size() != 0) dfs (rev[u][0]);
	return;
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++){
		cin >> a >> x >> y; 
		f[y] = a; graph[x].pb(y); rev[y].pb(x);
		pts.pb(x); pts.pb(y);
	}
	for (int i = 0; i < pts.size(); i++){
		if (graph[pts[i]].size() == 0){ ch = true; star.pb(pts[i]); }
	}
	for (int i = 0; i < star.size(); i++){
		dfs (star[i]); 
	}
	for (int i = 0; i < pts.size(); i++){
		if (!visit[pts[i]]) { ch = false; break; };
	}
	if (!ch) printf ("Impossible\n");
	else for (int i = 0; i < ans.size(); i++) cout << ans[i] << endl;
	return 0;
}
