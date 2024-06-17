// we'll use three pointer approack
// l  , mid , r -> we will find (x-l) using two pointers and keep increasing l

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,x; cin>>n>>x;
    vector<pair<ll,ll>> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].first; arr[i].second = i+1;
    }
    sort(arr.begin(),arr.end());

    // l can start from 0 and reach n-2 max since mid and r will take min 1 elem each obv
    for(ll l=0;l<n-2;l++){
        ll mid = l+1,r=n-1;
        ll rm = x - arr[l].first;
        while(mid<r){
            // found the triplet...
            if (rm == arr[mid].first+arr[r].first){
                cout<<arr[l].second<<' '<<arr[mid].second<<' '<<arr[r].second<<'\n';
                return 0;
            }
            // to dec the sum
            else if (rm < arr[mid].first+arr[r].first){
                r--;
            }
            // to inc the sum
            else{
                mid++;
            }
        }
    }

    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}