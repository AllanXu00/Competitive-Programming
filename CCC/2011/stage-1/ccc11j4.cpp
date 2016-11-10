#include <iostream>
using namespace std;

int main() {
	int x=-1, y=-5, temp;
	char a;
	bool check [401][401] = {false};
	check [200][199]=true;
	check [200][198]=true;
	check [200][197]=true;
	check [201][197]=true;
	check [202][197]=true;
	check [203][197]=true;
	check [203][196]=true;
	check [203][195]=true;
	check [204][195]=true;
	check [205][195]=true;
	check [205][196]=true;
	check [205][197]=true;
	check [206][197]=true;
	check [207][197]=true;
	check [207][196]=true;
	check [207][195]=true;
	check [207][194]=true;
	check [207][193]=true;
	check [206][193]=true;
	check [205][193]=true;
	check [204][193]=true;
	check [203][193]=true;
	check [202][193]=true;
	check [201][193]=true;
	check [200][193]=true;
	check [199][193]=true;
	check [199][194]=true;
	check [199][195]=true;
	bool safe = true;
	while (true)
	{
		cin >> a >> temp;
		if (a == 'q')
		{
			break;
		}
		if (a=='u')
		{
			for(int i = 1; i <= temp; i++)
			{
				if(check[x+200][y+i+200]==true)
				{
					safe = false;
				}
				else
				{
					check[x+200][y+i+200]=true;
				}
			}
			y +=temp;
			
		}
		else if (a=='d')
		{
		for(int i = 1; i <= temp; i++)
			{
			if(check[x+200][y-i+200]==true)
				{
					safe = false;
				}
				else
				{
					check[x+200][y-i+200]=true;
				}
			}
			y -= temp;
		}
		else if (a=='r')
		{
			for(int i = 1; i <= temp; i++)
			{
			if(check[x+i+200][y+200]==true)
				{
					safe = false;
				}
				else
				{
					check[x+i+200][y+200]=true;
				}
			}
			x+=temp;
		}
		else if (a=='l')
		{
			for(int i = 1; i <= temp; i++)
			{
			if(check[x-i+200][y+200]==true)
				{
					safe = false;
				}
				else
				{
					check[x-i+200][y+200]=true;
				}
			}
			x-=temp;
		}
		cout << x << " " << y << " ";
		if(safe==true)
		{
			cout << "safe"<<endl;
		}
		else if (safe == false)
		{
			cout << "DANGER" << endl;
			return 0;
		}
		
		
	}
	return 0;
}
