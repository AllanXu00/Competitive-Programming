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
	
	for (int i = 0; i < 3100; i++)
	{
		dist [i] = 10000000;
		damage[i]= 10000000;
	}
	
	cin >> lim >> a >> b;
	
	for (int i = 0; i < b; i++)
	{
		cin >> c >> d >> e >> cam; 
		pa.first = e; 
		pa.second.first = d;
		pa.second.second = cam;
		graph [c].push_back(pa);
		pa.second.first = c;
		graph [d].push_back(pa);
		
	}
	cin >> star >> goal;
	
	pa.first = 0; 
	pa.second.first = star;
	pa.second.second = 0;
	qu.push(pa);
	while (!qu.empty())
	{
		x = qu.top().second.first;
		dis = -qu.top().first;
		dam = qu.top().second.second;
		qu.pop();
		
		if (x==goal&&lim>dam)
		{
			cout << dis << endl;
			return 0;
		}
		if (dis<dist[x] || dam<damage[x]){
		    dist[x]=min(dist[x], dis);
		    damage[x]=min(damage[x], dam);
		    for (int i = 0; i < graph[x].size(); i++)
		    {
			
			pa.first = -(dis+graph[x][i].first);
			pa.second.first = graph [x][i].second.first;
			pa.second.second = dam + graph [x][i].second.second;
			
			
			qu.push(pa);
		    }
		}
	}
	cout << -1 << endl;
	
	return 0;
}
