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

int n; string s, t; long long ans; 

int main() {
    scanf("%d", &n);
    for (int k = 0; k < n; k++){
        set <long long> f;
        cin >> s; 
        for (int i = 0; i < s.length(); i++){
        	long long hash = 1;
        	for (int j = i; j < s.length(); j++){
        		hash = hash*33 ^ (s[j] - 'a' + 1);
        		f.insert(hash);
        	}
        }
        ans = f.size()+1;
        printf ("%lld\n", ans);
    }

	return 0;
}
