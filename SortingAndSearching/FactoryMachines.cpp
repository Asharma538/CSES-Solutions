#include <bits/stdc++.h>
using namespace std;

#define ll long long



int main(){

    ll n,t; cin>>n>>t;
    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];

    if (n==1){
        cout<<t*arr[0]<<'\n';
        return 0;
    }

    // we'll do bin search for finding the minimum time
    ll l=0,r=1e18;

    // r will always be the time that really exists and >= t products can be made in this time
    // l will always be the time in which < t products can be made


    while(l<r-1){
        ll mid = (l+r)/2;

        ll prods = 0;
        for(ll i=0;i<n;i++){
            if (prods>=1e18){
                // for saving overflow
                break;
            }
            prods+=(mid/arr[i]);
        }

        if (prods>=t){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<r<<'\n';
    return 0;
}