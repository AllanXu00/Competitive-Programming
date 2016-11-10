#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstdio>
#include <stdio.h>
using namespace std;

priority_queue <pair <int, int> > qu;
pair <int, int> pa; 
vector <pair <int, int> > graph[5100];
int a, b, c, d, x, y, z, dis, an, mi=10000000, star;

int dist [5100];


int main() {
	scanf ("%d",&a);
	scanf ("%d",&b);
	
	for (int i = 0; i < b; i++)
	{
		scanf ("%d",&x);
		scanf ("%d",&y);
		scanf ("%d",&dis);
		pa.first = dis; 
		pa.second = y; 
		graph[x].push_back(pa);
		pa.second = x;
		graph[y].push_back(pa);
	}
	for (int i = 0; i < 5100; i++)
	{
		dist[i]=10000000;
	}
	
	
	
	scanf ("%d",&c);
	pair <int, int> ar[c];
	for (int i = 0; i < c; i++)
	{
		scanf ("%d",&ar[i].first);  
		scanf ("%d",&ar[i].second);  
	}
	scanf ("%d",&star);
	
	
	
	for (int i = 0; i < c; i++)
	{
	pa.first = 0; 
	pa.second = star; 
	qu.push(pa);
	if (dist[ar[i].first]==10000000)
	{
	while (!qu.empty())
	{
		dis = -qu.top().first; 
		x = qu.top().second; 
		qu.pop();
		
		if (x==ar[i].first)
		{
			break;
		}
		
		if (dist[x]>dis)
		{
			for (int j = 0; j < graph[x].size(); j++)
			{
				pa.first = - (dis+graph[x][j].first);
				pa.second = graph[x][j].second; 
				if (dist[graph[x][j].second] > -pa.first)
				{
					qu.push(pa);
				}
			}
			dist[x]=dis;
		}
	}
	while (!qu.empty())
	{
		qu.pop();
	}
	}
	mi = min (dist [ar[i].first]+ar[i].second, mi);
	
	}
	cout << mi << endl;
	return 0;
}
