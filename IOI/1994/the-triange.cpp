#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, dp[105][105], tr[105][105], ans;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            scanf("%d", &tr[i][j]);
        }
	}
	dp[1][1] = tr[1][1];
	for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i; j++){
            dp[i+1][j] = max (dp[i+1][j], dp[i][j]+tr[i+1][j]);
            dp[i+1][j+1] = max (dp[i+1][j+1], dp[i][j] + tr[i+1][j+1]);
            ans = max (ans, dp[i][j]);
        }
	}
	printf("%d\n", ans);
	return 0;
}
