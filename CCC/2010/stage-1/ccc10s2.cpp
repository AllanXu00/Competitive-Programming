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

vector <char> ans;
map <string, char> f;
string a, t, b[25];
int n, l; 
char c;
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        cin >> c >> b[i];
        f[b[i]] = c;
    }
    cin >> a;
    while (a.length() > 0){
        for (int i = 0; i < n; i++){
            l = b[i].length(); t = a.substr(0, l);
            if (t == b[i]){
                a = a.substr(l, a.length()-l); 
                ans.pb(f[b[i]]);
            }
        }
    }
    for (int i = 0; i < ans.size(); i++) cout << ans[i];
	return 0;
}
