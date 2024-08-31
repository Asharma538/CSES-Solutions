// This question involves the knowledge of MAX FLOW MIN CUT Algorithm,
// either you can go by Ford Fulkerson / Edmonds Karp 

// I'll go by Edmond Karp

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

// for storing neighbours 
vector<set<ll>> v(501);

// for storing edge weights
ll arr[501][501];


ll n,m;

// we need to reach n again and again for increasing our flow 
ll reach_n(){


    // for tracking vis nodes
    vector<bool> vis(501,false);
    // for tracking the path found and updating it 
    vector<ll> par(501,-1);

    // performing a BFS 
    // Queue < node , max_flow_possible_till_now >
    queue<pair<ll,ll>> q;
    q.push({1,1e18}); //source capacity is INFINITY
    vis[1] = 1;

    while(q.size()){
        ll x = q.front().first;
        ll min_flow = q.front().second;
        q.pop();

        // if we're at the destination 
        if (x==n){
            // updating all the edge capacities 
            while(par[x]!=-1){
                arr[par[x]][x] -= min_flow;
                arr[x][par[x]] += min_flow;

                x = par[x];
            }
            return min_flow;
        }

        for(auto c : v[x]){
            if (vis[c] or arr[x][c]<=0) continue;
            vis[c] = true;
            par[c] = x;
            q.push({c,min(min_flow,arr[x][c])});
        }

    }

    // if we can't find any path 
    return -1;

}

int main(){
    ll a,b,c; cin>>n>>m;
    repeat(i,0,m){
        cin>>a>>b>>c;
        v[a].insert(b);
        // for back edges 
        v[b].insert(a);

        // since there can be multiple edges between same nodes
        arr[a][b] += c;
    }

    ll max_flow = 0;

    while(1){
        ll ans = reach_n();
        if (ans==-1) break;
        max_flow += ans;
    }

    print(max_flow);

    return 0;
}