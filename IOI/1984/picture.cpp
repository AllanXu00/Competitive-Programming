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

struct LINE {int x, y, yy, val;} ver[10005], hor[10005];
bool cmp (LINE a, LINE b) {return a.x < b.x || (a.x == b.x && a.val > b.val); }
int n, p1, p2, fx, fy, sx, sy, tmp, lins, ans, in1[10005], in2[10005]; 
vector <int> yval, xval; 

int main() {
	scan(n);
	for (int i = 0; i < n; i++){
		scan(fx); scan(fy); scan(sx); scan(sy);
		fx += 10000; fy += 10000; sx += 10000; sy += 10000;
		ver[2*i] = {fx, fy, sy, 1};
		ver[2*i+1] = {sx, fy, sy, -1};
		hor[2*i] = {fy, fx, sx, 1};
		hor[2*i+1] = {sy, fx, sx, -1};	
		xval.pb(fx); xval.pb(sx);
		yval.pb(fy); yval.pb(sy);
	}
	sort (hor, hor+2*n, cmp);
	sort (ver, ver+2*n, cmp);
	sort (yval.begin(), yval.end());
	sort (xval.begin(), xval.end());
	for (int i = 0; i < 2*n; i++){
		p1 = lower_bound (xval.begin(), xval.end(), hor[i].y) - xval.begin(); 
		p2 = lower_bound (xval.begin(), xval.end(), hor[i].yy) - xval.begin(); 
		for (int j = p1+1; j <= p2; j++){
			if (in1[j] == 0 || (in1[j]==1 && hor[i].val == -1)) ans += xval[j] - xval[j-1];
			in1[j] += hor[i].val;
		}
	}
	for (int i = 0; i < 2*n; i++){

		p1 = lower_bound (yval.begin(), yval.end(), ver[i].y) - yval.begin(); 
		p2 = lower_bound (yval.begin(), yval.end(), ver[i].yy) - yval.begin(); 
		for (int j = p1+1; j <= p2; j++){
			if (in2[j] == 0 || (in2[j]==1 && ver[i].val == -1)) ans += yval[j] - yval[j-1];
			in2[j] += ver[i].val;
		}
	}
	printf ("%d\n", ans);
	return 0;
}
