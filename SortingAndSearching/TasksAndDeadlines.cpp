#include <bits/stdc++.h>
using namespace std;

bool sort_func(pair<int,int> a,pair<int,int> b){
    if (a.first == b.first) return a.second>b.second; // for more reward
    return a.first < b.first; // as it can be finished early
}

int main(){
    
    // input
    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;

    // what makes the most sense here is to finish every task as early as possible, and make the tasks giving more
    // reward and same duration as priority
    // if we'll not go greedy here we'll still end up wasting the same time but we'll also lose more reward

    sort(arr.begin(),arr.end(),sort_func);

    long long ans = 0,finish_time = 0;
    for(int i=0;i<n;i++){
        finish_time += arr[i].first;
        ans += arr[i].second - finish_time;
    }

    cout<<ans<<'\n';
    return 0;
}