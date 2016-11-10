#include <iostream>

using namespace std;

int main()
{
   int a, n1, n2, t1, t2;
   cin >> a; 
   n1 = 100;
   n2 = 100;
   for (int i = 0; i < a; i++)
   {
       cin >> t1 >> t2;
       if (t1 > t2)
       {
           n2 = n2 - t1;
       }
       else if (t1 < t2)
       {
           n1 = n1 - t2;
       }
   }
   cout << n1 << endl << n2 << endl;
   
   
   return 0;
}
