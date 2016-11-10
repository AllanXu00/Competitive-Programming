#include <bits/stdc++.h>
using namespace std;

int x, visit[65536];
long long cnt, ans, bes, star;

int main() {
	cnt = 1;
	while (true){
		scanf("%d", &x);
		if (x == 0){
			if (ans < cnt - star){
					bes = star;
					ans = cnt - star;
				}	
			break;
		} 
		if (visit[x] >= star){
			if (ans < cnt - star){
				bes = star;
				ans = cnt - star;
			}
			star = visit[x]+1;
		}
		visit[x] = cnt; 
		cnt++;
	}
	rewind(stdin);
	cnt = 1; 
	while (ans > 0){
		cin >> x; 
		if (cnt >= bes){
			cout << x << endl; 
			ans--;
		}
		cnt++;
	}
	return 0;
}
