#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool p (string str){
	for (int i = 0; i < str.length(); i++){
		if (str[i] != str[str.length()-i-1]) return false;
	}
	return true;
}

string a, a1, b1, b2, c1, c2;
int ans, t;

int main() {
	cin >> a;
	t = a.length();
	for (int i = 0; i < t; i++){
		for (int j = 0; j + i < t; j++){
			b1 = a; 
			b1.erase(b1.begin(), b1.begin()+i); 
			b1.erase(b1.end()-j, b1.end());
			if (p(b1)) ans = max (ans, t-i-j);
		}
	}
	cout << ans << endl;
	return 0;
}
