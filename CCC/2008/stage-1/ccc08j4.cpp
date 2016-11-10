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

string a;
vector <char> ans;

void dfs (int pos){
	if (a[pos] >= '0' && a[pos] <= '9'){
        ans.pb(a[pos]); a.erase(a.begin()+pos);
        return;
    }
    else{
        dfs(pos+1); dfs(pos+1);
        ans.pb(a[pos]); a.erase(a.begin()+pos);
        return;
    }
}

int main() {
    while (true){
        getline(cin, a); ans.clear();
        remove(a.begin(), a.end(), ' ');
        if (a == "0") break;
        dfs (0);
        for (int i = 0; i < ans.size(); i++){
            cout << ans[i]; if (i != ans.size()-1) cout << " ";
        }
        cout << endl;
    }
	return 0;
}
