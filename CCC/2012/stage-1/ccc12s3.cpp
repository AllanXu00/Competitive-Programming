#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int a, t, bi, sm, lim1, lim2, ans; 
	cin >> a;
	pair <int, int> ar [1100];
	for (int i = 0; i < 1100; i++)
	{
		ar[i].second = i;
		ar[i].first = 0; 
	}
	for (int i = 0; i < a; i++)
	{
		cin >> t; 
		ar[t].first++;
	}
	sort (ar, ar+1100);
	bi = ar[1099].second;
	lim1 = ar[1099].first;
	lim2 = ar[1098].first;
	sm =  ar[1098].second;
	ans = abs(bi-sm);
	//cout << ans << endl;
	for (int i = 1099; i >= 0; i--)
	{
	    if (ar[i].first<lim1)
	    {
	    	cout << ans << endl; 
	    	return 0;
	    }
	    for (int j = 1098; j >= 0; j--)
	    {
		if (ar[j].first < lim2){
			break;	
		} 
		bi = ar[i].second;
		sm = ar[j].second;
		ans = max (ans, abs(bi-sm));
	    }
	}
	cout << ans << endl;
	return 0;
}
 
