#include <iostream>
using namespace std;
int main() {
	double a = 0.00;
	double b; 
	double n;
	double b1 = 100.00;
	double b2 = 500.00;
	double b3 = 1000.00;
	double b4 = 5000.00;
	double b5 = 10000.00;
	double b6 = 25000.00;
	double b7 = 50000.00;
	double b8 = 100000.00;
	double b9 = 500000.00;
	double b10 = 1000000.00;
	double av;
	double d;
	double z = 0.00;

	cin >> n;
	do {
		cin >> b;
		
		if (b == 1) { b1 = 0; 
		z++; }
		else if (b == 2) { b2 = 0; 
		z++; }
		else if (b == 3) { b3 = 0; 
		z++; }
		else if (b == 4) { b4 = 0; 
		z++; }
		else if (b == 5) { b5 = 0; 
		z++; }
		else if (b == 6) { b6 = 0; 
		z++; }
		else if (b == 7) { b7 = 0; 
		z++; }
		else if (b == 8) { b8 = 0; 
		z++; }
		else if (b == 9) { b9 = 0;
		z++; }
		else if (b == 10) { b10 = 0; 
		z++; }

		a++;
		b = 0;
	} while (a < n);

	cin >> d;

	av = (b1 + b2 + b3 + b4 + b5 + b6 + b7 + b8 + b9 + b10) / (10 - z);

	if (d > av) {
		cout << "deal" << endl;
	}

	else cout << "no deal" << endl;



	return 0;
}
