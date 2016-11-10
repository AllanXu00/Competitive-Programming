#include <iostream>
#include <string>
using namespace std;

int main() {
	int a,a1, c,c1, ans; 
	char b='g', b1; 
	bool d=false; 
	string e; 
	cin >> e; 
	
	
	for(int i = 0; i < e.size(); i=i+2)
	{
		a = int(e[i])-48;
		if (e[i+1]=='I')
		{
			c = 1;
		}
		if (e[i+1]=='V')
		{
			c = 5;
		}
		if (e[i+1]=='X')
		{
			c = 10;
		}
		if (e[i+1]=='L')
		{
			c = 50;
		}
		if (e[i+1]=='C')
		{
			c = 100;
		}
		if (e[i+1]=='D')
		{
			c = 500;
		}
		if (e[i+1]=='M')
		{
			c = 1000;
		}
		if (i==0)
		{
			ans = a*c;
		}
		else
		{
			ans+=a*c;
		}
		
		if (c>c1&&i>0)
		{
			ans-=a1*c1*2;
		}
		c1=c;
		a1=a;
	
	}
	
	

	cout << ans << endl;
	return 0;
}
