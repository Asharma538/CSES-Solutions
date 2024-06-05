#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    ll s = 0;

    for(int i=0;i<n;i++){
        if (arr[i]>s+1 and arr[i]!=s+1 ){
            cout<<s+1<<'\n'; 
            return 0;
        }
        s += arr[i];
    }
    cout<<s+1<<'\n'; 
    return 0;
}