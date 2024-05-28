#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;
    
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    sort(arr,arr+n);

    int ans=0;
    int l=0,r=n-1;
    while(l<r){
        if (arr[l]+arr[r]<=x){
            ans++;
            l++;
            r--;
        }
        else{
            ans++;
            r--;
        }
    }
    if (l==r) ans++;
    cout<<ans<<'\n';
    
}