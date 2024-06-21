// this problem can be solved using prefix arrays
// prefix[0] = arr[0]
// prefix[i>0] = prefix[i-1] + arr[i]

// if prefix[i] - prefix[j] is calculated it gives the sum of values, arr[j+1],arr[j+2],....arr[i]

// so we'll keep a track of all the prefix sum values in a map
// then we'll find if any value if substracted makes the sum as x
// as if b-a = x
// => a = b-x
// as there can be multiple a's we'll keep a count of them too


#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,x; cin>>n>>x;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];
    
    // making arr a prefix arr
    for(ll i=1;i<n;i++) arr[i]+=arr[i-1];

    // map
    map<ll,ll> mp;
    // as we can always substract 0, i.e. consider all elems till i in the subarray
    mp[0]=1;

    ll ans = 0;

    for(ll i=0;i<n;i++){
        if (mp.find(arr[i]-x) != mp.end()) ans+=mp[arr[i]-x];
        mp[arr[i]]++;
    }
    cout<<ans<<'\n';
    return 0;
}