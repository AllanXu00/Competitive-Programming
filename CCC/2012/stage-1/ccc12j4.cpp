#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main() {
	int a, t, t1, tf;
	string b;
	char temp;
	cin >> a >> b;
	for(int i = 0; i < b.length(); i++)
	{
		temp = b[i];
		t1 = temp;
		t1 = t1 - a;
		if (t1 < 65)
		{
			t1 = t1 + 26;
		}
		t1 -= (3*(i+1));
		if (t1 < 65)
		{
			t1 = t1 + 26;
		}
		
		cout << char (t1);
	}
	
	return 0;
}
