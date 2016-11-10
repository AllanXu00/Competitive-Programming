#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
using namespace std;

int n, x, y, t;
vector <int> num, comp, graph[105];
bool visit[105];

int gcd (int a, int b){return b ? gcd(b, a%b) : a;}
int lcm (int a, int b){
	if (a == 0 || b == 0) return 0;
	return a / gcd(a, b) * b;
}
void dfs (int u){
	if (visit[u]) return;
	visit[u] = true;
	comp.push_back(u);
	for (int i = 0; i < graph[u].size(); i++) dfs(graph[u][i]);
}
void an(int s){
	int ans = num[0];
	for (int i = 1; i < s; i++) ans = lcm(ans, num[i]);
	printf("%d\n", ans);
}

int main() {
	while (true){
		scanf ("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++){
			scanf("%d%d", &x, &y);
			graph[x].push_back(y);
		}
		for (int i = 1; i <= n; i++){
			if (!visit[i]){
				dfs (i);
				num.push_back(comp.size());
				comp.clear();
			} 
		}
		an(num.size());
		memset (visit, false, sizeof visit);
		for (int i = 0; i < 105; i++)graph[i].clear();
		num.clear();
	}
	return 0;
}
