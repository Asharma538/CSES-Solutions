// since there're no directed cycles there should not be a problem performing topo sort 

// we just need to check for alternate routes to n 

// for that we'll perform topo sort without considering 1 as a node in the graph 
// thus removing all the unnecessary nodes that can never be in our route from 1 to n 

// if n is not in a path from 1 it'll be removed too so we'll check the parent of n after this if it is not the init value -> IMPOSSIBLE

// after this toposorting we'll begin our toposort with 1 and then going till n 

// to maintain the parents we'll use a parent array which will track the parents to the node which free-s the next node 
// since we'll eliminate all nodes before 1 that could eliminate other nodes we'll have our new par always as 1 for our routes

// but if then too n remains unvisited then we need to say IMPOSSIBLE 

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
    vector<int> indeg(n,0);

    repeat(i,0,m){
        cin>>a>>b;
        --a,--b;
        v[a].push_back(b);
        indeg[b]++;
    }

    vector<int> par(n,-1);
    queue<int> ts; // toposort queue
    repeat(i,1,n){ // all nodes except 1 but (we're having 0 based indexing here )
        if (indeg[i]==0){
            ts.push(i);
        }
    }

    while(ts.size()){
        int x = ts.front();
        for(auto i : v[x]){
            indeg[i]--;
            if (indeg[i]==0){
                if (i==0) continue; // 0 based indexing (we've to miss 1)
                ts.push(i);
                par[i] = x;
            }
        }
        ts.pop();
    }

    // if n is not on the route from 1 but is present on some other route 
    if (par[n-1]!=-1){
        print("IMPOSSIBLE");
        return 0;
    }

    ts.push(0);
    while(ts.size()){
        int x = ts.front();
        for(auto i : v[x]){
            indeg[i]--;
            if (indeg[i]==0){
                ts.push(i);
                par[i] = x;
            }
        }
        ts.pop();
    }
    
    // if n is still unvisited;
    if (par[n-1]==-1){
        print("IMPOSSIBLE");
        return 0;
    }

    int curr = n-1;
    stack<int> path;
    while(curr!=-1){
        path.push(curr+1);
        curr = par[curr];
    }
    
    print(path.size());
    while(path.size()){
        cout<<path.top()<<' ';
        path.pop();
    }

    return 0;
}