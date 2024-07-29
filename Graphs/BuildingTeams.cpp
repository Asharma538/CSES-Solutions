// // I'll go with a simple approach of checking the colours 

// // but still you can do it with detecting odd cycles as well
// // coz we can tolerate even cycles but we can't tolerate odd cycles like 3,5

// we'll assign a colour to each node 
// starting from 0 and we'll assign the colour alternatively 

// but then when we've visited a node we'll verify that all its friends have different colours

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

vector<vector<int>> v(100001);
int vis[100001]; // for colours


void dfs(int i,int color){
    vis[i]=color;
    for(auto j: v[i]) if (vis[j]==-1) dfs(j,color^1);
}

bool verify(int i,int color){
    // two friends can't have same colour
    for(auto j: v[i]) if (vis[j]==color) return false;
    return true;
}


int main(){
    int n,m,a,b; cin>>n>>m;

    // init of vis
    repeat(i,0,n+1) vis[i]=-1;

    repeat(i,0,m){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    repeat(i,1,n+1){
        // repeat(i,1,n+1) cout<<vis[i]+1<<' '; cout<<endl;
        if (vis[i]==-1){
            dfs(i,0);
        }
        else{
            bool no_cycle = verify(i,vis[i]);
            if (!no_cycle){
                print("IMPOSSIBLE"); return false;
            }
        }
    }

    repeat(i,1,n+1) cout<<vis[i]+1<<' ';
    


    return 0;
}