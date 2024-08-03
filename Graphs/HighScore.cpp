// // // we need bellman ford  algorithm as prereq here 

// // as we clearly need to find a positive cycle for a -1 score 
// // we can negate the edges and use bellman ford for the same 

// a check would be to see if both 1 and n can be reached from the cycle, so that we can ensure the cycle lies between them and can be visited later in path 
// to check if the cycle can be visited 

// we'll do a bfs from 1 on normal graph 
// then we'll flip the source and destination in the graph and make a new graph then do a bfs from n 

// if any node can be visited from both 1 and n we confirm the cycle on that node is reachable from 1 and n 


// boileplate in comments 

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

class edge{
    public:
    ll src,dst,weight;
    edge(ll a=0,ll b=0,ll c=0){
        src=a;
        dst=b;
        weight=c;
    }
};


int main(){

    ll n,m,a,b,c; cin>>n>>m;
    vector<vector<ll>> graph(n);
    vector<vector<ll>> rev_graph(n);
    vector<edge> edges(m);

    repeat(i,0,m){
        cin>>a>>b>>c;
        --a,--b;
        graph[a].push_back(b); // we don't need c for bfs
        rev_graph[b].push_back(a);

        edges[i].src = a;
        edges[i].dst = b;
        edges[i].weight = -c; // negating the edges
    }

    queue<ll> bfs;

    // doing bfs from 1 
    vector<bool> vis_1(n,false);
    vis_1[0]=1; // since we're following 0 based indexing for nodes
    bfs.push(0);

    while(bfs.size()){
        ll x = bfs.front();
        for(auto i : graph[x]){
            if (!vis_1[i]){
                vis_1[i]=1;
                bfs.push(i);
            }
        }
        bfs.pop();
    }

    // doing bfs from n 
    vector<bool> vis_n(n,false);
    vis_n[n-1]=1; // since we're following 0 based indexing for nodes
    bfs.push(n-1);

    while(bfs.size()){
        ll x = bfs.front();
        for(auto i : rev_graph[x]){
            if (!vis_n[i]){
                vis_n[i]=1;
                bfs.push(i);
            }
        }
        bfs.pop();
    }


    // BELLMAN FORD 
    vector<ll> dis(n,1e18),dis_check(n);
    dis[0]=0;

    repeat(j,0,n) repeat(i,0,m) dis[edges[i].dst] = min(dis[edges[i].dst],dis[edges[i].src]+edges[i].weight);

    // dis_check can be used for cycle detection
    repeat(i,0,n) dis_check[i] = dis[i];

    repeat(i,0,m) dis[edges[i].dst] = min(dis[edges[i].dst],dis[edges[i].src]+edges[i].weight);

    // if there's a cycle the distance will change and if they change we need to see if that node is visited from both 1 and n
    repeat(i,0,n){
        if (dis_check[i]!=dis[i] and vis_1[i] and vis_n[i]){
            print(-1);
            return 0;
        }
    }

    print(-dis[n-1]);

    return 0;
}