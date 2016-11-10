#include <iostream>
using namespace std;

int main() {
	int n1,n2, b1, b2, time;
	cin >> n1 >> n2 >> b1 >> b2 >> time;
	bool bc, nc;
	bc = false; 
	nc = false;
	int bch = 0; 
	int nch = 0;
	int nd = 0;
	int bd = 0;
	for (int i = 1; i < time; i++)
	{
		if (nc == false)
		{
			nd++;
			nch++;
		}
		if (nch==n1&&nc==false)
		{
			nch = 0; 
			nc = true;
		}
		if (nc == true)
		{
			nd--;
			nch++;
		}
		if (nc==true&&nch==n2)
		{
			nch=0; 
			nc = false;
		}
		if (bc == false)
		{
			bd++;
			bch++;
		}
		if (bch==b1&&bc==false)
		{
			bch = 0; 
			bc = true;
		}
		if (bc == true)
		{
			bd--;
			bch++;
		}
		if (bc==true&&bch==b2)
		{
			bch=0; 
			bc = false;
		}
	}
	if (nd > bd)
	{
		cout << "Nikky";
	}
	else if (nd==bd)
	{
		cout << "Tied";
	}
	else
	{
		cout << "Byron";
	}
	return 0;
}
