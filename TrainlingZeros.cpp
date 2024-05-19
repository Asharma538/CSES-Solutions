#include <iostream>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll ans = 0;
    while(n){
        ans += (n/5);
        n/=5;
    }
    cout<<ans<<"\n";

    return 0;
}