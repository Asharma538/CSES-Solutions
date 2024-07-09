// we need to find patterns in our tower, finding all the 2x2 patterns in our 2xN tower
// we'll observe 8 distinct patterns

// _______
// |__|__| 1
// |_____|
// _______
// |_____| 2
// |__|__|  
// _______
// |__|  | 3
// |__|__|
// _______
// |  |__| 4
// |__|__|
// _______
// |__|__| 5
// |__|__|
// _______
// |_____| 6
// |_____|
// _______
// |  |  | 7
// |__|__|
// _______
// |     | 8
// |_____|

// consider only the between 4 lines, ignore the borders
// we'll add 1 of these 8 every turn N times, making the top of the old block we added coincide with the bottom of our new block
// i.e. the lower 1xN of new block should be same as the upper 1xN of the old block

// thus 
// 1's top can be used as a bottom in 2,3,4,5,7
// 2's top can be used as a bottom in 1,6,8
// 2's top can be used as a bottom in 2,3,4,5,7
// 4's top can be used as a bottom in 2,3,4,5,7
// 5's top can be used as a bottom in 2,3,4,5,7
// 6's top can be used as a bottom in 1,6,8
// 7's top can be used as a bottom in 2,3,4,5,7
// 8's top can be used as a bottom in 1,6,8

// or we can say we can keep 1 6 8 on the top of 2 6 8
// and 2 3 4 5 7 on the top of 1 3 4 5 7

// the final ans need to be a 2 or 6-th block so that we can have a ceil to close the tower


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll t; cin>>t;
    // we'll calculate all possibilities till max of all n so that we save time
    ll max_n = -1,mod = 1e9 + 7;

    ll arr[t]; for(ll i=0;i<t;i++){
        cin>>arr[i];
        max_n = max(max_n,arr[i]);
    }

    ll dp[9][max_n+1];

    // all blocks can be the starting point
    for(int i=1;i<9;i++) dp[i][1] = 1;

    for(ll i=2;i<=max_n;i++){
        dp[1][i] = (dp[2][i-1]+dp[6][i-1]+dp[8][i-1])%mod;
        dp[6][i] = (dp[2][i-1]+dp[6][i-1]+dp[8][i-1])%mod;
        dp[8][i] = (dp[2][i-1]+dp[6][i-1]+dp[8][i-1])%mod;

        dp[2][i] = (dp[1][i-1]+dp[3][i-1]+dp[4][i-1]+dp[5][i-1]+dp[7][i-1])%mod;
        dp[3][i] = (dp[1][i-1]+dp[3][i-1]+dp[4][i-1]+dp[5][i-1]+dp[7][i-1])%mod;
        dp[4][i] = (dp[1][i-1]+dp[3][i-1]+dp[4][i-1]+dp[5][i-1]+dp[7][i-1])%mod;
        dp[5][i] = (dp[1][i-1]+dp[3][i-1]+dp[4][i-1]+dp[5][i-1]+dp[7][i-1])%mod;
        dp[7][i] = (dp[1][i-1]+dp[3][i-1]+dp[4][i-1]+dp[5][i-1]+dp[7][i-1])%mod;
    }

    for(ll i : arr){
        cout<<(dp[2][i]+dp[6][i])%mod<<'\n';
    }

    return 0;
}