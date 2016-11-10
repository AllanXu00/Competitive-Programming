#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

char grid[2005][2005]; int dp[2005][2005], n, ans;

int main() {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			scanf (" %c", &grid[i][j]);
		}
	}
	for (int i = n; i > 0; i--){
		for (int j = 1; j <= n; j++){
			if (grid[i][j] != '#') continue;
			if (grid[i+1][j] != '#') dp[i][j] = 1;
			else dp[i][j] = min (dp[i+1][j-1], dp[i+1][j+1]) + 1;
			ans += dp[i][j];
		}
	}
	printf("%d\n", ans);
	return 0;
}
