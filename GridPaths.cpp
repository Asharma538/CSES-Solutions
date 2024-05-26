#include <iostream>
using namespace std;

#define ll long long
#define elif else if

string path;
ll ans;

// let's define the grid, with a boundary of 1s around a 7x7 square, so that we can easily spot the ends
// true -> can't go, false -> can go
bool grid[9][9];

// i,j is the cell and idx is the index of the path
void phod(int i,int j,int idx){

    if (i==7 and j==1){ // reached the final location
        if (idx==48) // if all cells covered
            ans++;
        return; // because if not covered and then too we're here on final cell early, so wrong choice of directions
    }

    // if we're on a dead end, means we can't go down and up, but we can go left and right, then we can't cover the whole grid, thus a dead vertical end
    if (grid[i-1][j] and grid[i+1][j] and !grid[i][j-1] and !grid[i][j+1]) return;
    // if we're on a dead end, means we can't go left and right, but we can go up and down, then we can't cover the whole grid, thus a dead horizontal end
    if (!grid[i-1][j] and !grid[i+1][j] and grid[i][j-1] and grid[i][j+1]) return;

    grid[i][j] = true; // we're here

    // going all 4 directions
    if (path[idx]=='?'){
        
        if (!grid[i  ][j+1]) phod(i    ,j+1    ,idx+1); // right
        if (!grid[i  ][j-1]) phod(i    ,j-1    ,idx+1); // left
        if (!grid[i+1][j  ]) phod(i+1  ,j      ,idx+1); // down
        if (!grid[i-1][j  ]) phod(i-1  ,j      ,idx+1); // up

    }
    // going to the desired cell if not visited already, but if visited -> wrong choice of directions
    elif (path[idx]=='D' and !grid[i+1][j]) phod(i+1,j,idx+1);
    elif (path[idx]=='U' and !grid[i-1][j]) phod(i-1,j,idx+1);
    elif (path[idx]=='R' and !grid[i][j+1]) phod(i,j+1,idx+1);
    elif (path[idx]=='L' and !grid[i][j-1]) phod(i,j-1,idx+1);

    grid[i][j] = false; // we're done with this possibility
    
    return;
}

int main(){
    for(int i=0;i<9;i++) grid[i][0]=true;
    for(int i=0;i<9;i++) grid[0][i]=true;
    for(int i=0;i<9;i++) grid[i][8]=true;
    for(int i=0;i<9;i++) grid[8][i]=true;


    cin>>path;

    // idx = 0, i,j=1,1 (starting location)
    phod(1,1,0);
    cout<<ans<<'\n';
}