// whenever we've these small constraints we obviously need to think about power of 2
// so here in this question we'll have a dp state as 
// dp[i] = { number_of_rides_gone , capacity_filled_in_current_ride } this will be a paired state
// with 
// dp[0] = { 0 , 0 } as no rides that have gone, weight filled till now

// #NOTE
// dp[i] will talk only about the passengers that have 1 in the binary notation of i
// for example 
// if i=5, n=4
// then i = 0101
// which will imply only these 2nd and 4th passengers are standing in the queue and we'll ignore all other passengers having 0 (1st and 3rd)

// dp[i] = { rides_gone , capacity_filled } for the passengers having a 1 in the binary notation of i

// so for propagation later on we'll go from i=0 to i=pow(2,n) in which 
// for each j=0 to j=n we'll find whether we can fit the j-th passenger in our current ride 
// or we need to send this ride and start a new one

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    int n,x; 
    cin>>n>>x;
    ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    pair<ll,ll> dp[(int) pow(2,n)];
    dp[0] = {0,0};

    for(ll i=1;i<pow(2,n);i++){
        // initializing with max so that we can find the min
        dp[i] = {n+1,0};
        for(ll j=0;j<n;j++){
            if ( (1<<j) & i ){
                // if we leave the j-th passenger what was the state can be found by dp[ i ^ (1<<j) ]

                if ( dp[i ^ (1<<j)].second + arr[j] <= x ){
                    // number of rides gone remain the same and we fit the current j-th passenger in the previous state's ride
                    dp[i] = min ( dp[i] , { dp[i ^ (1<<j)].first ,  dp[i ^ (1<<j)].second + arr[j] } );
                }
                else{
                    // we need to send this ride and restart filling the new one
                    dp[i] = min ( dp[i] , { dp[i ^ (1<<j)].first + 1 ,  arr[j] } );
                }
            }
        }
    }

    // output will be shown when all the passengers are in queue with all having 1 in their positions 
    // we also need to count the ride we were filling at the last
    cout<<dp[ (int)pow(2,n) - 1].first + 1<<'\n';

    return 0;
}