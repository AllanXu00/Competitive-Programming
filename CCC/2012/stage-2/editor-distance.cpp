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

int n, ro[100005], sx, sy, ex, ey, x, y, dis;
bool visit[100005][85];
queue <pair <int, pair <int, int> > > q;

int main() {
	scan(n);
	for (int i = 1; i <= n; i++) scan(ro[i]);
	scan(sx); scan(sy); scan(ex); scan(ey);
	q.push(mp(0, mp(sx, sy)));
	while (!q.empty()){
		dis = q.front().first; 
		x = q.front().second.first;
		y = q.front().second.second; 
		q.pop(); 
		if (x < 1 || x > n) continue;
		if (y < 1) { x--; y = ro[x]; }
		if (y > ro[x]) { x++; y = 1; }
		if (visit[x][y]) continue;
		visit[x][y] = true;
		if (x == ex && y == ey) { printf ("%d\n", dis); break; }
		q.push(mp(dis+1, mp(x+1, min(y, ro[x+1]))));
		q.push(mp(dis+1, mp(x-1, min(y, ro[x-1]))));
		q.push(mp(dis+1, mp(x, y+1)));
		q.push(mp(dis+1, mp(x, y-1)));
	}
	return 0;
}
