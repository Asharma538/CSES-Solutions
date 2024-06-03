// this is a standard problem
// solved using prefix sum array,
// in the prefix sum array if we substract the elem at j with elem at index i
// we get sum of elems from i+1 to j - th index

// 1 2 3 4 5
// prefix sum
// 1 3 6 10 15
// arr[4] - arr[0] = 14, which is 2+3+4+5
// if we find the minimum index-i in prefix sum and substract it with every elem ahead, we'll get the max sum 

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n; cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++) cin>>arr[i];

    // the min and max, both can start with arr[0]
    
    ll min_s = arr[0];
    ll max_s = arr[0];

    // making arr a prefix sum arr

    for(ll i=1;i<n;i++) arr[i]+=arr[i-1];

    for(ll i=1;i<n;i++){
        max_s = max({arr[i]-max_s,max_s,arr[i]});
        min_s = min(min_s,arr[i]);
    }
    cout<<max_s<<'\n';

    return 0;
}