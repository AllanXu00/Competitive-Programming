#include <iostream>
#include <queue>
using namespace std;
 
struct point{
    int x, y, dist;
};
 
int main(){
    int cx,cy,cdist,ex, ey;
    int moves[10][10];
    bool seen[10][10];
    queue <point> q;
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++){
            moves[i][j] = 121;
            seen[i][j] = false;
        }
    cin >> cx >> cy >> ex >> ey;
    q.push((point){cx,cy,0});
    while(!q.empty()){
        cx = q.front().x;
        cy = q.front().y;
        cdist = q.front().dist;
        q.pop();
        if(cx < 1 || cy < 1 || cx > 8 || cy > 8 || seen[cx][cy]) continue;
        if(cx == ex && cy == ey){
            cout << cdist;
            break;
        }
        seen[cx][cy] = 1;
        q.push((point){cx+2,cy+1,cdist+1});
        q.push((point){cx-2,cy+1,cdist+1});
        q.push((point){cx+2,cy-1,cdist+1});
        q.push((point){cx-2,cy-1,cdist+1});
        q.push((point){cx+1,cy+2,cdist+1});
        q.push((point){cx+1,cy-2,cdist+1});
        q.push((point){cx-1,cy+2,cdist+1});
        q.push((point){cx-1,cy-2,cdist+1});
    }
}
