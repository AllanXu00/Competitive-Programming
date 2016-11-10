#include <bits/stdc++.h>
using namespace std;

#define inf 1<<30
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

string a;
bool aw(string w);
bool mw (string w){
    int l = w.length();
    bool ch = false;
    if (aw(w)) ch = true;
    for (int i = 1; i < l; i++){
        if (aw(w.substr(0, i)) && mw (w.substr(i+1, l-(i+1))) && w[i] == 'N') ch = true;
    }
    return ch;
}

bool aw (string w){
    int l = w.length();
    bool ch = false;
    if (w == "A") ch = true;
    else if (w[0] == 'B' && w[l-1] == 'S' && mw(w.substr(1, l-2))) ch = true;
    return ch;
}

int main() {
    while (true){
        cin >> a;
        if (a == "X") break;
        if (mw(a)) printf ("YES\n");
        else printf ("NO\n");
    }
	return 0;
}
