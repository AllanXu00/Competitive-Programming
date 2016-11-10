#include <bits/stdc++.h>
using namespace std;

#define inf 0x3f
#define mp make_pair
#define pb push_back
char _inp[4097], *_pinp=_inp;
#define getchar() (*_pinp?*_pinp++:(_inp[fread(_pinp=_inp, 1, 4096, stdin)]='\0', *_pinp++))
#define scan(x) do{while((x=getchar())<'-'); _ssign=x=='-'; if(_ssign) while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0'); x=_ssign?-x:x;}while(0)
char _; bool _ssign;

int n, m, q, x, y, z, dist[1005][1005];

void floyd_warshall(int nodes) {
  for (int k = 1; k <= nodes; k++)
   for (int i = 1; i <= nodes; i++)
    for (int j = 1; j <= nodes; j++)
      if (dist[i][j] > dist[i][k] + dist[k][j]) {
        dist[i][j] = dist[i][k] + dist[k][j];
      }
}

int main() {
    scan(m); scan(n); scan(q);
    memset (dist, 0x3f, sizeof dist);
    for (int i = 0; i < m; i++) dist[i][i] = 0;
    for (int i = 0; i < n; i++){
        scan(x); scan(y); scan(z);
        dist[x][y] = z;
        dist[y][x] = z;
    }
    floyd_warshall(m);
    for (int i = 0; i < q; i++){
        scan(x); scan(y);
        printf("%d\n", dist[x][y]);
    }
	return 0;
}
