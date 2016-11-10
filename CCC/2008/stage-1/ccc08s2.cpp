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

long long x, ans;

int main() {
	while (true){
		scan(x); ans = 0;
		if (!x) break; 
		for (int i = 1; i <= x; i++){
			ans += sqrt((x*x) - (i*i)) + 1;
		}
		ans = ans*4 + 1;
		printf ("%lld\n", ans);
	}
	return 0;
}
