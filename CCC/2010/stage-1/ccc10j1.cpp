#include <iostream>

using namespace std;

int main()
{
   int a, count; 
   cin >> a; 
   count = 0;
   for (int i = 0; i <= a/2; i++)
   {
       if (a - i <= 5 && i <= 5)
       {
       count++;
       }
       
   }
   
   cout << count;
   
   return 0;
}
