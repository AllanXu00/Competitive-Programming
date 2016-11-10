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

int n, cx, cy, t1, t2; ll x, y, ans, two=2; 
map <ll, int> f;
vector <pair <ll, ll> > pts; 
vector <ll> comp; 
vector <int> xa[200005], ya[200005];

int main() {
    scan(n);
    for (int i = 0; i < n; i++){
        scan(x); scan(y);
        comp.pb(x); comp.pb(y);
        pts.pb(mp(x, y));
    }
    sort (comp.begin(), comp.end());
    for (int i = 0; i < comp.size(); i++){
        f[comp[i]] = i; 
        //cout << comp[i] << " " << i << endl;
    }
    for (int i = 0; i < pts.size(); i++){
        cx = f[pts[i].first]; cy = f[pts[i].second];
        xa[cx].pb(cy); ya[cy].pb(cx);
    }
    for (int i = 0; i < 200005; i++){
        sort (xa[i].begin(), xa[i].end());
        sort (ya[i].begin(), ya[i].end());
    }
    //cout << "runtime" << endl;
    for (int i = 0; i < 200005; i++){
    	//cout << i << endl;
        for (int j = 0; j < xa[i].size(); j++){
            cy = xa[i][j]; cx = i;
            t1 = lower_bound (ya[cy].begin(), ya[cy].end(), cx) - ya[cy].begin();
            t2 = ya[cy].size() - t1 - 1;
            ans += two *  j * (xa[i].size()-j-1) * t1 * t2;
        }
    }
    printf ("%lld\n", ans);
	return 0;
}
