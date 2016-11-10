#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a, b, c, num, cur, hi, lo, mid;
vector <int> house;

int qu (int dis){
	dis = dis*2;
	int best = 1005;
	for (int i = 0; i < house.size(); i++){
		if (house[i]>house[0]+dis) break;
		int count = 1;
		cur = house[0];
		for (int j = 1; j < house.size(); j++){
			if (house[j]-cur>dis){
				//if (dis=1000) cout << cur << endl;
				cur=house[j];
				count++;
			}
		}
		best = min(best, count);
	}
	return best;
}

int main() {
	cin >> a;
	for (int i = 0; i < a; i++){
		cin >> c;
		house.push_back(c);
	}
	sort (house.begin(), house.end());
	cin >> num;
	if (a==1){
		cout << 0 << endl;
		return 0;
	}
	hi = 1000000;
	lo = 0;
	while (hi>lo){
		mid = lo+(hi-lo)/2;
		if (qu(mid)<=num) hi = mid;
		else lo = mid+1;
	}
	cout << lo << endl;
	return 0;
}
