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

int a, b, c, n, s, cnt;

int main() {
	scan(n);
	for (int i = 0; i < n; i++){
		scan(a); s = a; b = 0; c = 0; cnt = 0;
		while (c < s-2){
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			c += b/2; b = b/2 + b%2 + a/2; a = a/2 + a%2;   cnt++;
		}
		if (a == 2 && b == 0){
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			a--; cnt++; b++;
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			a--; cnt++; b++;
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			cnt++; b--; c++;
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
		} 
		else if (a == 1 && b == 1){
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			a--; cnt++; b++;
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			cnt++; b--; c++;
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
		} 
		else if (a == 0 && b == 2){
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
			cnt++; b--; c++;
			printf ("Round %d: %d undefeated, %d one-loss, %d eliminated\n", cnt, a, b, c);
		}
		printf ("There are %d rounds.\n", cnt);
	}
	return 0;
}
