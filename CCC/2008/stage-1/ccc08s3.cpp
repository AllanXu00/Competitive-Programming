#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int a, b, c, x, y, ans; 
	bool check;
	cin >> a; 
	//cout << a << endl;
	for (int i = 0; i < a; i++)
	{
		cin >> b >> c; 
		queue <pair <pair <int, int>, int> > q;
		char ar[b+10][c+10];
		bool visit [b+10][c+10];
		check = false;
		memset (visit, true, sizeof visit);
		memset (ar, '*', sizeof ar);
		for (int j = 1; j <= b; j++){
			for (int n = 1; n <= c; n++){
				cin >> ar[j][n];
				visit [j][n]=false;
			}
			
		}
		q.push(make_pair (make_pair(1, 1), 0));
		while (!q.empty())
		{
			x=q.front().first.first; 
			y=q.front().first.second; 
			ans=q.front().second;
			q.pop();
			ans++;
			if (visit [x][y]) continue;
			visit [x][y]=true;
			if (x==b&&y==c){
				cout << ans << endl;
				check = true;
				break;
			}
			if (ar[x][y]=='+'){
				if (!visit[x+1][y]&&ar[x+1][y]!='*'){
					q.push(make_pair (make_pair(x+1, y), ans));
				}
				if (!visit[x-1][y]&&ar[x-1][y]!='*'){
					q.push(make_pair (make_pair(x-1, y), ans));
				}
				if (!visit[x][y+1]&&ar[x][y+1]!='*'){
					q.push(make_pair (make_pair(x, y+1), ans));
				}
				if (!visit[x][y-1]&&ar[x][y-1]!='*'){
					q.push(make_pair (make_pair(x, y-1), ans));
				}
			}
			if (ar[x][y]=='-'){
				if (!visit[x][y+1]&&ar[x][y+1]!='*'){
					q.push(make_pair (make_pair(x, y+1), ans));
				}
				if (!visit[x][y-1]&&ar[x][y-1]!='*'){
					q.push(make_pair (make_pair(x, y-1), ans));
				}
			}
			if (ar[x][y]=='|'){
				if (!visit[x+1][y]&&ar[x+1][y]!='*')
				{
					q.push(make_pair (make_pair(x+1, y), ans));
				}
				if (!visit[x-1][y]&&ar[x-1][y]!='*'){
					q.push(make_pair (make_pair(x-1, y), ans));
				}
			}
		}
		if (!check) cout << -1 << endl;
		while (!q.empty()) q.pop();
	}
	return 0;
}
