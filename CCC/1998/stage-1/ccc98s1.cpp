#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, c=0;
	cin >> a;
	string b;
	getline(cin, b);
	for(int i = 0; i < a; i++)
	{
		getline (cin, b);
		c=0;
		for(int j = 0; j < b.length(); j++)
		{
			if(b[j]==' '&&c==4)
			{
				b[j-1]='*';
				b[j-2]='*';
				b[j-3]='*';
				b[j-4]='*';
				c = 0;
			}
			else if (j == b.length()-1&&c==3)
			{
				b[j]='*';
				b[j-1]='*';
				b[j-2]='*';
				b[j-3]='*';
				
			}
			
			else if (b[j]==' ')
			{
				c=0;
			}
			else
			{
				c++;
			}
			
		}
		cout << b << endl << endl;
	}
	return 0;
}
