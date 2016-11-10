#include <iostream>
#include <algorithm>
using namespace std;

long long a, b, ans, bes;

int main() {
	cin >> a >> b;
	int ar[b], ar1[b];
	for (int i = 0; i< b; i++) cin >> ar[i];
	for (int i = 0; i< b; i++) cin >> ar1[i];
	sort (ar, ar+b);
	sort (ar1, ar1+b);
	for (int i = 0; i < b; i++){
        ans += max (ar[i], ar1[b-i-1]);
        bes += max (ar[i], ar1[i]);
        //cout << bes << endl;
	}
	if (a==1) cout << bes << endl;
	if (a==2) cout << ans << endl;
	return 0;
}
