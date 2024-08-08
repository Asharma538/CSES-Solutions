// for finding one min route we can use dijkstra's algorithm easily
// but when we need k min routes we need to extend dijkstra's algorithm

// i.e. we just need to update the dis array that we keep and make it go till 
// k dimensions rather than one 

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

vector<vector<pair<ll,ll>>> v(100001);

int main(){
    ll n,m,k,a,b,c; cin>>n>>m>>k;
    repeat(i,0,m){
        cin>>a>>b>>c;
        --a,--b;  // for 0 based indexing
        // node , dis
        v[a].push_back({b,c});
    }

    vector<vector<ll>> dis(n,vector<ll>(k,1e18)); 
    dis[0][0] = 0; // reaching 0 for the first time will be our start 

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
    // dis , node 
    pq.push({0,0});

    while(pq.size()){
        ll x = pq.top().second;
        ll d = pq.top().first;
        pq.pop();

        if (dis[x][k-1] < d) continue; // we've found all the k ways to reach this node
        int _k_ = 0; 
        // to find the dim in which we've to go for our node 
        while(_k_<k){
            if (dis[x][_k_] >= d){ // updating the min dim that had dis >= d
                dis[x][_k_] = d;
                break;
            }
            _k_++;
        }

        short a = 2;
        // normal dijkstra extended 
        for(auto y : v[x]){
            repeat(i,0,k){
                // updating the path from the _k_ dim 
                if (dis[y.first][i] > dis[x][_k_] + y.second){
                    dis[y.first][i] = dis[x][_k_] + y.second;
                    pq.push({dis[y.first][i],y.first});
                    break; 
                    // since we've to leave once we've updated the path for this dim 
                }
            }
        }
        // repeat(i,0,n){
        //     repeat(j,0,k){
        //         cout<<dis[i][j]<<' ';
        //     } cout<<endl;
        // }
        // print("=============");
    }

    repeat(i,0,k) cout<<dis[n-1][i]<<' '; cout<<endl;
    print(sizeof(dis));
    return 0;
}