#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d, sum[30005], dp[505][30005], balls[30005];;

int main() {
	cin >> a;
	for (int i = 0; i < a; i++){
		cin >> b >> c >> d; 
		for (int j = 1; j <= b; j++){
			cin >> balls[j];
			if (j <= d) sum[j] = balls[j] + sum[j-1];
			else sum[j] = balls[j] + sum[j-1] - balls[j-d];
		}
		for (int j = 1; j <= c; j++){
			for (int n = 1; n <= b; n++){
				if (n <= d) dp[j][n] = sum[n];
				else dp[j][n] = max(dp[j][n-1], dp[j-1][n-d]+sum[n]);
			}
		}
		cout << dp [c][b] << endl;
		
	}
	return 0;
}
