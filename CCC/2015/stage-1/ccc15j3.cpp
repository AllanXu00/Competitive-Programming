#include <iostream>
#include <string>
using namespace std;

int main() {
	string a; 
	cin >> a;
	char temp;
	for(int i = 0; i < a.length(); i++)
	{
		if (a[i]!= 'a'&& a[i]!= 'e'&&a[i]!= 'i'&&a[i]!= 'o'&&a[i]!= 'u')
		{
			//1
			cout << a[i];
			//2
			
			if (a[i]=='b'||a[i]=='c')
			{
				cout << 'a';
			}
			else if (a[i]=='d'||a[i]=='f'||a[i]=='g')
			{
				cout << 'e';
			}
			else if (a[i]=='h'||a[i]=='j'||a[i]=='k'||a[i]=='l')
			{
				cout << 'i';
			}
			else if (a[i]=='m'||a[i]=='n'||a[i]=='p'||a[i]=='q'||a[i]=='r')
			{
				cout << 'o';
			}
			else if (a[i]=='s'||a[i]=='t'||a[i]=='v'||a[i]=='w'||a[i]=='x'||a[i]=='y'||a[i]=='z')
			{
				cout << 'u';
			}
			//3
			if (a[i]!= 'z')
			{
			char temp = (a[i]+1);
				if (temp == 'a'||temp == 'e'||temp == 'i'||temp == 'o'||temp == 'u')
				{
					cout << char (temp + 1);
				}
				else
				{
					cout << temp;
				}
			}
			else
			{
				cout << 'z';
			}
		}
		else
		{
			cout << a[i];
		}
	}
	return 0;
}
