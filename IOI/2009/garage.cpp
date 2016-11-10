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

ll n, m, x, p, ans, co[1005], car[20005]; bool visit[1005];
unordered_map <int, int> val; queue <int> q;

int main() {
    scan(n); scan(m); memset (visit, true, sizeof visit);
    for (int i = 0; i < n; i++) scan(co[i]);
    for (int i = 0; i < m; i++) scan(car[i]);
    for (int i = 0; i < 2*m; i++){
        scan(x); p = -1;
        for (int j = 0; j < n; j++) if (visit[j]) { p = j; break; }
        if (p == -1 && x > 0) q.push(x);
        else if (x > 0){
            ans += co[p] * car[x-1]; 
            visit[p] = false; val[x] = p;
        }
        else{
            visit[(val[-x])] = true; p = val[-x];
            if (!q.empty()){
            	x = q.front(); q.pop(); 
            	ans += co[p] * car[x-1]; visit[p] = false; val[x] = p;
            }
        }
    }
    printf ("%d\n", ans);
	return 0;
}
