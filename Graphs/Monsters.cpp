// we need to escape the labyrinth
// for that we need to know which cell we need to go next 
// and for that we need to know when on each cell the nearest monster will reach

// if we assume that there's only 1 monster then the problem is a simple BFS one for monster then for us 
// we'll check the squares that'll can be visited by us earlier than the monster to escape

// but to consider 2 monsters
// we need to know when both of them will reach those cells that we're thinking to step on 

// so 2 bfs? yes 

// so n bfs for n monsters ? yes 

// but there's a catch and that is we just need 1 bfs and we can account for all the monsters too
// let's code it

// boilerplate is in comments

#include <bits/stdc++.h>
using namespace std;


//Getting faster
#define repeat(i,s,e) for(long long i=s;i<e;i++)
#define reveat(i,s,e) for(long long i=s;i>e;i--)
#define elif else if
#define print(s) cout<<(s)<<endl
#define ll long long
#define append push_back
#define print_it(s) for(auto i : s) cout<<i<<" ";cout<<endl;


//Debugging functions
void print_2darr(auto n,auto m,auto **arr){ repeat(i,0,n){repeat(j,0,m) cout<<arr[i][j]<<' ';cout<<endl;}}
void print_1darr(auto n,auto arr[]){ repeat(i,0,n) cout<<arr[i]<<' ';cout<<endl;}


//Variables
string yes = "YES";
string no = "NO";


int main(){
    int n,m; cin>>n>>m;
    char ** labyrinth = new char * [n]; repeat(i,0,n) labyrinth[i] = new char [m];

    // tracking the time taken by monsters to reach a cell, considering they can change a cell in 1 unit
    int ** dis = new int * [n]; repeat(i,0,n) dis[i] = new int [m];

    repeat(i,0,n) repeat(j,0,m) dis[i][j] = 1e9; // nXm can be max 10***6

    // tracking visited cells
    bool ** vis = new bool * [n]; repeat(i,0,n) vis[i] = new bool [m];
    repeat(i,0,n) repeat(j,0,m) vis[i][j] = 0;

    pair<int,int> st;
    set<pair<int,int>> monsters;

    repeat(i,0,n) repeat(j,0,m){
        cin>>labyrinth[i][j];
        if (labyrinth[i][j]=='A') st = {i,j};
        elif (labyrinth[i][j]=='M') monsters.insert({i,j});
    }

    // pair < pair < x , y > , distance > for BFS 
    queue<pair<pair<int,int>,int>> bfs;

    for(auto i : monsters) bfs.push({i,0}); // think about it.... if we do individual bfs as well it too will yield the same result

    while(bfs.size()){
        int x = bfs.front().first.first;
        int y = bfs.front().first.second;
        int d = bfs.front().second;
        bfs.pop();

        if (d>=dis[x][y]) continue; // some monster is reaching here earlier -> same thing for all monsters

        dis[x][y] = d;

        if (x>0 and labyrinth[x-1][y]!='#' and !vis[x-1][y]){
            vis[x-1][y] = 1;
            bfs.push({{x-1,y},d+1}); // increasing the time d-> d+1
        }
        if (x<n-1 and labyrinth[x+1][y]!='#' and !vis[x+1][y]){
            vis[x+1][y] = 1;
            bfs.push({{x+1,y},d+1});
        }
        if (y>0 and labyrinth[x][y-1]!='#' and !vis[x][y-1]){
            vis[x][y-1] = 1;
            bfs.push({{x,y-1},d+1});
        }
        if (y<m-1 and labyrinth[x][y+1]!='#' and !vis[x][y+1]){
            vis[x][y+1] = 1;
            bfs.push({{x,y+1},d+1});
        }

    }

    // print_2darr(n,m,dis);

    // let's check the distances 
    // print_2darr(n,m,dis);

    // BFS for us
    bfs.push({st,0});

    repeat(i,0,n) repeat(j,0,m) vis[i][j] = 0;

    while(bfs.size()){
        int tm = 1e8; while(tm--);
        int x = bfs.front().first.first;
        int y = bfs.front().first.second;
        int d = bfs.front().second;
        bfs.pop();

        // we can't be with a monster on a cell
        if (d>=dis[x][y]) continue; // since the monster will reach here so we can't continue

        if (x==0 or y==0 or x==n-1 or y==m-1){
            dis[x][y] = -d;
            // we've escaped
            stack<char> path;
            while(dis[x][y] != 0){
                if (x>0 and dis[x][y]==dis[x-1][y]-1){ // we came from x-1 -> x 
                    path.push('D');
                    x--;
                }
                if (x<n-1 and dis[x][y]==dis[x+1][y]-1){ // we came from x+1 -> x
                    path.push('U');
                    x++;
                }
                if (y>0 and dis[x][y]==dis[x][y-1]-1){ // we came from y-1 -> y
                    path.push('R');
                    y--;
                }
                if (y<m-1 and dis[x][y]==dis[x][y+1]-1){ // obv
                    path.push('L');
                    y++;
                }
            }
            print(yes);
            print(path.size());
            while(path.size()){
                cout<<path.top(); path.pop();
            }
            return 0;
        }

        // since we're making an escape path and we need to track it down
        // let's make the dis[x][y] = -d so that we can track our steps back this negative distance path
        dis[x][y] = -d;

        if (x>0 and labyrinth[x-1][y]!='#' and !vis[x-1][y]){
            vis[x-1][y] = 1;
            bfs.push({{x-1,y},d+1}); // increasing the time d-> d+1
        }
        if (x<n-1 and labyrinth[x+1][y]!='#' and !vis[x+1][y]){
            vis[x+1][y] = 1;
            bfs.push({{x+1,y},d+1});
        }
        if (y>0 and labyrinth[x][y-1]!='#' and !vis[x][y-1]){
            vis[x][y-1] = 1;
            bfs.push({{x,y-1},d+1});
        }
        if (y<m-1 and labyrinth[x][y+1]!='#' and !vis[x][y+1]){
            vis[x][y+1] = 1;
            bfs.push({{x,y+1},d+1});
        }
    }


    print(no);

    return 0;
}