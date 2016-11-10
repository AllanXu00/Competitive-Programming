#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int n, x, hi, lo, mid, ans; 
vector <int> per;
bool visit[101]; 

bool valid (int ppl){
	double p = 100/double(ppl); bool check;
	for (int i = 0; i < per.size(); i++){
		check = false; 
		for (int j = 1; j <= 100; j++){
			if (int(p*j+0.5) == per[i]) check = true;
		}
		if (!check) return false;
	}
}

int main() {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &x);
		if (!visit[x]){
			visit[x] = true;
			per.push_back(x);
		}
	}
	for (int i = 1; i <= 100; i++){
		if (valid(i)){
			printf ("%d\n", i);
			return 0;
		}
	}
	cout << 1 << endl;
	return 0;
}
