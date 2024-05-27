#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define repeat(i,s,e) for(ll i=s;i<e;i++)

ll phod(ll itr,ll sm_a,ll sm_b,ll n,ll* arr){
    if (itr==n) return abs(sm_a-sm_b);

    return min(
        phod(itr+1,sm_a+arr[itr],sm_b,n,arr),
        phod(itr+1,sm_a,sm_b+arr[itr],n,arr)
    );
}

int main(){
    ll n; cin>>n;
    ll arr[n];
    repeat(i,0,n) cin>>arr[i];

    cout<<phod(0,0,0,n,arr);

    return 0;
}