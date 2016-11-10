#include <iostream>
using namespace std;

int ar[4][4], sum, ans;
bool magic = true;

int main() {
	for (int i = 0; i < 4; i++){
		sum = 0;
		for (int j = 0; j < 4; j++){ scanf("%d", &ar[i][j]); sum+= ar[i][j];}
		if (i > 0 && sum != ans) magic = false;
		if (i == 0) ans = sum;
	}
	for (int i = 0; i < 4; i++){
		sum = 0;
		for (int j = 0; j < 4; j++){
			sum += ar[j][i];
		}
		if (sum != ans) magic = false;
	}
	if (magic) cout << "magic";
	else cout << "not magic";
	
	return 0;
}
