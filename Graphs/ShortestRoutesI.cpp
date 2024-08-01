// this is a simple application of dijkstra's algorithm

// so let's implement that

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
    ll n,m,a,b,c; cin>>n>>m;
    repeat(i,0,m){
        cin>>a>>b>>c;
        a--,b--;
        // inserting dis too with neighbours in the one way flights
        v[a].push_back({b,c});
    }

    // dis array for dijkstra
    ll dis[n];
    repeat(i,0,n) dis[i] = 1e18;

    // priority queue for dijkstra -> is a min heap but by default it is a max heap
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    // dis from node , that node
    pq.push({0,0});
    dis[0] = 0;

    while (pq.size()){
        ll d = pq.top().first;
        ll u = pq.top().second;
        pq.pop();
        if (dis[u] < d) continue; // if there are more optimized ways
        for(auto i: v[u]){
            if (dis[i.first] > d + i.second){
                dis[i.first] = d+i.second;
                pq.push({dis[i.first],i.first});
            }
        }
    }
    print_it(dis);

    return 0;
}