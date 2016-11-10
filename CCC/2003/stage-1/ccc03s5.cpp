#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue <pair <int, int> > qu; 
pair <int, int> pa; 
vector <pair <int, int> > graph[10100]; 
int a, b, c, x, y, z, dis, ans=10000000; 
int dist [10100], q[10100];

int main() {
	
	cin >> a >> b >> c; 
	for (int i = 0; i < b; i++)
	{
		cin >> x >> y >> z; 
		pa.first = z; 
		pa.second = x; 
		graph[y].push_back(pa);
		pa.second = y; 
		graph[x].push_back(pa);
	}
	for (int i = 0; i < 10100; i++)
	{
		dist[i]=0;
	}
	pa.first = 1000000; 
	pa.second = 1; 
	qu.push(pa);
	while (!qu.empty())
	{
		dis = qu.top().first;
		x = qu.top().second;
		qu.pop();
		if (dist[x]<dis)
		{
			dist[x]=dis;
			for (int i = 0; i < graph[x].size(); i++)
			{
				pa.first = min(graph[x][i].first, dis);
				pa.second = graph[x][i].second;
				qu.push(pa);
			}
		}
		
	}
	for (int i = 0; i < c; i++)
	{
		cin >> q[i];
		ans = min (dist[q[i]], ans);
	}
	cout << ans << endl;
	return 0;
}
