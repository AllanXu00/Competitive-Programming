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

int b, s, ans; char a; string buff;
queue <char> q;
vector <int> v1, v2; 

int main() {
    scan(s); scan(b);
    for (int i = 0; i < 60; i++){ v1.pb(0); v2.pb(0); }
    for (int i = 0; i < s; i++) {
    	a = getchar();
    	v1[a-'A']++;
    } 
    a = getchar();
    for (int i = 0; i < b; i++){
    	a = getchar();
    	q.push(a); v2[a-'A']++;
    	if (q.size() > s){
    		a = q.front(); q.pop();
    		v2[a-'A']--;
    	} 
    	if (v1 == v2) ans++;
    }
    printf ("%d\n", ans);
	return 0;
}
