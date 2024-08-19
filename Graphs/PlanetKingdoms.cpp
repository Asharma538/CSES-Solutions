// we need to implement kosaraju's algorithm here which consists of 2 parts

// 1. DFS to decide the ordering or traversal 
// Reverse the graph
// 2. DFS on the reversed graph with respect to the ordering we found in 1 to find the components 


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
vector<vector<int>> v_(100001);
// lets use vis a kingdoms array too 
int vis[100001];

// we need a stack for keeping our ordering 
stack<int> ordering;

void dfs(int i){
    vis[i] = 1;
    for(auto c : v[i]) if (!vis[c]){
        dfs(c);
        // adding it when all paths through c are taken 
        ordering.push(c);
    }
}

void dfs_rev(int i,int kingdom){
    vis[i] = kingdom;
    for(auto c : v_[i]) if (vis[c]==0) dfs_rev(c,kingdom);
}

int main(){

    int n,m,a,b; cin>>n>>m;
    repeat(i,0,m){
        cin>>a>>b;
        v[a].push_back(b);
        v_[b].push_back(a);
    }

    repeat(i,1,n+1){
        if (!vis[i]){
            dfs(i);
            ordering.push(i);
        }
    }

    repeat(i,0,n+1) vis[i+1] = 0;

    // traversal of reversed graph using ordering 
    int kingdoms = 0;
    while(ordering.size()){
        // if already a part of some kingdom 
        if (vis[ordering.top()]!=0){
            ordering.pop();
            continue;
        }
        kingdoms++;
        dfs_rev(ordering.top(),kingdoms);
        ordering.pop();
    }

    print(kingdoms);
    repeat(i,1,n+1) cout<<vis[i]<<' '; cout<<endl;
    
    return 0;
}