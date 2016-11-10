#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int a, n; //number of planets and planet i start on
    int x, y,  i; //loop variables
    int z=0; // number of fuel cell at any given time
    cin >> a >> n;
    pair <int, int> e [100000];
    for (x = 0; x < a; x++)
    //z = 0;
    //i = 0;
    {
        cin >> e [x].second >> e [x]. first;  
    }
    e [n-1]. first = 0;
    //e [n]. second = 0;
//    cout << a << ": "<< n<< endl;
    //for (i = 0 ; i < a; i++)
    sort (e, e + a ); 
    
    //if (n + 2 <= a)
   // {
  //      sort (e + (n +1) , e + a);
  //  }
    
    
 
    for (y = 0; y < a; y++)
    {
//        cout << e [y]. second << "---" << e [y]. first<< endl;
        if (z >= e [y]. first && e [y]. second - e [y]. first >= 0)
        {
            z = z + (e [y]. second - e [y]. first);
            i = i + 1;
//            cout << e [y]. first;
        }
        
//        else if (e [y].second < e [y].first)
//    {
//        break;
//    }
    
    }
    cout << z << endl;
    cout << i << endl;
    return 0;
}
