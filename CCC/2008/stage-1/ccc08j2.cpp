#include <iostream>
using namespace std;
int main() {
	char p1, p2, p3, p4, p5, temp;
	int b, n;
	int x = 0;
	p1 = 'A';
	p2 = 'B';
	p3 = 'C';
	p4 = 'D';
	p5 = 'E';

	do {
		cin >> b >> n;
		if (b == 1) {
			do {
				temp = p1,
				p1 = p2,
				p2 = p3;
				p3 = p4;
				p4 = p5;
				p5 = temp;
				x++;
			} while (x < n);
		}
		else if (b == 2) { 
			do {
				temp = p5,
				p5 = p4;
				p4 = p3;
				p3 = p2;
				p2 = p1;
				p1 = temp;
				x++;
			} while (x < n); 
		}
		else if (b == 3) {
			do {
				temp = p1;
				p1 = p2;
				p2 = temp;
				x++;
			} while (x < n); 
		}
		x = 0;

	} while (b != 4);

	cout << p1 << " " << p2 << " " << p3 << " " << p4 << " " << p5 << endl;
	

	return 0;
}
