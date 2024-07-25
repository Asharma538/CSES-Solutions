// we'll traverse the building and when we get a . we'll cover all connected . and make them #
// increasing ans along the way whenever we'll find an unvisited .

// I'll add my boiler plate in desc

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

int n,m;
char ** arr;

// dfs function for traversing all connected dots
void dfs(int x,int y){
    if (x<0 or y<0 or x>n-1 or y>m-1) return; // outta bounds
    if (arr[x][y]=='#') return; // we've visited this
    arr[x][y] = '#';
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y-1);
    dfs(x,y+1);
}

int main(){
    cin>>n>>m;
    arr = new char*[n];
    repeat(i,0,n) arr[i] = new char [m];
    repeat(i,0,n) repeat(j,0,m) cin>>arr[i][j];

    int ans = 0;
    repeat(i,0,n) repeat(j,0,m){
        if (arr[i][j]=='.') ans++,dfs(i,j);
    }
    print(ans);
    return 0;
}