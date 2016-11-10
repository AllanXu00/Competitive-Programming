#include <iostream>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

int n, p, x, y, z;
map <int, int> f;
set <int> bst;
set <int> :: iterator pos;

int main() {
	scanf ("%d", &n);
	scanf ("%d", &x);
	bst.insert(-x);
	f[x] = 0;
	for (int i = 1; i < n; i++){
		scanf("%d", &x);
		pos = bst.lower_bound(-x);
		if (pos == bst.lower_bound(1)){
            cout << "NO" << endl;
            return 0;
		}
		bst.insert(-x);
		p = *pos;
		f[p]++;
		if (f[p] == 2){
            bst.erase(p);
		}
	}
	cout << "YES" << endl;
	return 0;
}
