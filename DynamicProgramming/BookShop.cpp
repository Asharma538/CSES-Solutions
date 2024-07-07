// we'll use simple 0/1 Knapsack DP approach
// cost being the weight - rows - i
// pages being the value - columns - j
// but according to the constraints we need to optimize

// dp[i][j] = dp[i-1][j] or dp[i-1][j-cost[i]]; from 0/1 knapsack dp state
// if we see we only need two rows (i and i-1) so we can only keep two rows and swap them to go to the next step

// THIS IS CALLED MEMORY OPTIMISED 0/1 KNAPSACK

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define repeat(i,s,e) for(ll i=s;i<e;i++)

int main(){
    ll n,x; cin>>n>>x;
    ll cost[n],pages[n];
    repeat(i,0,n) cin>>cost[i];
    repeat(i,0,n) cin>>pages[i];

    // repeat(i,0,n) cout<<cost[i]<<' '; cout<<endl;
    // repeat(i,0,n) cout<<pages[i]<<' '; cout<<endl;

    ll dp[2][x+1];
    repeat(i,0,2) repeat(j,0,x+1) dp[i][j] = 0;

    // for first initialization
    repeat(i,0,x+1) if (i>=cost[0]){
        dp[0][i] = pages[0];
    }


    repeat(i,1,n){
        repeat(j,0,x+1){
            // i-th item , j coins
            // not purchasing this item / purchasing this item
            if (j>=cost[i]) dp[i%2][j] = max(dp[(i+1)%2][j],dp[(i+1)%2][j-cost[i]]+pages[i]);
            else dp[i%2][j] = dp[(i+1)%2][j];
        }
        // repeat(j,0,x+1){
        //     cout<<dp[i%2][j]<<' ';
        // }
        // cout<<'\n';
    }
    cout<<dp[(n-1)%2][x]<<'\n';
    return 0;
}