#include <iostream>

using namespace std;

int main()
{
   int a, b, c, x, y;
   cin >> a >> b >> c;
   
   if (a > 100)
   {
       x = (a - 100)*25 + b * 15 + c * 20; 
   }
   else if (a <= 100)
   {
       x = b * 15 + c * 20; 
   }
   //float x1 = (float) x/100;
   //cout << "Plan A costs " << x1   << endl;
   cout << "Plan A costs " << x  << " cents" << endl;
   
   if (a > 250)
   {
       y = (a - 250) * 45 + b * 35 + c * 25;
   }
   else if (a <= 250)
   {
       y = b * 35 + c * 25; 
   }
   // float y1 = (float) y/100;
   // cout << "Plan B costs " << y  << endl;
   cout << "Plan B costs " << y << " cents" << endl;
   
   if (y < x)
   {
        cout << "Plan B is cheapest." << endl;
   }
   
    if (y > x)
   {
        cout << "Plan A is cheapest." << endl;
   }
   
   if (y == x)
   {
        cout << "Plan A and B are the same price." << endl;
   }
   
   return 0;
}
