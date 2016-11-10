#include <iostream>
using namespace std;

int goal, best, l;

int main() {
	while (true){
		cin >> goal; 
		if (goal == 0)break;
		best = 1<<30; l = 1<<30;
		for (int i = 1; i <goal; i++){
			if (i*2 + goal/i*2 < best && goal%i==0){
				best = i*2 + goal/i*2;
				l = i;
			}
		}
		cout << "Minimum perimeter is " << best << " with dimensions " << l << " x " << goal/l << endl;
	}
	return 0;
}
