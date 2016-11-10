#include <iostream>
#include <cstring>
using namespace std;

bool dp [31][31][31][31];
int x, a1, b1, c1, d1;
bool r1, r2, r3, r4, r5, ans;

bool dfs (int a, int b, int c, int d){
	if (a<0 || b<0 || c<0 || d<0) return false;
	else return !dp[a][b][c][d];
}

int main() {
	int x; 
	memset (dp, false, sizeof dp);
	for (int i = 0; i <= 30; i++){
		for (int j = 0; j <= 30; j++){
			for (int n = 0; n <= 30; n++){
				for (int k = 0; k <= 30; k++){
					r1 = dfs (i-2, j-1, n, k-2);
					r2 = dfs (i-1, j-1, n-1, k-1);
					r3 = dfs (i, j, n-2, k-1);
					r4 = dfs(i, j-3, n, k);
					r5 = dfs (i-1, j, n, k-1);
					dp[i][j][n][k]= (r1 || r2 || r3 || r4 || r5);
				}
			}
			
		}
	}
	cin >> x;
	for (int i = 0; i < x; i++){
		cin >> a1 >> b1 >> c1 >> d1; 
		if (dp[a1][b1][c1][d1]) cout << "Patrick" << endl;
		else cout << "Roland" << endl;
	}
	return 0;
}
