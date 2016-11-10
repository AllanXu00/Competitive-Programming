#include<iostream>
#include<algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

#define x first
#define y second
#define p2 pair<int, int>
int n, p, lo, z;
p2 a[5005];
p2 h[5005];
double ans;
int cross(p2 A, p2 O, p2 B){
    return (O.x-A.x)*(O.y-B.y)-(O.x-B.x)*(O.y-A.y);
}
int main(){
    cin >> z;
    for (int i =0 ; i< z; i++){
        cin >> n;
        ans = 0;
        memset (a, 0, sizeof 0);
        memset (h, 0, sizeof 0);
        for (int l=0; l<n; l++){
            cin >> a[l].x >> a[l].y;
        }
        sort(a, a+n);
        h[0]=a[0]; h[1]=a[1];
        p=2;
        for (int l=2; l<n; l++){
            while (p>=2 && cross(h[p-2], h[p-1], a[l])<=0) p--;
            h[p++]=a[l];
        }
        lo=p+1;
        for (int l=n-2; l>=0; l--){
            while(p>=lo && cross(h[p-2], h[p-1], a[l])<=0) p--;
            h[p++]=a[l];
        }
        for (int l=1; l<p; l++){
            //cout << h[l].x << ' ' << h[l].y << endl;
            ans += sqrt (abs(h[l].x-h[l-1].x) * abs(h[l].x-h[l-1].x) + abs(h[l].y-h[l-1].y) * abs(h[l].y-h[l-1].y));
        }
        ans += sqrt (abs(h[p-1].x-h[0].x) * abs(h[p-1].x-h[0].x) + abs(h[p-1].y-h[0].y) * abs(h[p-1].y-h[0].y));
        printf("%.2f\n", ans);
    }
    return 0;
}
