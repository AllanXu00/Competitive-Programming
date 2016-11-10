#include <iostream>

using namespace std;

int main()
{
   int tot, a, b, c,count;
   count = 0;
   cin >> tot >> a >> b >> c;
   while (true)
   {
       a++;
       tot--;
       count++;
       if (a%35==0)
       {
           tot += 30;
       }
       if (tot == 0)
       {
           break;
       }
       b++;
       tot--;
       count++;
       if (b%100==0)
       {
           tot +=60;
       }
       if (tot == 0)
       {
           break;
       }
       c++;
       tot--;
       count++;
       if (c%10==0)
       {
           tot += 9;
       }
       if (tot == 0)
       {
           break;
       }
       
   }
   cout << "Martha plays "<< count << " times before going broke.";
   
   return 0;
}
