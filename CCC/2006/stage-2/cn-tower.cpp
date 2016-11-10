#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define ll long long
#define mp make_pair
#define pb push_back
#define f first
#define s second
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

int n;
double ans, tmp, ar[2005];
string b;

int main() {
    cin >> n; 
    for (int i = 0; i < n; i++){
        cin >> b >> ar[i];
        ar[i+n] = (ar[i]) + 360;  
    }
    sort (ar, ar+2*n);
    ans = ar[n-1] - ar[0];
    for (int i = n; i < 2*n; i++){
        tmp = ar[i] - ar[i-n+1]; 
        ans = min(ans, tmp);
    }
    cout << ceil(ans/360 * 4320) << endl; 
	return 0;
}
