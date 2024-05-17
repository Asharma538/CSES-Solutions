#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll ans = 1;
    ll mod = (1e9 + 7);
    for(int i=0;i<n;i++) ans = (2*ans)%mod;
    cout<<ans<<"\n";
}