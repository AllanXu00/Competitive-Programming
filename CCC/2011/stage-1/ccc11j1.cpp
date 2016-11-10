#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, t, s; 
	cin >> a;
	string b [a];
	t = 0; 
	s = 0;
	for (int i = 0; i < a; i++)
	{
		getline(cin, b[i]); 
		for (int j =0;j< b[i].size();j++)
		{
			if (tolower(b[i].at(j))=='t')
			{
				t++;
			}
			if (tolower(b[i].at(j))=='s')
			{
				s++;
			}
		}
	}
	
	if (t<s-1||t==s-1)
	{
		cout << "French";
	}
	else
	{
		cout << "English";
	}
	
	
	return 0;
}
