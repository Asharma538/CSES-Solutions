// we'll propagate the number of possibilities we've found till the i-th index to the i+1-th index
// and our answer will be the number of possibilities we can make the last index elem of the array

// thus we'll use a 2D dp of (n x m+1), we don't need 0, but it will be easier to just use values till m
// dp[i][j] will denote the number of possibilities the i-th elem can be made following the constraints
// And dp[i][j] = dp[i-1][j-1]
//                     +dp[i-1][j]
//                     +dp[i-1][j+1]


#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll mod = 1e9 + 7;

int main(){
    ll n,m; cin>>n>>m;
    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];

    ll dp[n][m+1];

    for(ll i=0;i<n;i++) for(ll j=0;j<=m;j++) dp[i][j]=0;

    // all the values till m are equiprobable
    if (arr[0]==0) for(ll i=0;i<=m;i++) dp[0][i] = 1;
    // only the given value is possible all others are 0
    else dp[0][arr[0]] = 1;

    for(ll i=1;i<n;i++){
        if (arr[i]==0){
            // no fixed val
            for(ll j=1;j<=m;j++){
                if (j==1) dp[i][1] = (dp[i-1][1]+dp[i-1][2])%mod;
                else if (j==m) dp[i][m] = (dp[i-1][m]+dp[i-1][m-1])%mod;
                else dp[i][j] = (dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
            }
        }
        else{
            // a fixed val
            if (arr[i]==1) dp[i][1] = (dp[i-1][1]+dp[i-1][2])%mod;
            else if (arr[i]==m) dp[i][m] = (dp[i-1][m]+dp[i-1][m-1])%mod;
            else dp[i][arr[i]] = (dp[i-1][arr[i]-1]+dp[i-1][arr[i]]+dp[i-1][arr[i]+1])%mod;
        }
    }

    ll ans = 0;
    for(int i=1;i<=m;i++) ans = (ans + dp[n-1][i])%mod;
    cout<<ans<<'\n';
    return 0;
}