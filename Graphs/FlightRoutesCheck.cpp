// // we need to check if we've the whole graph as 1 strongly connected component

// // you can use kosaraju's algorithm but it is an overkill

// we'll do bfs from 1 in the original graph to check if we can reach every node from 1 

// and a bfs from 1 in the reversed edges graph to check if every node can reach 1 

// boilerplate in comments 

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
    vector<vector<int>> v(n+1);
    vector<vector<int>> v_rev(n+1);
    repeat(i,0,m){
        int a,b; cin>>a>>b;
        v[a].push_back(b);
        v_rev[b].push_back(a);
    }

    queue<int> bfs;
    vector<bool> vis(n+1,false);
    bfs.push(1);
    vis[1] = true;
    while (bfs.size()){
        int x = bfs.front();
        for(auto i : v[x]){
            if (!vis[i]){
                vis[i]=true;
                bfs.push(i);
            }
        }
        bfs.pop();
    }
    repeat(i,1,n+1){
        if (!vis[i]){
            print(no);
            cout<<to_string(1)+" "+to_string(i);
            return 0;
        }
    }

    vis = vector<bool>(n+1,false);

    bfs.push(1);
    vis[1] = true;
    while (bfs.size()){
        int x = bfs.front();
        for(auto i : v_rev[x]){
            if (!vis[i]){
                vis[i]=true;
                bfs.push(i);
            }
        }
        bfs.pop();
    }
    repeat(i,1,n+1){
        if (!vis[i]){
            print(no);
            cout<<to_string(i)+" "+to_string(1);
            return 0;
        }
    }
    print(yes);
    
    
    return 0;
}