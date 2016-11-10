#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stdio.h>
using namespace std;

int a, b, c, d, star, des, x, y, dis, pos;
vector <pair <pair <int, int>, int > > graph[110000];
vector <pair <pair <int, int>, int > > rev[110000];
int dist[110000], co[110000], revdist[110000], revco[110000], sum[110000];
vector <pair <int, int> > ans;
pair <pair <int, int>, int> pa;
queue <pair <pair <int, int>, int> > qu;
pair <int, int> p;

int main() {

	cin >> a >> b >> star >> des;
	for (int i = 0; i < b; i++)
	{
	    cin >> x >> y >> dis >> c;
		//scanf ("%d %d %d %d", x, y, dis, c);
		//cout << "runtime";
		pa.first.first = dis;
		pa.first.second = c;
		pa.second = y;
		graph[x].push_back(pa);
		pa.second = x;
		rev[y].push_back(pa);
	}

	for (int i = 0; i < 110000; i++)
	{
		dist[i]=1<<30;
		revdist[i]=1<<30;
	}
	pa.first.first = 0;
	pa.first.second = 0;
	pa.second = star;
	qu.push(pa);
	while (!qu.empty())
	{
		dis=-qu.front().first.first;
		c = qu.front().first.second;
		x = qu.front().second;
		qu.pop();
		if (dist[x]>dis)
		{
			dist[x]=dis;
			co[x] = c;
			for (int i = 0; i < graph[x].size(); i++)
			{
				pa.first.first = -dis-graph[x][i].first.first;
				pa.first.second = c+graph[x][i].first.second;
				pa.second = graph[x][i].second;
				if (dist[graph[x][i].second]>dis+graph[x][i].first.first)qu.push(pa);
			}
		}
	}
	pa.first.first = 0;
	pa.first.second = 0;
	pa.second = des;
	qu.push(pa);
	while (!qu.empty())
	{
		dis=-qu.front().first.first;
		c = qu.front().first.second;
		x = qu.front().second;
		qu.pop();
		if (revdist[x]>dis)
		{
			revdist[x]=dis;
			revco[x] = c;
			for (int i = 0; i < rev[x].size(); i++)
			{
				pa.first.first = -dis-rev[x][i].first.first;
				pa.first.second = c+rev[x][i].first.second;
				pa.second = rev[x][i].second;
				if (revdist[rev[x][i].second]>dis+rev[x][i].first.first)qu.push(pa);
			}
		}
	}
	for (int i = 1; i < 110000; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			if (dist[i]!=1000000&&revdist[graph[i][j].second]!=1000000){
				p.first = dist[i]+revdist[graph[i][j].second]+graph[i][j].first.first;
				p.second = graph[i][j].first.second;
				ans.push_back(p);
			}
		}
	}
	sort (ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++){
		if (i==0) sum[i]=ans[i].second;
		else sum[i]=ans[i].second+sum[i-1];
	}
	cin >> d;
	for (int i = 0; i < d; i++)
	{
		scanf("%d", &x);
		p.first = x;
		p.second = 1<<30;
		pos = upper_bound (ans.begin(), ans.end(), p)-ans.begin();
		if (pos>ans.size()) cout << 0 << endl;
		else cout << sum[pos-1] << endl;
	}

	return 0;
}
