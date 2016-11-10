#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 0x3f
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

ll n, p, x, y, ans, freq; bool visit[400005];
vector <ll> graph[400005]; pair <ll, ll> dist[400005], bes[400005]; 

void dfs (int pos){
	vector <pair <ll, ll> > tool; vector <ll> psa; ll tot; 
	psa.pb(0);
	if (visit[pos]) return; 
	visit[pos] = true; 
	if (graph[pos].size() == 1){
		dist[pos].first = 0; dist[pos].second = 1; 
		bes[pos].first = 0; bes[pos].second = 1; 
		return; 
	}
	else{
//	cout << "here" << endl;
		for (int i = 0; i < graph[pos].size(); i++){
			if (!visit[graph[pos][i]]){
				dfs(graph[pos][i]);
				if (dist[pos].first < dist[graph[pos][i]].first + 1){
					dist[pos].first = dist[graph[pos][i]].first + 1;
					dist[pos].second = dist[graph[pos][i]].second;
				}
				else if (dist[pos].first == dist[graph[pos][i]].first + 1){
					dist[pos].second += dist[graph[pos][i]].second;
				}
				tool.pb(mp(dist[graph[pos][i]].first+1, dist[graph[pos][i]].second));
			}
		}
		if (tool.size() >= 2){
			sort (tool.begin(), tool.end());
			for (int i = 0; i < tool.size(); i++){
				psa.pb(tool[i].second);
				if (i > 0) psa[i] += psa[i-1];
			//	cout << pos << ' ' << i << ' ' << psa[i] << endl;
			}
			//cout << pos << ' ' << tool.size() << ' ' << psa[tool.size()] << endl;
			p = lower_bound (tool.begin(), tool.end(), mp (tool[tool.size()-2].first, 0LL)) - tool.begin(); 
			if (tool[tool.size()-1].first == tool[tool.size()-2].first){
				bes[pos].first = tool[tool.size()-1].first + tool[tool.size()-2].first;
				bes[pos].second = tool[p].second; tot += tool[p].second;
			//	cout << bes[pos].second << endl;
				for (int i = p+1; i < tool.size(); i++){
					if (i != p+1) bes[pos].second += tot * (tool[i].second); 
					else bes[pos].second = tot * (tool[i].second); 
					tot += (tool[i].second); 
					//cout << pos << ' ' << ' ' << tot << ' ' << i << ' ' << bes[pos].second << endl;
				}
			}
			else if (tool[tool.size()-1].first != tool[tool.size()-2].first){
				bes[pos].first = tool[tool.size()-1].first + tool[tool.size()-2].first;
				bes[pos].second = (psa[tool.size()-1] - psa[p]) * psa[tool.size()];
			}
		}
	}
//	cout << pos << ' ' << dist[pos].first << ' ' << dist[pos].second << endl;
}

int main() {
    scan(n);
    for (int i = 0; i < n-1; i++){
    	scan(x); scan(y);
    	graph[x].pb(y);
    	graph[y].pb(x);
    }
    for (int i = 1; i <= n; i++){
    	if ((int)graph[i].size() > 1){ 
    		dfs(i);
    		break;
    	}
    }
	for (int i = 1; i <= n; i++){
//		cout << bes[i].first << ' ' << bes[i].second << endl;
		if (bes[i].first > ans){
			ans = bes[i].first; 
			freq = bes[i].second;
		}
		else if (bes[i].first == ans) freq += bes[i].second;
	}
    printf ("%lld %lld\n", ans+1, freq);
	return 0;
}
