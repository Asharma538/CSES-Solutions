// we'll check over all the coins and see the minimum possible state
// dp[i] = min ( dp[i] , dp[i-j]+1 ), where j : arr

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,x; cin>>n>>x;
    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n);

    // if min elem is > x
    if (arr[0]>x){
        cout<<-1<<'\n';
        return 0;
    }

    ll dp[x+1]={0};

    for(ll i: arr) dp[i]=1;

    for(ll i=1;i<=x;i++){
        if (dp[i]) continue;

        dp[i]=1e9;
        // to not go -ve consider i>j
        for(ll j : arr) if (j<i) dp[i]=min(dp[i],dp[i-j]+1);
    }

    // if can't be made 
    if (dp[x]==1e9) cout<<-1<<'\n';
    // can be made
    else cout<<dp[x]<<'\n';

    return 0;
}