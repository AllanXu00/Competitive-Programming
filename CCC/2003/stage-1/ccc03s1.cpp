#include <iostream>

using namespace std;

int main()
{
    int b, c; 
    b = 0;
    c = 1;
    int a [1000];
    while (true)
    {
    cin >> a [b];
    if (a [b] == 0)
    {
        cout << "You Quit!" << endl;
        return 0;
    }
    else if (a [b] < 2 || a [b] > 12)
    {
        return 1; 
    }
    
    c = c + a [b];
    
    if (c == 9)
    {
        c = 34;
    }
    
    else if (c == 40)
    {
        c = 64;
    }
    
    else if (c == 67)
    {
        c = 86; 
    }
    
     else if (c == 99)
    {
        c = 77; 
    }
    
     else if (c == 54)
    {
        c = 19; 
    }
    
     else if (c == 90)
    {
        c = 48; 
    }
    
    else if (c > 100)
    {
        c = c - a [b];
    }
    
    else if (c == 100)
    {
    cout << "You are now on square " << c << endl;
    cout << "You Win!" << endl;
    return 0;
    }
    cout << "You are now on square " << c << endl; 
    
    b = b + 1;
    }
   return 0;
}
