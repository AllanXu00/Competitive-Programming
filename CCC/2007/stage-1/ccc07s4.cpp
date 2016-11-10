#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


int a, x, y; 
vector <int> graph [100000];
int dist [100000];
int main() {
	
	cin >> a; 
	memset (dist, 0, sizeof dist);
	dist [1]=1;
	while (1)
	{
		cin >> x >> y; 
		if (x==0) break;
		graph[x].push_back(y);
	}
	
	for (int i = 1; i <= a; i++)
	{
		for (int j = 0; j < graph[i].size(); j++) 
		{
			dist[graph[i][j]] += dist[i];
		}
	}
	
	cout << dist[a] << endl;
	return 0;
}
