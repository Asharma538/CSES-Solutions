// we'll find a recursive solution and then memoise it

#include <bits/stdc++.h>
using namespace std;

#define ll long long

// set for keeping all sums
set<ll> s;
ll n;
ll arr[101];

// creating the max contraint dp table
ll dp[101][100001];

void phod(ll i=0,ll sm=0){
    // traversed all indices of arr
    if (i==n){
        s.insert(sm);
        return;
    }
    if (dp[i][sm+arr[i]]==-1){
        phod(i+1,sm+arr[i]);
        dp[i][sm+arr[i]] = 1;
    }
    if (dp[i][sm]==-1){
        phod(i+1,sm);
        dp[i][sm] = 1;
    }
}

int main(){
    cin>>n;
    for(ll i=0;i<n;i++) cin>>arr[i];

    // -1 denotes we've not seen this sum with this index
    for(ll i=0;i<101;i++) for(ll j=0;j<100001;j++) dp[i][j]=-1;

    phod();

    // 0 is not counted
    cout<<s.size()-1<<"\n";
    for(auto i : s) if (i!=0) cout<<i<<' '; cout<<endl;

    return 0;
}