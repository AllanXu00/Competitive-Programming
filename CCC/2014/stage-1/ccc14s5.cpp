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

int n, x, y, a, b, t1, t2, dp[2005], dp2[2005];
vector <pair <int, int> > pts;
vector <pair <ll, pair <int, int> > > dist;
long long dis;

ll calc (pair <int, int> p1, pair <int, int> p2){
    return pow(abs(p1.first - p2.first), 2) + pow(abs(p1.second - p2.second), 2);
}

int main() {
    pts.pb(mp(0, 0));
    scan(n);
    for (int i = 0; i < n; i++){
        scan(x); scan(y);
        pts.pb(mp(x, y));
    }
    for (int i = 0; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            dis = calc (pts[i], pts[j]);
            dist.pb(mp(dis, mp(i, j)));
        }
    }
    sort (dist.begin(), dist.end());
    for (int i = 0; i < dist.size(); i++){
        a = dist[i].second.first;
        b = dist[i].second.second;
        if (i != 0 && dist[i].first != dist[i-1].first){
        	memcpy (&dp, &dp2, sizeof dp2);
        }
        if (b != 0) dp2[a] = max (dp2[a], dp[b]+1);
        if (a != 0) dp2[b] = max (dp2[b], dp[a]+1);
    }
    printf ("%d\n", dp2[0]);
	return 0;
}
