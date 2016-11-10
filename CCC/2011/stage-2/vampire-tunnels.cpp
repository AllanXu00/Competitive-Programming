#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

vector < pair <int, pair <int, int> > > graph [3100];
int dist[3100]; 
int damage [3100];
bool visit [3100];


int main() {
	int a, b, c, d, e, x, y, dis, lim, dam=0, cam, star, goal;
	pair <int, pair <int, int> > pa;
	priority_queue <pair<int, pair <int, int> > > qu;
	memset (dist, 100000, sizeof dist);
	memset (visit, false, sizeof visit);
	memset (damage, 100000, sizeof damage);
	for (int i = 0; i < 3100; i++)
	{
		dist [i] = 10000000;
		damage[i]= 10000000;
	}
	
	cin >> lim >> a >> b;
	
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d >> e >> cam; 
		if (cam==0)
		{
			pa.second.second = 0;
		}
		else
		{
			pa.second.second = e;
		}
		pa.first = e; 
		pa.second.first = d+1;
		graph [c+1].push_back(pa);
		pa.second.first = c+1;
		graph [d+1].push_back(pa);
		//cout << c << '-' << d << '-' << e << endl;
	}
	
	//cout << "runtime" << endl;
	pa.first = 0; 
	pa.second.first = 1;
	pa.second.second = 0;
	qu.push(pa);
	while (!qu.empty())
	{
		x = qu.top().second.first;
		dis = -qu.top().first;
		dam = qu.top().second.second;
		qu.pop();
		//cout << x << endl;
		if (x==a&&lim>=dam)
		{
			cout << dis << endl;
			return 0;
		}
		for (int i = 0; i < graph[x].size(); i++)
		{
			//cout << "test";
			pa.first = -(dis+graph[x][i].first);
			pa.second.first = graph [x][i].second.first;
			pa.second.second = dam + graph [x][i].second.second;
			//cout << dist [graph [x][i].second.first] << endl;
			//cout << dis +graph[x][i].first << endl;
			if (dist [graph[x][i].second.first]>dis+graph[x][i].first||damage[graph[x][i].second.first]>dam+graph[x][i].second.second)
			{
			qu.push(pa);
			dist [graph[x][i].second.first]=dis+graph[x][i].first;
			damage [graph[x][i].second.first]=dam+graph[x][i].second.second;
			//cout << "yay";
			}
		}
	}
	cout << -1 << endl;
	
	return 0;
}
