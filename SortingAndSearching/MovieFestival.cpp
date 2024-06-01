#include <bits/stdc++.h>
using namespace std;


int main(){

    int n; cin>>n;
    vector<pair<int,int>> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;

    // the idea is to take the greedy approach of picking the movie which ends earlier,
    // because if we take the one that ends later we only lose more time. 

    // thus greedy works while choosing maximum non intersecting intervals

    sort(arr.begin(),arr.end());

    int end_time = arr[0].second;
    int ans = 1;
    for(int i=1;i<n;i++){
        // we can watch 2 movies if end time = start time of the other one
        if (arr[i].first >= end_time){
            ans++;
            // watching this movie now
            end_time = arr[i].second;
        }
        else if (arr[i].first < end_time and arr[i].second < end_time ){
            // choosing this movie as its endtime is less
            end_time = arr[i].second;
        }
        else if (arr[i].first < end_time and arr[i].second >= end_time){
            continue;
        }
    }
    cout<<ans<<'\n';

    return 0;
}