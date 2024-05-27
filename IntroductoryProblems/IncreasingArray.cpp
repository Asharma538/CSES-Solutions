#include <iostream>
using namespace std;


#define ll long long

int main(){
    ll n; cin>>n;
    ll ans = 0;
    ll last_a = 0;
    for(ll i=0;i<n;i++){
        int a; cin>>a;

        if (a>last_a){
            last_a = a;
        }
        else{
            ans += (last_a-a);
        }

    }
    cout<<ans<<'\n';
}