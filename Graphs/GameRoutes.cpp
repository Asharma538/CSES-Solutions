// we'll use toposort for finding the ans 
// we'll use a ways array which will store for i-th node the number of ways to reach i-th node 

// we'll first remove all the unnecessary nodes like we did for prev questions 

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

const ll mod = 1e9 + 7;

int main(){
    int n,m; cin>>n>>m;
    vector<vector<int>> v(n);
    int a,b;
    vector<int> indeg(n,0);
    repeat(i,0,m){
        cin>>a>>b; --a,--b;
        v[a].push_back(b);
        indeg[b]++;
    }

    queue<int> ts;
    repeat(i,1,n) if (indeg[i]==0)  ts.push(i);

    // removing unnecessary nodes 
    while(ts.size()){
        for(auto i : v[ts.front()]){
            indeg[i]--;
            if (i==0) continue;
            if (indeg[i]==0) ts.push(i);
        }
        ts.pop();
    }

    vector<int> ways(n,0);
    ways[0] = 1;
    ts.push(0);
    while(ts.size()){
        for(auto i : v[ts.front()]){
            // ways to reach a child = ways to reach the child + ways to reach its parent 
            ways[i] += ways[ts.front()];
            ways[i] %= mod;

            indeg[i]--;
            if (indeg[i]==0) ts.push(i);
        }
        ts.pop();
    }

    print(ways[n-1]);

    return 0;
}