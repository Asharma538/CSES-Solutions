// we just need to perform a simple DFS to find the sequence

// the graph will be formed by making 2*i and 2*i+1 as children of the node i 

// we also need to check in dfs that every new node we're covering will cover 1 more new node 

// so that we can find the minimum sequence 

// for example 

// n=2

// 00 -> 01 -> 10
//          -> 11

// but if we ensure each node covers 1 more we can do 

// 00 -> 01 -> 10 , 10 covers nothing don't go at it first
// 00 -> 01 -> 11 -> 10 => Minimum sequence 

// now 1 can go to 10 or 11 (i.e. 2 or 3)
// but if 1 goes to 10 then 10 can't go anywhere 
// and since 11 is the only thing left we'll have to to back and go to 11 again from 1 

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

const ll mx_n = 1<<16;
vector<vector<ll>> v(mx_n);
vector<bool> vis(mx_n,0);
vector<ll> child(mx_n,-1); // for printing the sequence 

ll dfs(ll i,ll covered){
    vis[i] = true;
    ll ans = covered;
    for(auto c : v[i]){
        if (vis[c]) continue;
        ll covered_new = dfs(c,covered+1);
        if (covered_new < covered) continue;
        ans = covered_new;
        child[i] = c;
    }
    return ans;
}

int main(){
    ll n; cin>>n;
    ll p = (1<<n);
    repeat(i,0,p){
        ll a = ((i<<1) + 1)%p;
        ll b = (i<<1)%p;
        v[i].push_back(a);
        v[i].push_back(b);
    }

    dfs(0,1);

    ll u = 0;
    repeat(i,0,n) cout<<u;
    do
    {
        // the new char will be the last binary digit 
        u = child[u];
        cout<<u%2;
    } while (child[u]!=-1);

    return 0;
}