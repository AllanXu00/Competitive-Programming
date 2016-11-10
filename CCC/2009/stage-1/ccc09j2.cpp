#include <iostream>
using namespace std;
int main()
{
    int total, trout, pike, pickerel, count = 0;
    cin >> trout >> pike >> pickerel >> total;
    for(int i=0; i<= total/trout; i++)
        for(int j=0; j<= total/pike; j++)
            for(int k=0; k<= total/pickerel; k++)
                if ((i>0 || j>0 || k>0) && (i*trout + j*pike + k*pickerel <= total)){
                    count = count + 1;
                    cout << i << " Brown Trout, "
                        << j << " Northern Pike, "
                        << k << " Yellow Pickerel"
                        << endl;
                }
    cout << "Number of ways to catch fish: " << count << endl;
    return 0;
}
