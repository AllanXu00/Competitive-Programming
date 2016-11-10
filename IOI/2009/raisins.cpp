#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int dp[55][55][55][55], ps[55][55], r, c;

int dfs(int x1, int y1, int x2, int y2){
    if (dp[x1][y1][x2][y2] <= 30000000) return dp[x1][y1][x2][y2];
    if (x1 == x2 && y1 == y2) return ps[x2][y2] - ps[x2-1][y2] - ps[x2][y2-1]+ ps[x2-1][y2-1];
    for (int i = x1; i < x2; i++){
        int tot = dfs(x1, y1, i, y2) + dfs(i+1, y1, x2, y2);
        dp[x1][y1][x2][y2] = min (dp[x1][y1][x2][y2], tot+ps[x2][y2]+ps[x1-1][y1-1]-ps[x1-1][y2]-ps[x2][y1-1]);
    }
    for (int i = y1; i < y2; i++){
        int tot = dfs(x1, y1, x2, i) + dfs(x1, i+1, x2, y2);
        dp[x1][y1][x2][y2] = min (dp[x1][y1][x2][y2], tot+ps[x2][y2]+ps[x1-1][y1-1]-ps[x1-1][y2]-ps[x2][y1-1]);
    }
    return dp[x1][y1][x2][y2];
}

int main() {
    scanf ("%d%d", &r, &c);
    for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            scanf ("%d", &ps[i][j]);
            ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
	memset (dp, 0x3f, sizeof dp);
	dfs (1, 1, r, c);
	if (r == 1 && c == 1) dp[1][1][1][1] = ps[r][c];
	printf ("%d\n", dp[1][1][r][c]-ps[r][c]);
	return 0;
}
