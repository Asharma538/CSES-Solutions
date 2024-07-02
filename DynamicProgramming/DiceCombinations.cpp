// by checking by hand we can know
// dp[i] = pow(2,i-1) for i=1 to 6

// for others dp[i] = dp[i-1]+dp[i-2]+...+dp[i-6]

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll arr[max(7LL,n+1)]={0};

    ll mod = 1e9+7;

    for(ll i=1;i<=6;i++) arr[i] = pow(2,i-1);

    for(ll i=7;i<=n;i++) for(ll j=1;j<=6;j++) arr[i] = (arr[i]+arr[i-j])%(mod);

    cout<<arr[n]<<'\n';
    return 0;
}