#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#define pb push_back
#define mp make_pair
#include <cmath>
#include <algorithm>
#include <cstdio>
#define rep(i,j) for(int i = 0; i < j; i++)
using namespace std;
 
typedef long long ll;
 
int N,M,a,b;
 
int main(){
 
    cin >> N >> M;
    vector<int> route[N+1];
 
    rep(i,M){
        cin >> a >> b;
        route[a].pb(b);
    }
 
    cin >> a >> b;
    queue<int> q,qq;
 
    int vis[N+1];
    memset(vis,false,sizeof(vis));
 
    bool aa = false, bb = false;
 
    q.push(a);
    while(!q.empty()){
        int c = q.front();
        q.pop();
        vis[c] = true;
        if(c == b){
            aa = true;
            break;
        }
        for(int i = 0; i < route[c].size(); i++){
            if(!vis[route[c][i]]) {
                q.push(route[c][i]);
                vis[route[c][i]] = true;
            }
        }
    }
    memset(vis,false,sizeof(vis));
    qq.push(b);
    while(!qq.empty()){
        int c = qq.front();
        qq.pop();
        vis[c] = true;
        if(c == a){
            bb = true;
            break;
        }
        for(int i = 0; i < route[c].size(); i++){
            if(!vis[route[c][i]]) {
                qq.push(route[c][i]);
                vis[route[c][i]] = true;
            }
        }
    }
 
    if(aa) cout << "yes" << endl;
    else if(bb) cout << "no" << endl;
    else cout << "unknown" << endl;
 
    return 0;
}
