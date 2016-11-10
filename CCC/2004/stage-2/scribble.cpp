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

int n, m, x, y, t, ans; char c;
pair <int, int> ar[100], d[100];
string a;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> c >> x >> y;
		ar[c-'A'] = mp(x, y);
	}
	cin >> m; 
	for (int i = 0; i < m; i++){
		cin >> a; t =0; memcpy (&d, &ar, sizeof ar);
		for (int j = 0; j < a.length(); j++){
			d[a[j] - 'A'].second--; 
			if (d[a[j] - 'A'].second < 0){t=0; break;}
			t += d[a[j] - 'A'].first;
		}
		ans = max (ans, t);
	}
	cout << ans << endl;
	return 0;
}
