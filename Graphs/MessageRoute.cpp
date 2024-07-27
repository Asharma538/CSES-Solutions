// we'll do a bfs for finding the shotest path 
// and make a par array for keeping track of our path like we did for labyrinth

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


// graph 2d vector
vector<vector<int>> v(100001);
// visited array for bfs
bool vis[100001];
// parent array for keeping track
int par[100001];

int main(){
    int n,m,a,b; cin>>n>>m;

    // number of edges
    repeat(i,0,m){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    q.push(1); vis[1] = 1; par[1]=-1;

    while(q.size()){
        int x = q.front();

        // neighbours of x
        for(auto i : v[x]){
            if (!vis[i]){
                vis[i]=1;
                // assigning the par
                par[i] = x;
                q.push(i);
            }
        }
        q.pop();
        // for debugging
    }

    if (vis[n]==1){
        stack<int> path;
        int curr = n;
        while(curr!=-1){
            path.push(curr);
            curr = par[curr];
        }
        print(path.size());
        while(path.size()){
            cout<<path.top()<<' ';
            path.pop();
        }
    } else {
        print("IMPOSSIBLE");
    }

    return 0;
}