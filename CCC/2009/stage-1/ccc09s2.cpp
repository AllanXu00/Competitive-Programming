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

int r, c; char a, b;
map <string, bool> f[35];
vector <string> v[35];
string tmp, cur; 

int main() {
	scan(r); scan(c);
	for (int i = 0; i < r; i++){
		tmp = "";
		for (int j = 0; j < c; j++){
			a = getchar();
			b = getchar();
			tmp += a;
		}
		f[i][tmp] = true; v[i].pb(tmp);
	}
	for (int i = 0; i < r-1; i++){ 
		cur = v[i+1][0];
		for (int j = 0; j < v[i].size(); j++){
			tmp = "";
			for (int k = 0; k < v[i][j].length(); k++){
				tmp += (v[i][j][k] == cur[k]) ? "0" : "1";
			}
			if (!f[i+1][tmp]){
				f[i+1][tmp] = true; 
				v[i+1].pb(tmp);
			}
		}
	}
	printf ("%d\n", v[r-1].size());
	return 0;
}
