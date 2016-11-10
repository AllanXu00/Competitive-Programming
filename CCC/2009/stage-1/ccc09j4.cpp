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

int w, c, s, g, d, psa[8] = {7, 2, 3, 4, 4, 5, 0, 0};
string ar[8] = {"WELCOME", "TO", "CCC", "GOOD", "LUCK", "TODAY", "", ""};
vector <string> ans;

int main() {
    scan(w);
    while (c <= 6){
    	if (c > 0) psa[c] += psa[c-1];
        if (psa[c] < w-ans.size()+1 && c < 6){
            ans.pb(ar[c]); c++; 
        }
        else{
            g = w - psa[c-1]; 
            if (ans.size() > 1) s = g/(ans.size()-1);
            else s = 0;
            if (ans.size() > 1) d = g%(ans.size()-1);
            else d = 0;
            for (int i = 0; i < ans.size(); i++){
                cout << ans[i];
                if (i != ans.size()-1) for (int j = 0; j < s; j++){ printf ("."); g--;}
                if (d > 0){ printf ("."); d--; g--;}
            }
            while (g > 0){ cout << '.'; g--; }
            cout << endl;
            psa[c] -= psa[c-1];
            ans.clear();
            ans.pb(ar[c]); c++; 
        }
    }
	return 0;
}
