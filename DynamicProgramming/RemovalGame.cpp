// this is a two player DP problem

#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;
ll arr[5000];

// max contraint dp
ll dp[5000][5000];


// recursive dp
ll phod(int s,int e){
    if (s>e) return 0;
    if (s==e) return arr[s];

    if (dp[s][e]==-1){
        // this something will be the given after the chance of second player
        // and in his/er turn he/she will leave the min possible 
        dp[s][e] = max(
            // taken the first elem
            // 2nd player takes the remaining max and leaves min for the 1st player
            arr[s]+min(phod(s+1,e-1),phod(s+2,e)),
            arr[e]+min(phod(s+1,e-1),phod(s,e-2))
        );
    }
    // else return simply anyways
    return dp[s][e];
}


int main(){
    cin>>n;
    for(ll i=0;i<n;i++) cin>>arr[i];

    // we'll make a dp table for start,end pair i.e. 2d dp
    // this start,end will contain the max possible score that can be achieved with s,e as the current state of game
    // -1 will denote we've not yet visited this state 
    for(ll i=0;i<n;i++) for(ll j=0;j<n;j++) dp[i][j] = -1;

    cout<<phod(0,n-1)<<'\n';
    return 0;
}