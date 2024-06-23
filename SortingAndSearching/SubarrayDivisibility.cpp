#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll arr[n]; 
    for(ll i=0;i<n;i++){
        cin>>arr[i]; arr[i]%=n;    
    }

    // keeping only remainders and making the array prefix sums
    // as some elems can remain -ve, so to make them positive we're adding n

    for(ll i=1;i<n;i++) arr[i] = (arr[i]+arr[i-1]+n)%n;

    // we'll keep the extra-s that we've in arr in a map so that we can see if we've any extra to be removed
    map<ll,ll> mp;
    ll ans = 0;

    for(ll i=0;i<n;i++){
        // finding if we can substract any extra
        if (mp.find(arr[i])!=mp.end()) ans += mp[arr[i]];

        // increasing the extra-s count
        mp[arr[i]]++;
    }

    // adding mp[0] because we've the full subarrays becoming divisible at that point as well
    cout<<ans+mp[0]<<'\n';

    return 0;
}