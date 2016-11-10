#include <iostream>
using namespace std;

int main() {
	int x=0, y=0, a, b, e, t;
	char c, d; 

	while (true)
	{
		cin >> a;
		if (a==7)
		{
			break;
		}
		else if (a==1)
		{
			cin >> c;
			if (c=='A')
			{
				cin >> t;
				x=t;
			}
			if (c=='B')
			{
				cin >> t;
				y=t;
			}
			
		}
		else if (a==2)
		{
			cin >> c;
			if (c=='A')
			{
				cout << x << endl;
			}
			if (c=='B')
			{
				cout << y << endl;	
			}
		}
		else if (a==3)
		{
			cin >> c >> d;
			if (c=='A'&&d=='B')
			{
				x+=y;
			}
			if (c=='B'&&d=='A')
			{
				y+=x;
			}
			if (c=='A'&&d=='A')
			{
				x+=x;
			}
			if (c=='B'&&d=='B')
			{
				y+=y;
			}
		}
		else if (a==4)
		{
			cin >> c >> d;
			if (c=='A'&&d=='B')
			{
				x*=y;
			}
			if (c=='B'&&d=='A')
			{
				y*=x;
			}
			if (c=='A'&&d=='A')
			{
				x*=x;
			}
			if (c=='B'&&d=='B')
			{
				y*=y;
			}
		}
		else if (a==5)
		{
			cin >> c >> d;
			if (c=='A'&&d=='B')
			{
				x-=y;
			}
			if (c=='B'&&d=='A')
			{
				y-=x;
			}
			if (c=='A'&&d=='A')
			{
				x-=x;
			}
			if (c=='B'&&d=='B')
			{
				y-=y;
			}
		}
		else if (a==6)
		{
			cin >> c >> d;
			if (c=='A'&&d=='B')
			{
				x/=y;
			}
			if (c=='B'&&d=='A')
			{
				y/=x;
			}
			if (c=='A'&&d=='A')
			{
				x/=x;
			}
			if (c=='B'&&d=='B')
			{
				y/=y;
			}
		}
	//cout << a << endl;
	}
	return 0;
}
