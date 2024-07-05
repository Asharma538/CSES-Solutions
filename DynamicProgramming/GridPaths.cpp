// we'll use the dp state of dp[i][j] = dp[i-1][j] + dp[i][j-1]

// if i==0 then dp[0][j]=1 for all j till we find a trap
// if j==0 then dp[i][0]=1 for all i till we find a trap

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define repeat(i,s,e) for(ll i=s;i<e;i++)

ll mod = 1e9 + 7;

int main(){
    ll n; cin>>n;
    char **arr = new char *[n];
    repeat(i,0,n) arr[i] = new char [n];

    repeat(i,0,n) repeat(j,0,n) cin>>arr[i][j];

    // we'll use ways (ways to reach any cell) as dp
    ll **ways = new ll * [n];
    repeat(i,0,n) ways[i] = new ll [n];
    repeat(i,0,n) repeat(j,0,n) ways[i][j] = 0;

    repeat(j,0,n){
        if (arr[0][j]=='*') break;
        ways[0][j] = 1;
    }

    repeat(i,0,n){
        if (arr[i][0]=='*') break;
        ways[i][0] = 1;
    }

    repeat(i,1,n){
        repeat(j,1,n){
            if (arr[i][j]=='*') continue;
            // gathering the ways we can reach the top cell + the left cell,
            // bcz we can only come from there to our present cell
            ways[i][j] += (ways[i-1][j] + ways[i][j-1])%mod;
        }
    }

    cout<<ways[n-1][n-1]<<'\n';
    return 0;
}