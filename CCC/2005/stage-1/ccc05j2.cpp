#include <iostream>
using namespace std;

int main() {
	int a, b, t=0, ans=0; 
	cin >> a >> b; 
	for (int i = a; i <= b; i++)
	{
		t=0; 
		for(int j = 1; j <= i; j++)
		{
			if(i%j==0)
			{
				t++;
			}
		
		}
		if (t==4)
		{
			ans++;
		}
	}
	cout << "The number of RSA numbers between " << a <<" and " <<b <<" is " << ans;
	return 0;
}
