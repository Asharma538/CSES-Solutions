#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,x; cin>>n>>x;

    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    // we'll keep a set for storing x-a, if we've found a
    // pair<x-a,pos> , for every a till we get sum x

    set<pair<int,int>> rem;

    for(int i=0;i<n;i++){
        int a = arr[i];
        auto it = rem.lower_bound({a,0}); 
        // lower bound >= key, here we'll find a it which will point to x-a or smth bigger

        if (it!=rem.end() and (*it).first == a){
            cout<<(*it).second<<" "<<i+1<<'\n';
            return 0;
        }
        rem.insert({x-a,i+1});
    }
    cout<<"IMPOSSIBLE\n";
    return 0;
}