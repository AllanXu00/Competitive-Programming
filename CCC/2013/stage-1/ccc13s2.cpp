#include <iostream>

using namespace std;

int main()
{
   int limit, num, total, count; 
   cin >> limit >> num; 
   int cars [num]; 
   total = 0; 
   count = 0; 
   for (int i = 0; i < num; i++)
   {
       cin >> cars [i];
   }
   for (int i = 0; i < num; i++)
   {
       if (i > 3)
       {
           total = total - cars [i - 4];
       }
       total = total + cars [i];
       
       
       
       if (total > limit)
       {
           cout << count << endl;
           break;
       }
       count++;
       if (count == num && total < limit)
       {
           cout << num;
           break;
       }
       
       
   }
   
   
   return 0;
}
