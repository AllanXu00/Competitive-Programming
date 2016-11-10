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

struct LINE {ll x, y, yy, val, zom;} ver[10005], hor[10005];
bool cmp (LINE a, LINE b) {return a.x < b.x || (a.x == b.x && a.val < b.val); }
ll a[5005], b[5005], test[10005], z,  n, r, c, q, p1, p2, fx, fy, sx, sy, tmp, lins, ans, in1[10005], in2[10005]; 
vector <ll> yval, xval;
vector <LINE>cx, cy;

int main() {
	scan(r); scan(c); scan(n);
	for (int i = 0; i < n; i++){scan(b[i]); scan(a[i]);}
	scan(q);
	xval.pb(1); xval.pb(c);
	yval.pb(1); yval.pb(r);
	for (int i = 0; i < n; i++){
		fx = a[i] - q; sx = a[i] + q; fx = max (1LL, fx); sx = min (c, sx);  
		fy = b[i] - q; sy = b[i] + q; fy = max (1LL, fy); sy = min (r+1, sy+1);
		ver[2*i] = {a[i]-q, fy, sy, 1, i};
		ver[2*i+1] = {a[i]+q, fy, sy, -1, i};
		yval.pb(fy); yval.pb(sy);	
		if (a[i]-q > 0) fx++; 
		if (a[i]+q > c) sx++; 
		hor[2*i] = {b[i]-q, fx, sx, 1, i};
		hor[2*i+1] = {b[i]+q, fx, sx, -1, i};	
		xval.pb(fx); xval.pb(sx);
	}
	sort (hor, hor+2*n, cmp);
	sort (ver, ver+2*n, cmp);
	sort (yval.begin(), yval.end());
	sort (xval.begin(), xval.end());
	for (int i = 0; i < 2*n; i++){
		p1 = lower_bound (xval.begin(), xval.end(), hor[i].y) - xval.begin(); 
		p2 = lower_bound (xval.begin(), xval.end(), hor[i].yy) - xval.begin(); 
		for (int j = p1; j < p2; j++){
			if (in1[j] == 0 || (in1[j]==1 && hor[i].val == -1)) {
				if (hor[i].x > 0 && hor[i].x <= r && test[j] == 0){
					ans += xval[j+1] -xval[j];
					test[j] = 1; 
				} 
			} 
			in1[j] += hor[i].val; 
			
		}
		if (hor[i].x != hor[i+1].x) memset (test, 0LL, sizeof test);
		//cout << hor[i].x << ' ' << hor[i].y << ' ' << hor[i].yy << ' ' << ans << endl;

	}
	memset (test, 0LL, sizeof test);
	for (int i = 0; i < 2*n; i++){
		p1 = lower_bound (yval.begin(), yval.end(), ver[i].y) - yval.begin(); 
		p2 = lower_bound (yval.begin(), yval.end(), ver[i].yy) - yval.begin(); 
		for (int j = p1; j < p2; j++){
			if (in2[j] == 0 || (in2[j]==1 && ver[i].val == -1)){
				if (ver[i].x > 0 && ver[i].x <= c && test[j] == 0){
					ans += yval[j+1] - yval[j];
					test[j] = 1; 
				} 
			} 
			in2[j] += ver[i].val; 
		}
		if (ver[i].x != ver[i+1].x) memset (test, 0LL, sizeof test);
		//cout << ver[i].x << ' ' << ver[i].y << ' ' << ver[i].yy<< ' ' << ans  << endl;
	}
	printf ("%lld\n", max (z, ans));
	return 0;
}
 
