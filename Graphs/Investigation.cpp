// so we just need to modify our dijkstra's algo a bit for this qn 
// it'll come easy with code see

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
    ll n,m,a,b,c; cin>>n>>m;
    vector<vector<pair<ll,ll>>> v(n);

    repeat(i,0,m){
        cin>>a>>b>>c;
        --a,--b;
        v[a].push_back({b,c});
    }

    vector<ll> min_cost(n,1e18);
    vector<ll> num_min_routes(n,0);
    vector<ll> min_flights(n,1e18);
    vector<ll> max_flights(n,0);

    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;

    // dis , node 
    pq.push({0,0});
    min_cost[0] = 0;
    max_flights[0] = 0;
    min_flights[0] = 0;
    num_min_routes[0] = 1;

    while(pq.size()){
        ll x = pq.top().second;
        ll d = pq.top().first;
        pq.pop();
        if (min_cost[x]<d) continue;
        min_cost[x] = d;

        for(auto i : v[x]){
            if (min_cost[i.first] > min_cost[x]+i.second){
                min_cost[i.first] = min_cost[x]+i.second;
                // since we just have one way to reach i right now i.e. from x 
                num_min_routes[i.first] = num_min_routes[x];
                // 1 more flight from x 
                min_flights[i.first] = min_flights[x]+1;
                max_flights[i.first] = max_flights[x]+1;
                // propagation / relaxation 
                pq.push({min_cost[i.first],i.first});
            } elif (min_cost[i.first] == min_cost[x]+i.second){
                // cost remains the same but the flights and routes can get updated see how 
                num_min_routes[i.first] = (num_min_routes[i.first]+num_min_routes[x])%mod;

                min_flights[i.first] = min( min_flights[i.first],min_flights[x]+1);
                max_flights[i.first] = max( max_flights[i.first],max_flights[x]+1);
            }
        }
    }

    cout<<min_cost[n-1]<<' '<<num_min_routes[n-1]<<' '<<min_flights[n-1]<<' '<<max_flights[n-1]<<'\n';
    
    return 0;
}