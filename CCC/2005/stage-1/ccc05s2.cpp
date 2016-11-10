#include <iostream>
using namespace std;
 
int main() {
	int x1, y1, x2=0, y2=0, x3, y3;
	cin >> x1 >> y1;
	while(true)
	{
		cin >> x3 >> y3;
		if (x3==0&&y3==0)
		{
			break;
		}
		x2+=x3;
		y2+=y3;
		if (x2>x1)
		{
			x2=x1;
		}
		else if (x2<0)
		{
			x2=0;
		}
		if (y2>y1)
		{
			y2=y1;
		}
		else if (y2<0)
		{
			y2=0;
		}
		cout << x2 << " " << y2 << endl;
	}
	return 0;
}
