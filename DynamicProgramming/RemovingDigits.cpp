/// this qn can be done using Greed, no need of DP

#include <bits/stdc++.h>
using namespace std;

int find_max_digit(int x){
    int mx = 0;
    while(x){
        mx = max(mx,x%10);
        x/=10;
    }
    return mx;
}

int main(){
    int n,ans=0; 
    cin>>n;
    while(n){
        n-=find_max_digit(n);
        ans++;
    }
    cout<<ans<<'\n';
}