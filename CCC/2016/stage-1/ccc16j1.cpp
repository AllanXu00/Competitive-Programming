#include <iostream>
#include <string>
using namespace std;

int ans; char x;

int main() {
	for (int i = 0; i < 6; i++){
		cin >> x; 
		if (x == 'W') ans++;
	}
	if (ans > 4) cout << 1 << endl;
	else if (ans > 2) cout << 2 << endl;
	else if (ans > 0) cout << 3 << endl;
	else cout << -1 << endl;
	return 0;
}
