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

int n, m, x, y, s, v1, v2, lo, hi, mid, tree[400005], lazy[400005]; ll ans, z; 
pair <int, int> q[100005];

void prop (int n, int l, int r){
	tree[n] += (r-l+1) * lazy[n];
	if (l != r){
		lazy[2*n+1] += lazy[n];
		lazy[2*n+2] += lazy[n];
	}
	lazy[n] = 0; 	
}
void update (int n, int l, int r){
	if (lazy[n]) prop (n, l, r);
	if (l > y || r < x) return; 
	if (l >= x && r <= y){
		lazy[n] += 1; 
		prop (n, l, r);
		return;
	}
	update(2*n+1, l, (l+r)/2);
	update (2*n+2, (l+r)/2+1, r);
	tree[n] = tree[2*n+1] + tree[2*n+2];
}
int query (int n, int l, int r){
	if (lazy[n]) prop (n, l, r);
	if (l > x || r < x) return 0; 
	if (l == x && r == x) return tree[n];
	return 	query(2*n+1, l, (l+r)/2) + query(2*n+2, (l+r)/2+1, r);
}
int main() {
	scan(n);
	for (int i = 0; i < n; i++){
		scan(q[i].first); scan(q[i].second);
		m = max (m, q[i].first);
	}
	sort (q, q+n);
	for (int i = 0; i < n; i++){
		if (q[i].first == q[i].second){
			x = 1; y = q[i].second; 
			update (0, 1, m);
		}
		else{
			x = q[i].first - q[i].second + 1;
			v1 = query (0, 1, m); 
			v2 = v1 - 1;
//			if (i == 5) cout << v1 << ' ' << v2 << endl;
			hi = q[i].first; lo = 1; 
	        while (lo < hi){
			    mid = lo + (hi - lo)/2;
			    x = mid;
			    if (query(0, 1, m) <= v2) hi = mid;
			    else lo = mid+1;
		    }
		    x = lo;
		    if (v2 >= query (0, 1, m)){
				x = lo; y = min (q[i].first, x+q[i].second-1);
				update (0, 1, m);
				q[i].first = x-1; 
				q[i].second -= (y-x+1);
		    }
			hi = q[i].first; lo = 1; 
			while (lo < hi){
			    mid = lo + (hi - lo)/2;
			    x = mid;
			    if (query(0, 1, m) <= v1) hi = mid;
			    else lo = mid+1;
		    }
		    x = lo; y = lo + q[i].second -1;
		    //cout << x << ' ' << y << endl;
		    update (0, 1, m);
		}

	}
	for (int i = 1; i <= m; i++){
		x = i; y = i; z = query (0, 1, m);
		ans += (z-1)*(z)/2;
	}
	printf ("%lld\n", ans);
	return 0;
}
