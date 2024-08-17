// we'll use Kruskal's algorithm for finding the Minimum Spanning Tree here 

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

vector<ll> par(100001);

ll find_par(ll u){
	if (par[u]>=0) return find_par(par[u]);
	return u;
}


int main(){
	ll n,m; cin>>n>>m;
	// dis , node1 , node2
	vector<pair<ll,pair<ll,ll>>> edges;
	ll a,b,d;
	repeat(i,0,m){
		cin>>a>>b>>d; 
		// weight, src , des
		edges.push_back({d,{a-1,b-1}});
	}

	// init with no par then we'll merge sets 
	repeat(i,0,n) par[i] = -1;
	
	priority_queue<pair<ll,pair<ll,ll>>,vector<pair<ll,pair<ll,ll>>>,greater<pair<ll,pair<ll,ll>>>> pq;
	repeat(i,0,m) pq.push(edges[i]);

	ll cost = 0,chosen = 0;

	while(pq.size() and chosen<n-1){
		auto e = pq.top();
		ll u = e.second.first;
		ll v = e.second.second;
		ll par_u = find_par(u);
		ll par_v = find_par(v);
		pq.pop();

		if (par_u==par_v) continue;
		if (par_u<=par_v){
			par[par_u] += par[par_v];
			par[par_v] = par_u;
		} else {
			par[par_v] += par[par_u];
			par[par_u] = par_v;
		}

		chosen++;
		cost += e.first;
	}

	if (chosen==n-1) print(cost);
	else print("IMPOSSIBLE");

	return 0;
}