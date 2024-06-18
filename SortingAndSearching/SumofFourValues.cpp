// the idea is to make it similar to sum of two values problem
// here we'll store the sum of two values that we've seen and will look if the remaining sum is already available

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,x; cin>>n>>x;
    vector<ll> arr(n); for(ll i=0;i<n;i++) cin>>arr[i];

    map<ll,pair<ll,ll>> sums_seen;

    for(int i=0;i<n;i++){
        // finding if any of the i,j pairs can make the sum
        for(int j=i+1;j<n;j++){
            if (sums_seen.find(x-arr[i]-arr[j])!=sums_seen.end()){
                cout<<i+1<<' '<<j+1<<' '<<sums_seen[x-arr[i]-arr[j]].first+1<<' '<<sums_seen[x-arr[i]-arr[j]].second+1<<'\n';
                return 0;
            }
        }
        // adding the sums
        for(int j=0;j<i;j++){
            sums_seen[arr[i]+arr[j]] = {i,j};
        }

    }

    cout<<"IMPOSSIBLE\n";
    return 0;
}