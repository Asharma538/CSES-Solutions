// we'll use two pointer approach with a set and a multiset to keep track of our subarrays with 
// k distinct values

// we'll fix the left pointer and extend the right pointer till we can get k distinct values

// for ex
// n=9,k=3
// a b a c c d e f e
// 0 1 2 3 4 5 6 7 8
// l = 0 , r can go till 4
// number of subarrays = 0->0,1,2,3,4 --> 4-0+1 = 5
// l = 1 , r can go till 4
// number of subarrays = 1->1,2,3,4 --> 4-1+1 = 4
// l = 2 , r can go till 5
// and so on....

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,k; cin>>n>>k;
    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];

    set<ll> s;
    multiset<ll> ms;

    ll ans = 0;
    
    ll l=0,r=0;
    // extending r to max possible

    while(r<n and (s.size()<k or s.find(arr[r])!=s.end())){
        s.insert(arr[r]);
        ms.insert(arr[r]);
        r++;
    }
    // as r has already got exceeded here we don't need +1
    ans+=r-l;

    for(l=1;l<n;l++){
        // removing prev elem at previous left pointer
        ms.erase(ms.find(arr[l-1]));

        // if that was the only value in subarray
        if (ms.find(arr[l-1])==ms.end()) s.erase(arr[l-1]);

        // extending r to max possible
        while(r<n and (s.size()<k or s.find(arr[r])!=s.end())){
            s.insert(arr[r]);
            ms.insert(arr[r]);
            r++;
        }

        // as r has already got exceeded here we don't need +1
        ans+=r-l;
    }

    cout<<ans<<endl;
    return 0;
}