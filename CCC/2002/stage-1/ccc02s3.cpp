#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int r, c;
char grid[375][80];
int final[375][80]={0};
int m;
char move[3000];


void print_grid()
{
   for (int i=0;i<c;i++)
   {
       for (int j=0;j<r;j++)
       {
          if (final[i][j] == 1)
          {
              cout << '*';
          }
          else cout << grid[i][j]  ;
       }
       cout << endl;
   }
}


void walk(int x, int y, char orientation1)
{
    for (int i=0; i < m; i++)
    {
        if ( move[i] == 'F' )
        {
            if        (  orientation1 == 'E' ) { y = y +1;         }
            else  if  (  orientation1 == 'S' ) { x = x +1;         }
            else  if  ( orientation1 == 'W' ) { y = y -1;         }
            else  if  ( orientation1 == 'N' ) { x = x -1;         }
        }
        if ( move[i] == 'L' )
        {
            if      ( orientation1 == 'E' ) { orientation1 = 'N'; }
            else if ( orientation1 == 'S' ) { orientation1 = 'E'; }
            else if ( orientation1 == 'W' ) { orientation1 = 'S'; }
            else if ( orientation1 == 'N' ) { orientation1 = 'W'; }
        }
        if ( move[i] == 'R' )
        {
            if      ( orientation1 == 'E' ) { orientation1 = 'S'; }
            else if ( orientation1 == 'S' ) { orientation1 = 'W'; }
            else if ( orientation1 == 'W' ) { orientation1 = 'N'; }
            else if ( orientation1 == 'N' ) { orientation1 = 'E'; }
        }
  if (grid[x][y] == 'X' || x < 0 || x > c-1 || y <0 || y > r-1) return;
    }
    final[x][y]=1;

}
int main()
{
   cin >> c >> r;
   for (int i=0;i<c;i++)
   {
       for (int j=0;j<r;j++)
       {
          cin>> grid[i][j]  ;
       }
   }
   cin >> m;


   for (int i = 0; i < m; i++)
   {
       cin >> move[i];
   }


   for (int i=0;i<c;i++)
   {
       for (int j=0;j<r;j++)
       {
          if (grid[i][j] != 'X')
          {
              walk(i,j, 'E');
              walk(i,j, 'S');
              walk(i,j, 'W');
              walk(i,j, 'N');
          }
       }
   }
   print_grid();
   return 0;
}
