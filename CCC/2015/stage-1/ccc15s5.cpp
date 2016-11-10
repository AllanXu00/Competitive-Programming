#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

int n, m, a[3005], b[105], dp[3005][2][105][105];

int solve(int pos, bool t, int l, int r){
	if (dp[pos][t][l][r] != 0) return dp[pos][t][l][r];
	if (pos > n){
		if (l > r) return 0;
		if (t){
			dp[pos][t][l][r] = b[r] + solve(pos, 0, l, r-1);
		}
		else{
			dp[pos][t][l][r] = solve(pos, 1, l+1, r);
		}
	}
	else if (t){
		dp[pos][t][l][r] = (solve(pos+1, 0, l, r) + a[pos]);
		if (l <= r){
			dp[pos][t][l][r] = max (solve(pos, 0, l, r-1) + b[r], dp[pos][t][l][r]);
		}
	}
	else{
		dp[pos][t][l][r] = solve(pos+1, 1, l, r);
		if (l <= r){
			dp[pos][t][l][r] = max (dp[pos][t][l][r], solve(pos, 1, l+1, r));
		}
	}
	return dp[pos][t][l][r];
}


int main() {
    scan(n);
    for (int i = 1; i <= n; i++) scan(a[i]);
    scan(m); 
    for (int i = 1; i <= m; i++) scan(b[i]);
    sort (b+1, b+m+1);
    printf("%d\n", solve(1, 1, 1, m));
	return 0;
}
