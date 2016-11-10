#include <iostream>
#include <vector>
#include <stdio.h>
#include <cstring>
using namespace std;

int N, dp[300][2505], rght[2502], lft[2502], cnt=1; 
vector <int> tree[300];
char ch;

void build (int u , int par){
	while( (ch=getchar()) == ' ' || ch == ')');
	if (ch == '('){
		tree[u].push_back(++cnt);build (cnt, u); 
		tree[u].push_back(++cnt);build (cnt, u); 
	}
	else{
		int num = 0; 
		while(ch>='0' && ch <='9'){
			num = num*10+ch-'0';
			ch = getchar();
		}
		for (int i =0 ; i <= 2500; i++) dp[u][i]=num+i;
	}
}

void dfs (int u){
	if (tree[u].empty()) return;
	int l = tree[u][0], r = tree[u][1];
	dfs(l); dfs(r);
	memset (lft, 0, sizeof lft);
	memset (rght, 0, sizeof rght);
	for (int i = 0; i <= N; i++){
		for(int e = i; e >= 0; e--){
			int edge = (1+e)*(1+e), child=dp[l][i-e];
			//if (edge < child) break;
			lft[i]=max(lft[i], min(edge, child));
		}
	}
	for (int i = 0; i <= N; i++){
		for(int e = i; e >= 0; e--){
			int edge = (1+e)*(1+e), child=dp[r][i-e];
			//if (edge < child) break;
			rght[i]=max(rght[i], min(edge, child));
		}
	}
	for (int i = 0; i <= N; i++){
		for (int j = 0; j <= i; j++){
			dp[u][i]=max(dp[u][i], lft[j]+rght[i-j]);
		}
	}
}

int main() {
	build(1, 1);
	while( (ch=getchar()) < '0' || ch > '9'); ungetc(ch, stdin);
	scanf("%d", &N);
	dfs (1);
	cout << dp[1][N] << endl;
	return 0;
}
