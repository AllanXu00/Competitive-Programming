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

int n; ll x, y, x1, x2, x3, x4, lo, hi, mid, cnt, bit[1000005];
char t;
vector <pair <char, pair <ll, ll> > > V;
vector <ll> pts; 
unordered_map <ll, ll> comp, rev, f;

void update(ll a, ll b) { 
    while (a <= 1000005){ 
    	//cout << a << endl;
        bit[a] += b; 
        a += (a & -a); 
    } 
}

long long add(ll a){
    ll sum = 0; 
    while (a > 0){
        sum += bit[a];
        a -= (a & -a);
    } 
    return sum;
}

bool query(int num){
	if (add(num) >= add(n)-x1+1) return true; 
	else return false;
}

int bs(int lo, int hi) {
	int mid;
	while (lo < hi) {
		mid = lo + (hi - lo)/2;
		if (query(mid)) hi = mid;
		else lo = mid + 1;
	}
	if (!query(lo)) return hi; 
	return lo;
}

int main() {
    scanf("%lld", &n); 
    for (int i = 0; i < n; i++){
        scanf(" %c", &t); cnt++;
        if (t == 'N' || t == 'M') scanf("%lld%lld", &x, &y);
        else scanf("%lld", &x);
        V.pb(mp(t, mp(x, y)));
        pts.pb(y);
    }
    sort (pts.begin(), pts.end());
    for (int i = 0; i < n; i++) comp[pts[i]] = i+1; 
    for (int i = 0; i < n; i++){
        x1 = V[i].second.first; x2 = V[i].second.second; x3 = comp[x2];
        //cout << V[i].first << " " << x1 << " " << x2 << " " << x3 << endl;
        if (V[i].first == 'N'){
            update(x3, 1);
            f[x1] = x3;
            rev[x3] = x1;
        }
        else if (V[i].first == 'M'){
            x4 = f[x1];
            update(x4, -1);
            update(x3, 1);
            f[x1] = x3;
            rev[x3] = x1;
        }
        else if (V[i].first == 'Q'){
            printf ("%lld\n", rev[bs(0, 1000001)]);
        }
    }
	return 0;
}
