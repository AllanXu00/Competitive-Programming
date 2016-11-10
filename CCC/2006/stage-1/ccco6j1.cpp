#include <iostream>

using namespace std;

int main()
{
    int b, s, d, e, c;
    c = 0;
    
    cin >> b >> s >> d >> e ; 

    if (b == 1)
        c = c + 461;
    if (b == 2)
        c = c + 431;
    if (b == 3)
        c = c + 420;
    if (b == 4)
        c = c ; 

    if (s == 1) 
        c = c + 100;
    if (s == 2)
        c = c + 57;
    if (s == 3)
        c = c + 70;
    if (d == 4)
        c = c; 
    
    if (d == 1)
        c = c + 130;
    if (d == 2)
        c = c + 160;
    if (d == 3)
        c = c + 118;
    if (d == 4)
        c = c; 
    
    if (e == 1)
        c = c + 167;
    if (e == 2)
        c = c + 266;
    if (e == 3)
        c = c + 75;
    if (e == 4)
        c = c; 
    cout << "Your total Calorie count is " << c << ".\n"; 
   
   return 0;
}
