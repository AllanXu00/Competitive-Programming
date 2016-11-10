#include <iostream>

using namespace std;

int main()
{
   int a, b;
   cin >> a; 
   int x [a], y [a], z [a];
   for (b = 0; b < a; b++)
   {
       cin >> x [b] >> y [b] >> z [b];
       if (x [b] < 1989)
       {
       cout << "Yes" << endl;
       }
       
       else if (x [b] == 1989 && y [b] < 2)
       {
           cout << "Yes" << endl;
       }
       
       else if (x [b] == 1989 && y [b] == 2 && z [b] <= 27)
       {
       cout << "Yes" << endl;
       }
       
       else 
       {
           cout << "No" << endl;
       }
   }
   
   return 0;
}
