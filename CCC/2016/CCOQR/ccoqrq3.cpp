#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

long long n, m, x, y, t; pair <long long, long long> p[100005]; long long ans;
long long ar (long long x){return (x*(x+1))/2;}

int main() {
    scanf("%lld%lld", &n, &m);
    for (int i = 0; i < m; i++){
    	scanf("%lld%lld", &x,&y);
    	p[i] = mp(y, n-x+1);
    }
    sort (p, p+m);
    for (int i = 0; i < m-1; i++){
        int h = p[i].second - (p[i+1].first-p[i].first);
        if(h >= p[i+1].second){
            p[i+1]=p[i];
            continue;
        }
        if (h < 0) h = 0;
    	ans += ar(p[i].second);
    	ans -= ar(h);
    }
    printf ("%lld\n", ans+ar(p[m-1].second));
	return 0;
}
