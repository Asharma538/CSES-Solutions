// we need a simple bfs with a track of our path from A to B 

// to track our path we'll use a parent array which will for each i,j
// keep a track of its parent cell (the cell from which we arrived on it)

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
    // input
    ll n,m; cin>>n>>m;
    char **arr = new char * [n]; repeat(i,0,n) arr[i] = new char [m];
    char **par = new char * [n]; repeat(i,0,n) par[i] = new char [m];

    // taking the labyrinth 
    pair<int,int> st; // start of BFS
    repeat(i,0,n) repeat(j,0,m){
        cin>>arr[i][j];
        if (arr[i][j]=='A') st = {i,j};
        par[i][j] = 'X'; // NO PARENT INITIALLY
    }

    // queue is for bfs and stack is for dfs
    queue<pair<int,int>> bfs_stack;
    bfs_stack.push(st);

    int x,y;
    // BFS
    while(!bfs_stack.empty()){
        // print("==================");
        x = bfs_stack.front().first;
        y = bfs_stack.front().second;
        bfs_stack.pop();

        // cout<<x<<' '<<y<<'\n';
        // print_2darr(n,m,arr);

        // END OF BFS
        if (arr[x][y]=='B') break;
        arr[x][y] = '#';

        // Going all directions
        // constriant     no wall             unvisited
        if (x-1>=0 and arr[x-1][y]!='#' and par[x-1][y]=='X'){
            bfs_stack.push({x-1,y});
            par[x-1][y] = 'U';
        }
        if (y-1>=0 and arr[x][y-1]!='#' and par[x][y-1]=='X'){
            bfs_stack.push({x,y-1});
            par[x][y-1] = 'L';
        }
        if (x+1<n and arr[x+1][y]!='#' and par[x+1][y]=='X'){
            bfs_stack.push({x+1,y});
            par[x+1][y] = 'D';
        }
        if (y+1<m and arr[x][y+1]!='#' and par[x][y+1]=='X'){
            bfs_stack.push({x,y+1});
            par[x][y+1] = 'R';
        }
    }

    // print_2darr(n,m,par);

    // there is a path
    if (arr[x][y]=='B'){
        print(yes);
        stack<char> path;
        // while we're on a path
        // using the par array to move back
        while( par[x][y]!='X'){
            path.push(par[x][y]);
            // do opposite to move back to the beginning
            if (par[x][y]=='U') x++;
            elif (par[x][y]=='D') x--;
            elif (par[x][y]=='R') y--;
            elif (par[x][y]=='L') y++;
            // a gen debugging tip
            // slow it down
            // int a=1e8; while(a--);
        }
        print(path.size());
        while(path.size()){
            cout<<path.top();path.pop();
        }
    }
    else{
        print(no);
    }

    return 0;
}