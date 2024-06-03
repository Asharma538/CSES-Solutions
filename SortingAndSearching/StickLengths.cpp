// the length for which this min cost is achieved is the median

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    if (n%2){
        // median is the center elem
        ll med = arr[n/2];
        ll x = 0;
        for(ll i=0;i<n;i++) x += abs(arr[i] - med);
        cout<<x<<'\n';
    }
    else{
        // median is the avg of the middle two
        // we'll calc our cost for both the individual two
        ll med1 = arr[(n/2) - 1], med2 = arr[(n/2)];
        ll x1 = 0, x2 = 0;
        for(ll i=0;i<n;i++){
            x1 += abs(arr[i] - med1);
            x2 += abs(arr[i] - med2);
        }
        cout<<min(x1,x2)<<'\n';
    }

    return 0;
}