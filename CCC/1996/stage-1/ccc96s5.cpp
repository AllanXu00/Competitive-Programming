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

int main() {
    int t, n, tmp; scan(t);
    for (int k = 0; k < t; k++){
    	scan(n); int ans = 0, ar[n], ar2[n];
    	for (int i = 0; i < n; i++){ scan(tmp); ar[i] = -tmp; }
    	for (int i = 0; i < n; i++){ scan(tmp); ar2[i] = -tmp; }
    	for (int i = 0; i < n; i++){
    		tmp = upper_bound(ar2, ar2+n, ar[i]) - ar2;
    		ans = max (ans, tmp-i-1);
    	}
    	printf ("The maximum distance is %d\n", ans);
    }
	return 0;
}
