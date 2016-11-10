#include <iostream>
#include <queue>
using namespace std;

int a, x, y, t1, t2, xg, yg, ans=0; 
bool grid[27][27];
int dist [27][27];
pair <int, int> pa;
queue <pair <int, int> > qu;

int main() {
	cin >> xg >> yg; 
	cin >> a; 
	for (int i = 0; i <= 26; i++){
		for (int j = 0; j <= 26; j++){
			dist [i][j]=0;	
		}
	}
	dist [1][1]=1;
	for (int i = 0; i < a; i++){
		cin >> t1 >> t2;
		grid [t1][t2]=true;
	}
	for (int i = 1; i <= xg; i++){
		for (int j = 1; j <= yg; j++){
			if (grid[i][j]) continue;
			dist[i][j] += dist[i-1][j] + dist[i][j-1]; 
		}
	}
	cout << dist[xg][yg] << endl;
	return 0;
}
