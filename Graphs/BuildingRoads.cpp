// we'll do a simple dfs from all the unvisited nodes
// start from 1, as the first dfs to mark all the non connected nodes
// then repeat for all unvisited ones 

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

vector<vector<int>> graph(100001);
bool vis[100001];

void dfs(int a){
    vis[a]=true;
    for(auto i : graph[a]) if (!vis[i]) dfs(i);
}


int main(){
    int n,m; cin>>n>>m;
    int a,b; 
    repeat(i,0,m){
        cin>>a>>b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    vector<pair<int,int>>roads;

    repeat(i,1,n+1){
        if (!vis[i]){
            // road from 1 to the city in that component
            roads.push_back({1,i});
            dfs(i);
        }
    }

    print(roads.size());
    for(auto i : roads) cout<<i.first<<' '<<i.second<<endl;

    return 0;
}