// we'll keep elements that can be substracted from our prefix sum array's i-th index in a set
// then we'll just adjust the set and check the ans as we go ahead

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,a,b; cin>>n>>a>>b;

    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];

    // convert arr to prefix sum arr
    for(ll i=1;i<n;i++) arr[i]+=arr[i-1];

    // the first base of our ans is to consider the first a elements' sum
    ll ans = arr[a-1];

    // multiset as there can be multiple values
    multiset<ll> s;

    for(ll i=a;i<n;i++){
        // inserting the potential elems that can be subtracted
        s.insert(arr[i-a]);

        if (i>=b){
            // we've to remove elements from set
            ans = max(ans,arr[i]-*s.begin());// min of set is its begining
            s.erase(s.find( arr[i-b] )); // removing the elem going beyong b-length (one elem to be removed)
        }
        else{
            // we just have to do basic check
            ans = max(ans , arr[i]); // subtract nothing
            ans = max(ans , arr[i]-*s.begin()); // remove the min elem
        }
    }
    
    cout<<ans<<'\n';
    return 0;
}