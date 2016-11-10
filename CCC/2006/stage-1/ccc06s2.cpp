#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main() {
	string a, b, c, d; 
	int e;
	char alpha[27];
	memset (alpha, '.', sizeof alpha);
	getline (cin, a);
	getline (cin, b);
	getline (cin, c);
	for (int i = 0; i < a.size(); i++)
	{
		if(b[i]==' ')
		{
			alpha[0]=a[i];
		}
		else
		{
			e=int(b[i])-64;
			alpha[e]=a[i];
		}
	}

	for(int i = 0; i < c.size();i++)
	{
		e = int(c[i])-64;
		if(e<0)
		{
			cout << alpha[0];
		}
		else
		{
			cout << alpha[e];
		}
	}
	
	return 0;
}
