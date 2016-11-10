#include <iostream>
#include <string>
using namespace std;

int main() {
	string a;
	while(true){
		cin >> a; 
		if (a=="CU")
		{
			cout << "see you" << endl;
		}
		else if (a==":-)")
		{
			cout << "I'm happy" << endl;	
		}
		else if (a==":-(")
		{
			cout << "I'm unhappy" << endl;	
		}
		else if (a==";-)")
		{
			cout << "wink" << endl;	
		}
		else if (a==":-P")
		{
			cout << "stick out my tongue" << endl;	
		}
		else if (a=="(~.~)")
		{
			cout << "sleepy" << endl;	
		}
		else if (a=="TA")
		{
			cout << "totally awesome" << endl;	
		}
		else if (a=="CCC")
		{
			cout << "Canadian Computing Competition" << endl;	
		}
		else if (a=="CUZ")
		{
			cout << "because" << endl;	
		}
		else if (a=="TY")
		{
			cout << "thank-you" << endl;	
		}
		else if (a=="YW")
		{
			cout << "you're welcome" << endl;	
		}
		else if (a=="TTYL")
		{
			cout << "talk to you later" << endl;
			break;
		}
		else
		{
			cout << a << endl;
		}
		
		
	}
	return 0;
}
