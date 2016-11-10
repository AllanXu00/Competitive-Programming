#include <iostream>

using namespace std;

int main()
{
    int a, b; 
    cin >> a >> b;
    if (a < 0 || a > 50 || b < a || b > 50)
    {
        return 1;
    }
    cout << (b-a) + b;
   return 0;
}
