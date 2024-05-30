#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;

    set<pair<int,int>> timestamps;
    // sorting all the timestamps and soring them, kinda hashing each one
    // 
    // if its of arrival , v= +1 
    // if its of departure, v= -1

    // set will be of type, { timestamp , v }

    for(auto i : arr) timestamps.insert({i.first,1}),timestamps.insert({i.second,-1});

    // at any time, footfall represents the no. of people in restaurant
    // +1 is for arrival of a cust.
    // -1 is for departure
    // going in sorted order of these timestamps will let us know the footfall of tha timestamps
    // we don't need to see on other timestamps since it will be of no use 
    
    int ans = 0;
    int footfall = 0;
    for(auto i : timestamps){
        if (i.second==1) footfall++;
        else footfall--;

        ans = max(ans,footfall);
    }
    cout<<ans<<'\n';

    return 0;
}