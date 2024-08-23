// this is a directed graph , which can have cycles 

// so we will have some rooms to which we can get back 
// so all the rooms in a cycle are connected, which essentially mean they can be treated all as a separate node 

// so all cycles ( say SCC ) will be represented as 1 node each 

// and the connection between SCC will be a directed acyclic graph i.e. DAG

// in this DAG which we formed after shrinking the old graph, we can simply use toposort to find the answer 

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

vector<vector<ll>> v(100001);
vector<vector<ll>> rev_v(100001);
// for keeping a track of vis nodes 
vector<bool> vis(100001);
// for keeping which node belongs to which component 
// we are keeping these two separate becuase we'll need to shrink components to one node
vector<ll> component_id(100001);
stack<ll> ordering;

void dfs(ll i){
    vis[i] = 1;
    for(ll c : v[i]) if (!vis[c]) dfs(c);
    ordering.push(i);
}

void dfs_rev(ll i,ll comp){
    component_id[i] = comp; vis[i]=1;
    for(ll c : rev_v[i]) if (!vis[c]) dfs_rev(c,comp);
}

int main(){
    ll n,m,a,b; cin>>n>>m;
    vector<ll> coins(n,0);


    repeat(i,0,n) cin>>coins[i];
    repeat(i,0,m){
        cin>>a>>b; --a,--b;
        v[a].push_back(b);
        rev_v[b].push_back(a);
    }

    // for finding the ordering 
    repeat(i,0,n) if (!vis[i]) dfs(i);

    repeat(i,0,n) vis[i] = 0;

    ll comp=0;
    while(ordering.size()){
        if (!vis[ordering.top()]) dfs_rev(ordering.top(),++comp);
        ordering.pop();
    }


    // now to reduce our graph we need to check if two nodes belong to different components and they have an edge bw them 

    // coins in a component 
    vector<ll> component_coins(comp,0);
    // indegree for toposort on DAG 
    vector<ll> indeg(comp,0);

    // reduced graph i.e. our DAG 
    vector<vector<ll>> reduced_v(comp);

    repeat(i,0,n){
        // over all edges 
        for(auto c : v[i]){
            if (component_id[i]!=component_id[c]){
                // we need to add an edge between the components 
                reduced_v[component_id[i]-1].push_back(component_id[c]-1);
                indeg[component_id[c]-1]++;
            }
        }
        component_coins[ component_id[i]-1 ] += coins[i];
    }


    queue<ll> toposort;
    repeat(i,0,comp) if (indeg[i]==0) toposort.push(i);

    // for maintaining coins we have gathered while doing toposort 
    vector<ll> dp(comp);
    repeat(i,0,comp) dp[i] = component_coins[i];

    while(toposort.size()){
        ll x = toposort.front();
        for(ll c : reduced_v[x]){
            dp[c] = max( dp[c] , component_coins[c]+component_coins[x] );
            indeg[c]--;
            if (indeg[c]==0){
                // if we have found the maximum coins we can gather till we reach c, then we need to make the component_coins for that node  till now as dp[node]
                component_coins[c] = dp[c];
                toposort.push(c);
            }
        }
        toposort.pop();
    }

    ll ans = 0;
    repeat(i,0,comp) ans = max(ans,dp[i]);
    print(ans);



    
    return 0;
}