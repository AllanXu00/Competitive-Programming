#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int  edges, a, b, cnt, num[101], low[101], nodes;
bool visit [101];
vector <int> graph[101];
vector <pair <int, int> > ans;
char x, y;

void dfs (int a, int c){
	int b; 
	low[a] = num[a] = ++cnt;
	for (int j = 0; j < graph[a].size(); j++){
		if (num[b=graph[a][j]] == -1){
			dfs (b, a);
			low[a]= min(low[a], low[b]);
		}
		else if (b != c) low[a] = min (low[a], num[b]);
	}
	for (int j = 0; j < graph[a].size(); j++){
		if (low[b= graph[a][j]] > num[a]) ans.push_back(make_pair(a, b));
	}
}

int main() {
	while (true){
		cin >> x >> y; 
		if (x== '*'|| y == '*') break;
		graph[int(x-65)].push_back(int(y-65));
		graph[int(y-65)].push_back(int(x-65));
		nodes++;
	}
	memset (num, -1, sizeof num);
	memset (low, -1, sizeof low);
	for (int i = 0; i < nodes; i++){
		if (num[i] == -1) dfs (i, -1);
	}
	for (int i = 0; i < ans.size(); i++) cout << char (ans[i].first+65) <<  char(ans[i].second+65) << endl;
	cout << "There are " << ans.size() << " disconnecting roads." << endl;
	return 0;
}
