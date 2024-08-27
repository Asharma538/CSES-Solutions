// so we can do this using Hamiltonian cycle finding algorithm too but I'll do it using DP with Bitmasking 

// we will mask a bit when we've visited the corresponding node in the graph 

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

ll n,m;
// mask , node 
ll dp[(1<<20)][20];
vector<vector<ll>> v(20);
const ll mod = 1e9 + 7;

ll dfs(ll i,ll mask){
    if (i==n-1){
        // cout<<"Reached with mask:"<<mask<<'\n';
        if (mask == ((1<<n)-1)) return 1;
        return 0;
    }

    if (dp[mask][i]!=-1) return dp[mask][i];

    ll tmp = 0;
    for(auto c : v[i]){
        if ( mask & (1<<c) ) continue;
        tmp = (tmp + dfs(c,mask ^ (1<<c)))%mod;
    }
    return dp[mask][i] = tmp;
}

int main(){
    cin>>n>>m;
    ll a,b;
    repeat(i,0,m){
        cin>>a>>b; --a,--b;
        v[a].push_back(b);
    }
    repeat(i,0,1<<20) repeat(j,0,20) dp[i][j] = -1;

    // checking the graph 
    // repeat(i,0,n){
    //     cout<<i<<"->";
    //     print_it(v[i]);
    // }

    print(dfs(0,1));
    
    return 0;
}