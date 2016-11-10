#include <iostream>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <cstring>
using namespace std;

int r, c, s, diff[31005][1105], ans, cnt, x, y, rad, br, xs, xe, ys, ye, hyp;

int main() {
	scanf("%d%d%d", &r, &c, &s);
	for (int i = 0; i < s; i++){
        scanf("%d%d%d%d", &y, &x, &rad, &br);
        for(int j = max(y-rad, 1); j <= min(y+rad, c); j++){
            if (j==y){
                xs = x - rad;
                xe = x + rad;
            }
            else if (j == y-rad || j == y+rad){
                xs = x;
                xe = x;
            }
            else{
                hyp = sqrt(rad*rad-(y-j)*(y-j));
                xs = x - hyp;
                xe = x + hyp;
            }
            diff[max (xs, 1)][j] += br;
            if (xe+1<=r)diff[xe+1][j] -= br;
        }
	}
	for (int j = c; j > 0; j--){
        for (int i = 1; i <= r; i++){
            diff[i][j]+=diff[i-1][j];
            ans = max (ans, diff[i][j]);
            //cout << diff[i][j] << " ";
        }
        //cout << endl;
	}
	for (int i = 1; i <= r; i++){
        for (int j = 1; j <= c; j++){
            if (diff[i][j]==ans) cnt++;
        }
	}
	printf("%d\n%d\n", ans, cnt);
	return 0;
}
