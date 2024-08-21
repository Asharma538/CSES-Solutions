// // First go through the link in description to know about implication graphs and 2-SAT problem 
// // then proceed with this video 

// steps we'll follow here:

// 1. Find the SCC(s) - strongly connected components

// 2. Check if a pair of i and -i are in same SCC, if they are then ans = IMPOSSIBLE

// 3. Otherwise we'll check which of a , -a is visited later in the transpose graph 
//     if -a is visited later we'll drop the topping
//     else we'll add the topping 

// boilerplate in comments :)

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
vector<vector<int>> v(200001);
// transpose graph for SCC 
vector<vector<int>> v_t(200001);
// lets use Visited array to also store the component ids 
vector<int> vis(200001,0);
// stack for toposort ordering 
stack<int> ordering;

void dfs(int i){
    vis[i] = 1;
    for(auto c : v[i]) if (!vis[c]) dfs(c);
    ordering.push(i);
}

void dfs_rev(int i,int comp){
    vis[i] = comp;
    for(auto c : v_t[i]) if (!vis[c]) dfs_rev(c,comp);
}

int main(){
    cin>>n>>m;
    repeat(i,0,n){
        char c1,c2; int a,b;
        cin>>c1>>a>>c2>>b;
        if (c1=='-') a = -a;
        if (c2=='-') b = -b;

        // to make all indices +ve lets add m 
        v[m-a].push_back(m+b);
        v[m-b].push_back(m+a);

        v_t[m+a].push_back(m-b);
        v_t[m+b].push_back(m-a);
    }

    repeat(i,1,2*m+1) if (!vis[i]) dfs(i);

    repeat(i,0,2*m+1) vis[i] = 0;


    int comp = 0;
    while(ordering.size()){
        if (!vis[ordering.top()]){
            dfs_rev(ordering.top(),++comp);
        }
        ordering.pop();
    }

    vector<char> ans(100001);

    repeat(i,1,m+1){
        if (vis[m-i]==vis[m+i]){
            // -i and i in same component 
            print("IMPOSSIBLE");
            return 0;
        }

        ans[i] = (vis[m-i]>vis[i+m])?'-':'+';
    }

    repeat(i,1,m+1) cout<<ans[i]<<' '; cout<<endl;
    
    return 0;
}