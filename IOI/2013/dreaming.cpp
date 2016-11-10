#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define mp make_pair 
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define s(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

ll n, m, k, x, y, z, tmp, lar, dist[1000005]; vector <ll> bes; 
vector <pair <ll, ll>> graph[1000005]; bool visit[1000005], ovisit[1000005], tvisit[1000005], vis[1000005];  
priority_queue <pair <ll, ll>> q; 

long long solve (ll u){
	ll ans1, ans2, pos, dis, fin = 1<<30; 
	while (!q.empty()) q.pop(); 
	q.push(mp(0, u));
	while (!q.empty()){
		dis = -q.top().first; 
		pos = q.top().second; 
		q.pop(); 
		if (visit[pos]) continue; 
		visit[pos] = true; vis[pos] = true; ans1 = pos; 
		for (int i = 0; i < graph[pos].size(); i++){
			if (!visit[graph[pos][i].second]) q.push(mp(-(dis+graph[pos][i].first), graph[pos][i].second)); 
		}
	}
	while (!q.empty()) q.pop(); 
	q.push(mp(0, ans1));
	while (!q.empty()){
		pos = q.top().second; 
		dis = -q.top().first; 
		q.pop(); 
		if (ovisit[pos]) continue; 
		ovisit[pos] = true; dist[pos] = max (dist[pos], dis); ans2 = pos; 
		for (int i = 0; i < graph[pos].size(); i++){
			if (!ovisit[graph[pos][i].second]) q.push(mp(-(dis+graph[pos][i].first), graph[pos][i].second)); 
		}
	}
	while (!q.empty()) q.pop(); 
	q.push(mp(0, ans2));
	while (!q.empty()){
		pos = q.top().second; 
		dis = -q.top().first; 
		q.pop(); 
		if (tvisit[pos]) continue; 
		tvisit[pos] = true; dist[pos] = max (dist[pos], dis);  fin = min(fin, dist[pos]); lar = max(lar, dist[pos]);  
		for (int i = 0; i < graph[pos].size(); i++){
			if (!tvisit[graph[pos][i].second]) q.push(mp(-(dis+graph[pos][i].first), graph[pos][i].second)); 
		}
	}
	return fin; 
}

int main() {
	s(n); s(m); s(k);
	for (int i = 0; i < m; i++){
		s(x); s(y); s(z); 
		graph[x].pb(mp(z, y));
		graph[y].pb(mp(z, x)); 
	}
	for (int i = 0; i < n; i++){
		if(!vis[i]){ bes.pb(solve(i)); } 
	}
	sort (bes.begin(), bes.end());
	if (bes.size() == 1) printf ("%lld\n", lar);
	else if (bes.size() == 2) printf ("%lld\n", max (bes[bes.size()-1] + bes[bes.size()-2] + k, lar));
	else printf ("%lld\n", max (bes[bes.size()-2] + bes[bes.size()-3] +2*k, max(bes[bes.size()-1] + bes[bes.size()-2] + k, lar))); 
	return 0;
}
