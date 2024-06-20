// we'll use a two pointer approach 
// j , i
//  i will keep inc till the sum between them reaches x or greater
//  j will keep inc till the sum between then reaches x or lesser

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n,x; cin>>n>>x;
    ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    ll sum_between=0,i=0,j=0,ans=0;

    for(;i<n;i++){
        // adding the val at i
        sum_between += arr[i];
        // inc j if possible
        while (sum_between>x and j<i){
            sum_between -= arr[j];
            j++;
        }
        // if the subarray has sum x
        if (sum_between==x) ans++;
    }
    cout<<ans<<endl;
    return 0;
}