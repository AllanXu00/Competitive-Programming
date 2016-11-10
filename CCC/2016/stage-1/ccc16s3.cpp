#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

#define mp make_pair

bool visit[100005], pho[100005], need[100005];
vector <int> graph[100005];
int nodes, phos, p, x, y, dis, start, diam, tot, D;
queue <pair <int, int> > q;

void dfs (int n){
	visit[n] = true;
	need[n] = pho[n];
	for (int i = 0; i < graph[n].size(); i++){
		if (!visit[graph[n][i]]){
			dfs (graph[n][i]);
			need[n] = need[n] || need[graph[n][i]];
		}
	}
}

int main() {
	scanf ("%d%d", &nodes, &phos);
	for (int i = 0; i < phos; i++){
		scanf("%d", &p);
		pho[p] = true;
	}
	for (int i = 0; i < nodes-1; i++){
		scanf("%d%d", &x, &y);
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	dfs (p);
	memset (visit, false, sizeof visit);
	q.push(mp(0, p));
	while (!q.empty()){
		dis = q.front().first;
		D = q.front().second;
		q.pop();
		if (!need[D]) continue;
		if (visit[D]) continue;
		//cout << dis << ' ' << D << endl;
		x = D;
		visit[x] = true;
		for (int i = 0; i < graph[x].size(); i++){
			q.push(mp(dis+1, graph[x][i]));
		}
	}
	start = x;
	q.push(mp(0, start));
	memset (visit, false, sizeof visit);
	while (!q.empty()){
		D = q.front().first;
		x = q.front().second;
		q.pop();
		if (!need[x]) continue;
		if (visit[x])continue;
		//cout << x << ' ' << D << endl;
		dis = D;
		visit[x] = true;
		for (int i = 0; i < graph[x].size(); i++){
			q.push(mp(dis+1, graph[x][i]));
		}
	}
	diam = dis;
	for (int i = 0; i < nodes; i++){
		for (int j = 0; j < graph[i].size(); j++){
			if (need[i] && need[graph[i][j]]) ++tot;
		}
	}
	printf("%d", tot-diam);
	return 0;
}
