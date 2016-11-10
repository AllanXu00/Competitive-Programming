#include <iostream>

using namespace std;

int main()
{
   int a, b, c, d, e;
   cin >> a; 
   char x [a];
   char y [a];
   e = 0;
   
   for (b = 0; b < a; b++)
   {
       cin >> x [b];
   }
   for (c = 0; c < a; c++)
   {
       cin >> y [c];
   }
   
   for (d = 0; d < a; d++)
   {
       if (x [d] == y [d])
       {
           e = e + 1;
       }
   }
   cout << e << endl;
   
    return 0;
}
