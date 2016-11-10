#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, d;
    cin >> a >> b;
    int c [b];
    d = 0;
    for (int i =0; i < b; i++)
    {
        cin >> c[i];
    }
    sort (c, c+b);
    for (int i = 0; i < b; i++)
    {
        if (a - c [i] >= 0)
        {
            a = a - c[i];
            d++;
        }
        else 
        {
            break;
        }
    }
   cout << d << endl;
   return 0;
}
