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

int n, m, k, x, y, ar[4005][4005];
bool ans;
vector <int> graph [4005];

int main() {
	scan(n); scan(m);
	scan(k);
	for (int i = 0; i < k; i++){
		scan(x); scan(y);
		graph[x].pb(y+2000);
		graph[y+2000].pb(x);
	}
	for (int i = 0; i < 4000; i++){
		for (int j = 0; j < graph[i].size(); j++){
			for (int k = 0; k < graph[i].size(); k++){
				if (j != k){ 
					x = graph[i][j];
					y = graph[i][k];
					ar[x][y]++; 
					//cout << x << ' ' << y << endl;
				}
			}
		}
	}
	for (int i = 0; i < 4000; i++){
		for (int j = 0; j < 4000; j++){
			if (i != j && ar[i][j] > 1) ans = true;
		}
	}
	if (ans) printf ("NO\n");
	else printf ("YES\n");
	return 0;
}
