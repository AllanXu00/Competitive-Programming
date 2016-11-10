#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, b, c, d; 
	cin >> a; 
	string temp;
	for (int i = 0; i < a; i++)
	{
		cin >> b >> c >> d; 
		getline (cin, temp);
		string ab[b], ac[c], ad[d];
		for (int n = 0; n < b; n++)
		{
			getline(cin, ab[n]);
			
		}
		for (int j = 0; j < c; j++)
		{
			getline(cin, ac[j]);
		}
		for (int k = 0; k < d; k++)
		{
			getline(cin, ad[k]);
		}
		for (int ii = 0; ii < b; ii++)
		{
		for (int ik = 0; ik < c; ik++)
		{
		for (int iij = 0; iij < d; iij++)
		{
		cout << ab[ii]<<' ' << ac[ik] <<' '<< ad[iij]<< '.' << endl;
		}
		}	
		}
		
		
	}
	return 0;
}
