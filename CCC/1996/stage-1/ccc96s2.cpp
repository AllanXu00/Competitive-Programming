#include <iostream>
#include <string>
using namespace std;

int main() {
	int a, c, d; 
	string b, b1;
	cin >> a;
	bool z = false;
	for (int i = 0; i < a; i++)
	{
		cin >> b; 
		b1 = b;
		d = b.length();
		z = false;
		for(int j = d-1; j >= 2; j--)
		{
			if(b[0]=='0')
			{
				b.erase(b.begin()+0);
				j--;
			}
			cout << b << endl;
			c = int(b[j]);
			c -=48;
			b.erase(b.begin()+j);
			b[j-1]-= c; 
			for (int n = b.length()-1; n >= 1; n--)
			{
				if (b[n]<48 )
				{
					b[n]+=10;
					b[n-1]-=1;
				}
				
			}
			
		}
				
	
			
				
		
		cout << b << endl;
		if (b=="11")
		{
			cout << "The number "<< b1 << " is divisible by 11." << endl;
		}
		else
		{
			cout << "The number " << b1 << " is not divisible by 11." << endl;
		}
	}
	return 0;
}
