#include <iostream>
#include <string>
using namespace std;

void dfs (int len, int on, string abc)
{
	if (on==0&&len==0)
	{
		cout << abc << endl;
		return;
	}
	if (len<=0)
	{
		//cout << endl;
		return;
	}
	string abd = abc;
	if (on>=1)
	{
	abc.append("1");
	dfs (len-1, on-1, abc);
	}
	abd.append("0");
	dfs (len-1, on, abd);
	
	
}

int main() {
	int a, n, k; 
	cin >> a; 
	for (int i = 0; i < a; i++)
	{
		cin >> n >> k; 
		cout << "The bit patterns are" << endl;
		dfs (n, k, "");
	}
	return 0;
}
