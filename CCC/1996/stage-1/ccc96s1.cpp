#include <iostream>

using namespace std;

int main()
{
    int a, b, c, f;
    
    cin >> a; 
    int e [a], d [a];
    c = 1;
    b = 0;
    
    for (f = 0; f < a; f = f + 1)
    {
        d [f] = 0; 
    }
    
    for (b = 0; b < a; b = b + 1)
    {
        cin >> e [b]; 
        for (c = 1; c < e [b] ; c = c + 1)
        {
            if (e [b] % c == 0)
            {
             
                d [b]= d[b]  + c;
            }
        }

        if (d[b] > e[b] ) 
        {
            cout << e[b]<<" is an abundant number."<< endl;
        }
        else if (d[b] < e[b]) 
        {
            cout << e[b]<<" is a deficient number."<< endl;
        }
        else if ( d[b] == e [b])
        {
            cout << e[b] <<" is a perfect number."<< endl;
        }
        else 
        {
            return 1;
        }
    }
    
   return 0;
}
