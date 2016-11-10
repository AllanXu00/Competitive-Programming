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
 
struct LINE {long long x, y1, y2, val;} s[2005];
bool cmp (LINE a, LINE b) {return a.x < b.x || (a.x == b.x && a.val < b.val); }
long long n, t, x1, yt, x2, yb, v, cur, ans, lo, hi, yval[2005], vals[2005];
 
int main() {
	scan(n); scan(t);
	for (int i = 0; i < n; i++){
		scan(x1); scan(yt); scan(x2); scan(yb); scan(v);
		s[2*i] = {x1, yt, yb, v};
		s[2*i+1] = {x2, yt, yb, -v};
		yval[2*i] = yt;
		yval[2*i+1] = yb;
	}
	sort (s, s+2*n, cmp);
	sort (yval, yval+2*n);
	for (int i = 0; i <= 2*n; i++){
		lo = lower_bound(yval, yval+2*n, s[i].y1) - yval;
		hi = lower_bound(yval, yval+2*n, s[i].y2) - yval;
		for (int j = 0; j < 2*n-1; j++){
			if (vals[j] >= t){
				ans += (yval[j+1] - yval[j]) * (s[i].x - s[i-1].x);
			}
		}
		for (int j = lo; j < hi; j++){
			vals[j] += s[i].val;
		}
 
	}
	cout << ans << endl;
	return 0;
}
