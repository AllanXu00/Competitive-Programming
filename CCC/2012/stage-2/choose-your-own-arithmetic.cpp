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

int n, m, k, x, dis; bool ans;
char o[10];
vector <int> val, goal;
queue <pair <int, int> > q;
unordered_map <int, bool> visit[15];

int main() {
    scan(n); scan(m); memset (o, 'N', sizeof o);
    for (int i = 0; i < m; i++){ scan(x); val.pb(x); }
    scan(k);
    for (int i = 0; i < k; i++) { scan(x); goal.pb(x); }
    sort (goal.begin(), goal.end());
    for (int i = 0; i < val.size(); i++) q.push(mp(val[i], 0));
    while (!q.empty()){
        x = q.front().first; 
        dis = q.front().second;
        q.pop();
        if (visit[dis][x]) continue; 
        visit[dis][x] = true; 
        if (dis == n){
            for (int i = 0; i < goal.size(); i++){
                if (x == goal[i]){
                    o[i] = 'Y';
                }
            }
            continue;
        }
        for (int i = 0; i < val.size(); i++){
            q.push(mp(x*val[i], dis+1));
            q.push(mp(x+val[i], dis+1));
        }
    }
    for (int i = 0; i < k; i++) printf ("%c\n", o[i]);
	return 0;
}
