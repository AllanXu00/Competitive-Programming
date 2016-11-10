#include <iostream>
#include <string>
using namespace std;

int main() {
	string a; 
	while (true)
	{
		cin >> a;
		if(a=="quit!")
		{
			return 0;
		}
		for(int i = 0; i < a.length(); i++)
		{
			cout << a[i];
			if (a[i-1]!= 'a'&& a[i-1]!= 'e'&& a[i-1]!= 'o'&& a[i-1]!= 'u'&& a[i-1]!= 'i'&& a[i-1]!= 'y')
			{
			if(a[i]=='o' && a[i+1] == 'r'&&a.length()>4&&i==a.length()-2) 
			{
				cout << 'u';
			}
			}
		}
		cout << endl;
	}
	
	return 0;
}
