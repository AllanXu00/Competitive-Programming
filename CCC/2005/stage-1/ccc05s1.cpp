#include <iostream>
#include <string>
using namespace std;
int alpha (char s)
{
	if (s=='A'||s=='B'||s=='C')
		{
			return 2;
		}
		else if (s=='D'||s=='E'||s=='F')
		{
			return 3;
		}
		else if (s=='H'||s=='I'||s=='G')
		{
			return 4;
		}
		else if (s=='J'||s=='K'||s=='L')
		{
			return 5;
		}
		else if (s=='M'||s=='N'||s=='O')
		{
			return 6;
		}
		else if (s=='P'||s=='Q'||s=='R'||s=='S')
		{
			return 7;
		}
		else if (s=='T'||s=='U'||s=='V')
		{
			return 8;
		}
		else if (s=='W'||s=='X'||s=='Y'||s=='Z')
		{
			return 9;
		}
		
}
int main() {
	int a, ans, inc; 
	cin >> a; 
	string flush;
	char num[10];
	bool th, si;
	char b;
	for (int i = 0; i < a; i++)
	{
		inc = 0;
		th = false;
		si = false;
		while (inc < 10)
		{
			cin >> b; 
			if (inc==3&&th==false)
			{
				cout << '-';
				th=true;
			}
			if (inc==6&&si==false)
			{
				cout << '-';
				si=true;
			}
			
			if (b!='-')
			{
				if (int(b)>64)
				{
					ans = alpha(b);
					cout << ans;
				}
				else
				{
					cout << b;
				}
				inc++;
			}
		}
		cout << endl;
		getline (cin, flush);
	}
	return 0;
}
