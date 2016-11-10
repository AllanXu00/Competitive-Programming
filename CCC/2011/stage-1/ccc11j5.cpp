#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int a, ar[8], b;
	cin >> a;
	for (int i =0 ; i < 8; i++) ar[i]=1;
	for (int i = 1; i < a; i++){
	    cin >> b;
	    ar[b]=ar[b]*(1+ar[i]);
	}
	cout << ar[a] << endl;
	return 0;
}
