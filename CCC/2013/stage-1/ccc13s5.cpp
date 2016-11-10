#include <iostream>
using namespace std;

int main() {
	int n, fac, ans=0;
	cin >> n;
	while (n>1){
		fac=0;
		for (int i = 2; i < n; i++){
			if (n%i==0){
				fac = i; 
				break;
			}
		}
		if (fac!=0){
		ans+=n/(n/fac);
		ans--;
		n=n-(n/fac);
		}
		else{
			n--;
			ans+=n;
		}
		//cout << n  << " " << ans << endl;
	}
	cout << ans << endl;
	return 0;
}
