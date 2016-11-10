#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

long long ar[1000005], ar2[1000005], tree[5000005], a, x, y, q, z;
double ans;
map <long long, int> f;

void build (int n, int lo, int hi){
	if (lo == hi){
		tree[n]=ar[hi];
		return;
	}
	build (2*n+1, lo, (lo+hi)/2);
	build (2*n+2, (lo+hi)/2+1, hi);
	tree[n] = tree[2*n+1] + tree[2*n+2];
}

void update(int n, int lo, int hi){
	if (hi < q || lo > q) return;
	if (lo == hi){
		tree[n] += 1;
		return;
	}
	update (2*n+1, lo, (lo+hi)/2);
	update (2*n + 2, (lo + hi)/2+1, hi);
	tree[n] = tree[2*n+1] + tree[2*n+2];
}

int query (int n, int lo, int hi){
	if (hi < x || lo > y) return 0;
	if (lo >= x && hi <= y) return tree[n];
	return query (2*n+1, lo, (lo+hi)/2) + query (2*n+2, (lo+hi)/2+1, hi);
}


int main() {
    scan(a);
    for (int i = 0; i < a; i++) scan(ar[i]);
    memcpy (ar2, ar, sizeof ar);
    sort (ar, ar+a);
    for (int i = 0; i < a; i++) f[ar[i]] = i;
    for (int i = 0; i < a; i++){
        q = f[ar2[i]]; x = q+1; y = 100004;
        update (0, 0, 100004);
        ans += query(0, 0, 100004)+1;
    }
    printf ("%.2f\n", ans/a);
	return 0;
}
