// This is an implementation problem for finding the euler's cycle over our graph

// we need to start from 1 and end at 1

// steps:
// 1. Maintain a stack 
// 2. Start from 1 
// 3. Push node into the stack which we'll visit from 1, and erase the edge between 1 and that node 
// 4. Now do this till the node we're in, loses all the edges if so push it in the ans and pop it from the stack now 

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
    
    // the basic obs we need to make is that if a node has indegree odd then the ans will be IMPOSSIBLE 

    vector<int> indeg(n+1,0);

    // using set to keep edge connections because it'll be east to remove an edge if maintained this way 
    vector<set<int>> v(n+1);
    repeat(i,0,m){
        int a,b; cin>>a>>b;
        v[a].insert(b); v[b].insert(a);
        indeg[a]++,indeg[b]++;
    }

    repeat(i,0,n+1) if (indeg[i]%2){
        print("IMPOSSIBLE");
        return 0;
    }

    vector<int> ans;

    stack<int> s;
    s.push(1);
    while(s.size()){
        int x = s.top();
        if (v[x].size()){
            int to = *(v[x].begin());
            // removing the edge 
            v[x].erase(v[x].begin());
            v[to].erase(x);
            // pushing it in stack 
            s.push(to);
        } else {
            ans.push_back(x);
            s.pop();
        }
    }

    // since the size of the path will be number of edges + 1 
    if (ans.size()!=m+1){
        print("IMPOSSIBLE");
        return 0;
    } else {
        print_it(ans);
    }
    


    return 0;
}