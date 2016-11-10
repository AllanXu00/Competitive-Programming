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

bool dp [35][35][35], visit[35][35][35];
int v, t, r1, r2, w, b; 
char x, y, z;
string a; 
vector <char> V, T;
vector <pair <int, int> > rev[30];  
vector <int> f[30]; 

void rs(){
    for (int i = 0; i < a.size(); i++){
        for (int j = 0; j < f[a[i]-'a'+1].size(); j++){
            dp[i][i][f[a[i]-'a'+1][j]] = true; 
        }
    }
}

void solve (int a1, int b, int c){
    if (dp[a1][b][c]) return;
    visit [a1][b][c] = true; 
    int t1, t2; 
    for (int i = 0; i < rev[c].size(); i++){
    	t1 = rev[c][i].first; t2 = rev[c][i].second; 
        for (int j = a1; j < b; j++){
            if (!visit[a1][j][t1]) solve (a1, j, t1);
            if (!visit[j+1][b][t2]) solve (j+1, b, t2);
            if (dp[a1][j][t1] && dp[j+1][b][t2]) dp[a1][b][c] = true; 
        }
    }
    return;
}

int main() {
    scanf("%d%d", &v, &t); 
    for (int i = 0; i < v; i++){ scanf (" %c", &x); V.pb(x); }
    for (int i = 0; i < t; i++){ scanf (" %c", &x); T.pb(x); }
    scanf("%d", &r1);
    for (int i = 0; i < r1; i++){ 
        scanf (" %c %c", &x, &y); 
        f[y-'a'+1].pb(x-'A'+1); 
    }
    scanf("%d", &r2);
    for (int i = 0; i < r2; i++){ 
        scanf (" %c %c %c", &x, &y, &z); 
        rev[x-'A'+1].pb(mp(y-'A'+1, z-'A'+1));
    }
    scanf ("%d", &w);
    for (int i = 0; i < w; i++){
        cin >> a; memset (dp, false, sizeof dp);
        memset (visit, false, sizeof visit);
        rs (); solve (0, a.size()-1, V[0]-'A'+1);
        printf ("%d\n", dp[0][a.size()-1][V[0]-'A'+1]);
    }
	return 0;
}
