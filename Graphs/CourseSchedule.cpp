// this is an implementation problem of TOPOLOGICAL SORT 
// we use a in_degree array to maintain the in_degree(s) of nodes and when they're 0 we add them to a queue 
// then they are removed from the graph thus decrementing the indegrees of the other nodes they were influencing

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
    int n,m,a,b; cin>>n>>m;
    vector<vector<int>> v(n);
    vector<int> in_degree(n,0);

    repeat(i,0,m){
        cin>>a>>b;
        --a,--b;
        v[a].push_back(b);
        in_degree[b]++;
    }

    queue<int> toposort;
    repeat(i,0,n) if (in_degree[i]==0) toposort.push(i);

    vector<int> order;
    while (toposort.size()){
        int x = toposort.front();
        order.push_back(x+1);
        toposort.pop();
        for(auto i : v[x]){
            --in_degree[i];
            if (in_degree[i]==0) toposort.push(i);
        }
    }

    // if we can get all nodes that means that an order was possible, otherwise with a cycle there will be some nodes left as their in_degree can't be 0
    if (order.size()==n){
        print_it(order);
    }
    else{
        print("IMPOSSIBLE");
    }
    
    
    return 0;
}