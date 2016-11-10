#include <iostream>

using namespace std;

int main()
{
   int a, b, count; 
   cin >> a >> b; 
   count = 0; 
   for (int i = 1; i <= a; i++)
   {
       for (int n = 1; n <=b; n++)
       {
           if (i + n == 10)
           {
               count ++;
           }
       }
   }
   if (count == 1)
   {
       cout << "There is 1 way to get the sum 10.";
   }
   else 
   {
       cout << "There are " << count << " ways to get the sum 10.";
   }
   
   return 0;
}
