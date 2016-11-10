#include <iostream>
#include <cmath>
#include <math.h>
using namespace std;

int main() {
	int a, b, count=0; 
	double temp;
	cin >> a >> b; 
	for(int i = 1; i < 1000; i++)
	{
		temp = double (i*i*i);
		if (temp >= a &&temp <= b)
		{
			if (sqrt(temp)==int(sqrt(temp)))
			{
				count++;
			}
		}
	}
	cout << count << endl;
	return 0;
}
