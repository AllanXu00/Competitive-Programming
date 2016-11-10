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

map <string, bool> f;
string a, b, c;
char u;
int n;

void create (int ind, string t){
	if (ind == 5){
		f[t] = true;
		return;
	}
	int pos = ind*2; 
	for (int i = pos; i <= pos + 1; i++){
		for (int j = pos; j <= pos+1; j++){
			u = min (a[i], b[j]);
			create (ind+1, t+u);
		}
	}
	return;
}

int main() {
	cin >> a >> b >> n; 
	create(0, "");
	for (int i = 0; i < n; i++){
		cin >> c; 
		if (f[c]) cout << "Possible baby." << endl; 
		else cout << "Not their baby!" << endl;
	}
	return 0;
}
