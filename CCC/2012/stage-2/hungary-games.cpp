#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <pair <int, int> > graph[20005];
priority_queue <pair <int, int> > qu, qu1;
int a, b, c, x, y, z, dis, dist[20005][2];

int main() {
	cin >> a >> b; 
	for (int i = 0; i < b; i++){
		cin >> x >> y >> z; 
		graph[x].push_back(make_pair(y, z));
	}
	qu.push(make_pair(0, 1));
	for (int i = 0; i < 20005; i++){
		dist[i][0]=1<<30;
		dist[i][1]=1<<30;
	}
	while (!qu.empty()){
		dis = -qu.top().first;
		x = qu.top().second; 
		qu.pop();
		//cout << x << " " << dis << endl;
		if (dist[x][0]>dis){
			dist[x][1]=dist[x][0];
			dist[x][0]=dis;
		} 
		else if (dist[x][1]>dis&&dis!=dist[x][0]) dist[x][1]=dis;
		else continue;
		for (int i = 0; i < graph[x].size(); i++){
			qu.push(make_pair (-(dis+graph[x][i].second), graph[x][i].first));
		}
	}
	if (dist[a][1]==1<<30) dist[a][1]=-1;
	cout << dist[a][1] << endl;
	return 0;
}
