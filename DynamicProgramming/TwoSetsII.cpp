#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
ll mod = 1e9 + 7;

// max constraint dp table, index can reach 500 and sm can reac something close to n*n (but obv less than)
ll dp[501][250000];

ll phod(int index,int sm){
    if (sm > ((n*(n+1))/4) ) return 0;
    if (sm == ((n*(n+1))/4) ) return 1;
    if (index==n+1) return 0;
    if (dp[index][sm]==-1) dp[index][sm] = (phod(index+1,sm+index)+phod(index+1,sm))%(mod);
    return dp[index][sm];
}

int main(){
    // we'll keep a 2D dp 
    // index,sum_of_one_set
    // if not seen this state we'll put it -1
    // otherwise it'll have some other value
    cin>>n;

    // initialize dp
    for(ll i=0;i<n;i++) for(ll j=0;j<((n*(n+1))/4)+1;j++) dp[i][j] = -1;

    // division can't happen equally in 2 sets
    if (n%4==1 or n%4==2) cout<<0<<'\n';
    // otherwise
    else cout<<phod(1,0)<<'\n';

    return 0;
}