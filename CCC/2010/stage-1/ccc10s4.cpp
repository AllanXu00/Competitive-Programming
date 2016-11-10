#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <map>
#pragma warning(disable:4996)

using std::vector;
using std::map;

const int MAXN = 1005;



struct fence {
	int cost;
	int first = 0;
	int second = 0;

	void add(int whereto) {
		if (first) {
			second = whereto;
		} else {
			first = whereto;
		}
	}

	bool operator<(const fence &f)const {
		return cost < f.cost;
	}

};


map < int, fence > farm; //ayy lmao maps are 3gud

vector<fence> interior;
vector<fence> exterior;

int redirect[MAXN];

int find(int x) {
	if (redirect[x] == x) {
		return x;
	}
	redirect[x] = find(redirect[x]); //path compression ftw
	return redirect[x];
}

int main() {

	int numPens;
	scanf("%i", &numPens);
	for (int a = 0; a < numPens; a++) {
		int links[8];
		int numSides;
		scanf("%i", &numSides);
		for (int b = 0; b < numSides; b++) {
			scanf("%i", &links[b]);
		}
		for (int b = 0; b < numSides; b++) {
			int weight;
			scanf("%i", &weight);
			
			int ma = links[b];
			int mb = links[(b + 1) % numSides]; //loops around if going out of bounds
			if (ma > mb) {
				std::swap(ma, mb);
			}
			farm[std::min(ma, mb) * MAXN + std::max(ma, mb)].add(a + 1);

			farm[std::min(ma, mb) * MAXN + std::max(ma, mb)].cost = weight; //worth the w8
		}
	}

	//input finished
	for (auto &any : farm) {
		fence &f = any.second;
		if (f.second) {
			interior.push_back(f); //interior ones are the ones that connect between 2 pens
		} else {
			f.second = 1002; //make an "outside" thing that will not conflict with the previous
			exterior.push_back(f); //exterior is the ones that point to outside
		}
	}
	std::sort(interior.begin(), interior.end());
	//std::sort(exterior.begin(), exterior.end()); no need right now

	int ans = 1000000000;
	for (int a = 0; a < MAXN; a++) {
		redirect[a] = a;
	}
	int interiorcost = 0;

	for (fence &f : interior) {
		int fa = find(f.first);
		int fb = find(f.second);
		if (fa != fb) {
			redirect[fa] = redirect[fb]; //simply merge
			interiorcost += f.cost;
		}//else no point merging
	}


	//now we try the exterior one
	int exteriorcost = 0;
	interior.insert(interior.end(), exterior.begin(), exterior.end());
	for (int a = 0; a < MAXN; a++) {
		redirect[a] = a;
	}
	std::sort(interior.begin(), interior.end()); //resort them

	for (fence &f : interior) {
		int fa = find(f.first);
		int fb = find(f.second);
		if (fa != fb) {
			redirect[fa] = redirect[fb]; //simply merge
			exteriorcost += f.cost;
		}//else no point merging
	}
	printf("%i", std::min(interiorcost, exteriorcost));


}
