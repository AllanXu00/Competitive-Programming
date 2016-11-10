#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int dp[3105][3105], f, v, x, y, t, n, ty, tot;
vector <int> value[3105], co[3105];

int main() {
	scanf("%d%d", &ty,&n);
	for (int i = 1; i <= n; i++){
		scanf("%d%d%d", &y, &x, &t);
		co[t].push_back(y);
		value[t].push_back(x);
	}
	scanf("%d", &tot);
	for (int i = 1; i <= ty; i++){
		for (int j = 0; j < value[i].size(); j++){
			for (int k = 0; k <= tot; k++){
				if (co[i][j] <= k) dp[i][k] = max (max (dp[i][k], dp[i-1][k]), dp[i-1][k-co[i][j]]+value[i][j]);
				else dp[i][k] = max (dp[i][k], dp[i-1][k]);
			}
		}
	}
	printf("%d\n", dp[ty][tot]);
	return 0;
}
