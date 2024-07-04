// we'll traverse arr
// we'll check in how many ways i-arr[j] can be made for i->(1 to x), add it to dp[i]

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,x; cin>>n>>x;
    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];

    ll mod = 1e9 + 7;

    ll dp[x+1]={0};
    dp[0]=1; // there's 1 way to make 0, don't choose anything!

    for(auto j : arr) for(ll i=0;i<=x;i++) if (j <= i) dp[i] = (dp[i]+dp[i-j])%mod;

    cout<<dp[x]<<'\n';
    return 0;
}