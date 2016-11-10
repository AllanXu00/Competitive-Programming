#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int r, c, grid[105][105], dp[105][105][2];// 0 = up, 1 = down
char t; 

int main() {
	while (true){
		scanf ("%d%d", &r, &c);
		memset (grid, 0, sizeof grid);
		memset (dp, 0, sizeof dp);
		if (r == 0) break;
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= c; j++){
				scanf(" %c", &t);
				if (t == '*') grid[i][j] = -1<<30;
				else if (t == '.') grid[i][j] = 0;
				else grid[i][j] = t -'0';
			}
		}
		for (int i = r; i >= 1; i--){
			dp[i][1][0] = dp[i+1][1][0] + grid[i][1];
		}
		for (int j = 2; j <= c; j++){
			for (int i = r; i >= 1; i--){
				dp[i][j][0] = grid[i][j] + max(max(dp[i][j-1][0], dp[i][j-1][1]),
											   dp[i+1][j][0]);
			}
			for (int i = 1; i <= r; i++){
				dp[i][j][1] = grid[i][j] + max(max(dp[i][j-1][0], dp[i][j-1][1]),
											   dp[i-1][j][1]);
			}
		}
		printf("%d\n", max(dp[r][c][0], dp[r][c][1]));
	}
	return 0;
}
