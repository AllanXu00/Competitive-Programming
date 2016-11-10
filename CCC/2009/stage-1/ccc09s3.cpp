#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

vector <int> graph[55];
bool con, visit[55];
int x, y, ans, dis, pos;
queue <pair <int, int> > q;
char c;

int main() {
	graph[2].push_back(6);
	graph[6].push_back(2);
	graph[1].push_back(6);
	graph[6].push_back(1);
	graph[3].push_back(6);
	graph[6].push_back(3);
	graph[4].push_back(6);
	graph[6].push_back(4);
	graph[5].push_back(6);
	graph[6].push_back(5);
	graph[7].push_back(6);
	graph[6].push_back(7);
	graph[3].push_back(4);
	graph[4].push_back(3);
	graph[3].push_back(5);
	graph[5].push_back(3);
	graph[4].push_back(5);
	graph[5].push_back(4);
	graph[3].push_back(15);
	graph[15].push_back(3);
	graph[15].push_back(13);
	graph[13].push_back(15);
	graph[13].push_back(12);
	graph[12].push_back(13);
	graph[13].push_back(14);
	graph[14].push_back(13);
	graph[12].push_back(9);
	graph[9].push_back(12);
	graph[16].push_back(18);
	graph[18].push_back(16);
	graph[16].push_back(17);
	graph[17].push_back(16);
	graph[17].push_back(18);
	graph[18].push_back(17);
	graph[7].push_back(8);
	graph[8].push_back(7);
	graph[9].push_back(8);
	graph[8].push_back(9);
	graph[9].push_back(10);
	graph[10].push_back(9);
	graph[11].push_back(10);
	graph[10].push_back(11);
	graph[11].push_back(12);
	graph[12].push_back(11);
	while (true){
		cin >> c; 
		ans = 0; 
		con = false;
		memset(visit, false, sizeof visit);
		while (!q.empty())q.pop();
		if (c=='i'){
			cin >> x >> y; 
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		else if (c=='d'){
			cin >> x >> y; 
			for (int i = 0; i < graph[x].size(); i++){
				if (graph[x][i]==y)graph[x].erase(graph[x].begin()+i);
			}
			for (int i = 0; i < graph[y].size(); i++){
				if (graph[y][i]==x)graph[y].erase(graph[y].begin()+i);
			}
		}
		else if (c=='n'){
			cin >> x;
			cout << graph[x].size()<< endl;
		}
		else if (c=='f'){
			cin >> x;
			q.push(make_pair(x, 0));
			while (!q.empty()){
				pos=q.front().first;
				dis=q.front().second;
				q.pop();
				if (visit[pos]) continue;
				visit[pos]=true;
				if (dis==2) ans++;
				else{
					for (int i = 0; i < graph[pos].size(); i++) q.push(make_pair(graph[pos][i], dis+1));
				}
			}
			cout << ans << endl;
		}
		else if (c=='s'){
			cin >> x >> y; 
			q.push(make_pair(x, 0));
			while (!q.empty()){
				pos=q.front().first;
				dis=q.front().second;
				q.pop();
				//cout << pos << endl;
				if (visit[pos]) continue;
				visit[pos]=true;
				if (pos==y){
					con = true;
					cout << dis << endl; 
					break;
				}
				for (int i = 0; i < graph[pos].size(); i++) q.push(make_pair(graph[pos][i], dis+1));
				
			}
			if (!con)cout << "Not connected" << endl;
		}
		else return 0;
		
	}
	return 0;
}
