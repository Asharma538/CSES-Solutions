// // the obvious approach seems to be trying every route and then halving the price of the max flight ticket and  then giving that as the ans 

// // though in the worst case this will lead us to exploring O(2^(n)) paths and is not that efficient 

// // leaving this we can go ahead with the approach that's a little bit unconventional 

// let's apply dijkstras from 1 
// let's apply dijkstras from n in reversed edge graph 

// then for any edge between i and j
// total cost = dij[1 to i] + weight(i,j)/2 + dij[n to j]

// doing this for each edge will give us our min ans 

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
vector<vector<pair<ll,ll>>> rev_v(100001);

class edge{
    public:
    ll src,dst,weight;
    edge(ll a=0,ll b=0,ll c=0){
        src = a;
        dst = b;
        weight = c;
    }
};

int main(){
    ll n,m,a,b,c; cin>>n>>m;
    vector<edge> edges(m);
    repeat(i,0,m){
        cin>>a>>b>>c;
        --a,--b;
        
        edges[i].src = a; edges[i].dst = b; edges[i].weight = c;

        v[a].push_back({b,c});
        rev_v[b].push_back({a,c});
    }


    // dijkstra from 1 and n
    vector<ll> dis_1(n,1e18),dis_n(n,1e18);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    // from 1 
    dis_1[0]=0;
    // dis , node 
    pq.push({0,0});
    while(pq.size()){
        ll x = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dis_1[x]) continue; 
        dis_1[x] = d;
        for(auto i : v[x]){
            if (dis_1[i.first] > d + i.second){
                dis_1[i.first] = d + i.second;
                pq.push({dis_1[i.first],i.first});
            }
        }
    }

    // from n 
    dis_n[n-1]=0;
    // dis , node 
    pq.push({0,n-1});
    while(pq.size()){
        ll x = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (d > dis_n[x]) continue; 
        dis_n[x] = d;
        for(auto i : rev_v[x]){
            if (dis_n[i.first] > d + i.second){
                dis_n[i.first] = d + i.second;
                pq.push({dis_n[i.first],i.first});
            }
        }
    }

    ll ans = 1e18;
    for(auto i : edges){
        ans = min( dis_1[i.src] + dis_n[i.dst] + (i.weight/2) , ans );
    }
    print(ans);

    
    return 0;
}