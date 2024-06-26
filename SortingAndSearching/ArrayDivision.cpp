#include <bits/stdc++.h>
using namespace std;

#define ll long long

// we'll use a binary search approach to find if any answer is feasible or not
// that we'll check by checking the no. of divisions that we have to make to achieve that ans

// if there're more divisions we'll inc l, otherwise we will dec r

ll divisions(vector<ll> arr,ll k){
    ll subarr_sum = 0;
    ll divs = 1;
    for(auto i : arr){
        if (subarr_sum+i>k){
            divs++;
            subarr_sum = 0;
        }
        subarr_sum += i;
    }
    return divs;
}

int main(){
    ll n,k; cin>>n>>k;
    vector<ll> arr(n); for(ll i=0;i<n;i++) cin>>arr[i];
    
    // l can be the maximum elem of the arr, for k=n
    // r can be the sum of the whole arr, for k=1
    ll l = 0, r = 0;
    for(auto i : arr){
        r += i; l = max(l,i);
    }

    ll ans = 1e18;

    while(l<=r){
        // this type of mid calc is done to avoid overflow
        ll mid = l + (r-l)/2;

        ll res = divisions(arr,mid);
        // if we have to make more divisions that means the mid (assumed ans) can't be achieved and we'll have
        // to raise the bar
        if(res>k){
            l = mid+1;
        }
        // if divisions are less we can anyways increase them by splitting up elems
        else{
            ans = min(ans,mid);
            r = mid-1;
        }
    }

    cout<<ans<<'\n';
    return 0;
}