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

int n, a, b, c, d, ans;
vector <int> v;

void dfs (vector <int> vec){
	vector <int> mew;
	if (vec.size() == 1){
		if (vec[0] <= 24){ ans = max (ans, vec[0]); return; }
		else return;
	}
	for (int i = 0; i < vec.size(); i++){
		for (int j = 0; j < vec.size(); j++){
			if (i != j){
				for (int k = 0; k < vec.size(); k++){
					if (k != i && k != j) mew.pb(vec[k]);
				}
				mew.pb(vec[i] + vec[j]); dfs(mew); mew.pop_back();
				mew.pb(vec[i] - vec[j]); dfs(mew); mew.pop_back();
				mew.pb(vec[i] * vec[j]); dfs(mew); mew.pop_back();
				if (vec[j] != 0 && vec[i] % vec[j] == 0){
					mew.pb(vec[i] / vec[j]); dfs(mew); mew.pop_back();
				}
				mew.clear();
			}
		}
	}
	return;
}

int main() {
	scan(n);
	for (int i = 0; i < n; i++){
		scan(a); scan(b); scan(c); scan(d); ans = 0; 
		v.pb(a); v.pb(b); v.pb(c); v.pb(d); dfs(v); v.clear();
		printf ("%d\n", ans);
	}
	return 0;
}
