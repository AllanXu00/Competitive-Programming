#include <iostream>
using namespace std;

int main() {
	int c = 0, cs = 0, hs = 0;
	char a[255];
	while (true)
	{
		cin >> a [c];
		c++;
		if (c==255)
		{
			break;
		}
	}
	for(int i = 0; i < c-2; i++)
	{
		
		if (a[i]==':'&&a[i+1]=='-'&&a[i+2]==')')
		{
			hs++;
		}
		if (a[i]==':'&&a[i+1]=='-'&&a[i+2]=='(')
		{
			cs++;
		}
	}
	if (cs==0 && hs == 0)
	{
		cout << "none";
	}
	else if (cs==hs)
	{
		cout << "unsure";
	}
	else if (cs>hs)
	{
		cout << "sad";
	}
	else 
	{
		cout << "happy";
	}
	return 0;
}
