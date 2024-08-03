// it's a straight application of floyd warshall algorithm 
// let's code it down

// boilerplate is in comments

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


int main(){
    ll n,m,q; cin>>n>>m>>q;

    vector<vector<ll>> A(n,vector<ll>(n,1e18)); // init

    ll a,b,c; 
    repeat(i,0,m){
        cin>>a>>b>>c;
        a--,b--;
        A[a][b] = min(A[a][b],c);
        A[b][a] = min(A[b][a],c); // if there're multiple paths we just care about the shorter one
    }

    repeat(i,0,n) A[i][i] = 0;

    repeat(k,0,n) repeat(i,0,n) repeat(j,0,n) if (A[i][j] > A[i][k] + A[k][j]) A[i][j] = A[i][k] + A[k][j];

    repeat(i,0,q){
        cin>>a>>b; a--,b--;
        print( A[a][b]==1e18? -1 : A[a][b] );
    }


    return 0;
}