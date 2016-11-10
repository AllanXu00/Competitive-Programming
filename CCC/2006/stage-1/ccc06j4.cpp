#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int a, b, x, y, star=2;
vector <int> graph [10];
vector <int> net [10];
vector <int> ans;
bool visit [10];
bool done [10];
bool check = true;
bool broke;

void dfs(int cur)
{
	//cout << cur << endl;
	broke = false;
	if (visit[cur])
	{
		//cout << "Cannot complete these tasks. Going to bed." << endl;
		//check = false;
		return;
	}
	if (done[cur]||cur>7||cur<1)
	{
		return;
	}
	//cout << cur << endl;
	for (int j = 0; j < net[cur].size();j++)
	{
		
		if (done[net[cur][j]]==false&&visit[net[cur][j]]==false)
		{
			broke = true;
			return;
		}
	}
	
	
	if (broke==false)
	{
		visit [cur]=true;
		ans.push_back(cur);
		//cout << cur << endl;
		
		for (int i = 0; i < graph[cur].size(); i++)
		{
			//dfs (graph[cur][i]);
			
		}
		
		done[cur]=true;
		visit [cur]=false;
	}
	dfs (cur-7);
	dfs (cur-6);
	dfs (cur-5);
	dfs (cur-4);
	dfs (cur-3);
	dfs (cur-2);
	dfs (cur-1);
	dfs (cur+1);
	dfs (cur+2);
	dfs (cur+3);
	dfs (cur+4);
	dfs (cur+5);
	dfs (cur+6);
	dfs (cur+7);
	//cout << cur << endl;
	
		
	
}

int main() {
	memset (visit, false, sizeof visit);
	memset (done, false, sizeof done);
	while (true)
	{
		cin >> x >> y;
		if (star==2&&star==y)
		{
			star = 3;
		}
		else if (star==3&&star==y)
		{
			star = 6;
		}
		else if (star==6&&star==y)
		{
			cout << "Cannot complete these tasks. Going to bed." << endl;
			return 0;
		}	
		if (x==0) break;
		graph[x].push_back(y);
		net[y].push_back(x);
	}
	graph[1].push_back(7);
	graph[1].push_back(4);
	graph[2].push_back(1);
	graph[3].push_back(4);
	graph[3].push_back(5);
	net[7].push_back(1);
	net[4].push_back(1);
	net[1].push_back(2);
	net[4].push_back(3);
	net[5].push_back(3);
	for (int i = 0; i < 10; i++)
	{
		sort (graph[i].begin(), graph[i].end());
	}
	
	
		dfs (star);
	
	if (check==false)
	{
		cout << "Cannot complete these tasks. Going to bed." << endl;
		return 0;
	}
	if (ans.size()<7)
	{
		cout << "Cannot complete these tasks. Going to bed." << endl;
		return 0; 
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i!=0) cout << " " << ans[i];
		else cout << ans[i];
	}
	cout << endl;
	return 0;
}
