#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int rice, dp[405][405];
bool f [405][405];

int dfs (int l, int r){
    if (dp[l][r] != 0) return dp[l][r];
    int ans = 0;
    for (int i = l; i < r; i++){
        int left = dfs(l, i), right = dfs(i+1, r);
        if (f[l][i] && f[i+1][r] && left == right){
            f[l][r] = true;
            ans = max (ans, left+right);
        }
        else ans = max (ans, max(left, right));
    }
    for (int i = l, j = r; i < j-1;){
        int left = dfs (l, i), mid = dfs (i+1, j-1), right = dfs (j, r);
        if (left == right && f[l][i] && f[i+1][j-1] && f[j][r]){
            ans = max (ans, left + mid + right);
            f[l][r] = true;
            i++; //j--;
        }
        else{
            if (left < right){
                ans = max (max (ans, left), max (mid, right));
                i++;
            }
            else{
            ans = max (max (ans, left), max (mid, right));
            j--;
            }
        }
    }
    dp[l][r] = ans;
    return ans;
}

int main() {
	scanf ("%d", &rice);
	for (int i = 1; i <= rice; ++i){
        scanf ("%d", &dp[i][i]);
        f[i][i] = true;
	}
	printf("%d\n", dfs (1, rice));
	return 0;
}
 
