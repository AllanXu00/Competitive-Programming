#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int a[100005], b[100005], n, *p, *q;
long long t, goal, s, num;
char ch[100005];
vector <long long> di, tr;

int main(){
    cin >> n >> goal;
    for (int i =0 ; i < n; i++){
        cin >> ch[i];
        a[i] = ch[i] - '0';
    }
    for (int i = 0; i <= 50; i++) di.push_back(pow(float(2), i));
    for (int i = 0; i < di.size(); i++)
    for (int i = di.size()-1; i >= 0; i--){
    	if (goal == 0) break;
        if (di[i] <= goal){
            goal -= di[i];
            tr.push_back(di[i]);
        }
    }
    for (int i = tr.size()-1; i >= 0; i--){
    	memcpy (&b, &a, sizeof (a));
    	num = tr[i];
    	for (int j = 0; j < n; j++){
    		t = (j + num) % n;
    		s = (j-num) % n;
    		if (s < 0) s += n;
    		a[j] = b[s] ^ b[t];
    	}
    }
    for (int i = 0; i < n; i++) printf ("%d", a[i]);
    return 0;
}
