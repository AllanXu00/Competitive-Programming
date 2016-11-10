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

int n, m, x, q, dis, dist[100005];
vector <int> graph[100005];
vector <bool> visit[100005];
unordered_map <int, int> rev[100005];
unordered_map <int, vector <int> > occurs;
unordered_set <int> op;

void dfs(int a, int b){
	op.clear(); occurs.clear(); 
	int c, t, ans, node, past, tim = 0; 
	while (!visit[a][b]){
		tim++; op.insert(a); occurs[a].pb(tim);  
		visit[a][b] = true; 
		node = a; a = graph[a][b]; 
		b = (rev[a][node]+1) % graph[a].size();
	}
	while (op.size() > 0){
		t = *op.begin(); op.erase(t); ans = 0; if (occurs[t].size() == 1) dist[t] = max(tim, dist[t]); 
		else{
			dist[t] = max (dist[t], tim-occurs[t][occurs[t].size()-1] + occurs[t][0]);
			for (int j = 1; j < occurs[t].size(); j++){
				dist[t]  = max (dist[t] , occurs[t][j] - occurs[t][j-1]);
			}
			
		}
	}
	return; 
}

int main() {
	scan(n);
	for (int i = 1; i <= n; i++){
		scan(m);
		for (int j = 0; j < m; j++){
			scan(x); graph[i].pb(x);
			visit[i].pb(false); rev[i][x] = j;
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < visit[i].size(); j++){
			if (!visit[i][j]) dfs (i, j); 
		}
	}
	scan(q);
	for (int i = 1; i <= q; i++){
		scan(m); printf ("%d\n", dist[m]);
	}
	return 0;
}
