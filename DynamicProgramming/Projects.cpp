#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define repeat(i,s,e) for(ll i=s;i<e;i++)

int main(){

    ll n; cin>>n;
    vector<pair<pair<ll,ll>,ll>> arr(n);
    // taking input
    // compressing the coordinates
    map<ll,ll> compress_coord;
    repeat(i,0,n){
        cin>>arr[i].first.first>>arr[i].first.second>>arr[i].second;
        arr[i].first.second++; // for easy reference of end will help later
        compress_coord[arr[i].first.first],compress_coord[arr[i].first.second]; // will reserve a val in map
    }

    ll new_coord = 0;
    for(auto &v : compress_coord){
        v.second = new_coord++;
    }
    // we've compressed the coord, now we'll make a arr which will have all the projects that end on day i, where i>=0 and i<=new_coord
    vector<vector<pair<ll,ll>>> projects(new_coord);
    repeat(i,0,n){
        // start date & money on the end date for reference
        projects[compress_coord[arr[i].first.second]].push_back({compress_coord[arr[i].first.first],arr[i].second});
    }

    // we'll make a DP table of state , dp[i] = max(dp[i-1],dp[start_date_of_project that end on day i]+money_by_project_ending_on_day_i)
    vector<ll> dp(new_coord,0); // init with 0
    repeat(i,0,new_coord){
        
        if (i>0) dp[i]=dp[i-1];

        for(auto p : projects[i]){
            // either the money we earned till yesterday or the money we can earn by taking this i-th project
            dp[i] = max(dp[i],dp[p.first]+p.second);
        }

    }

    cout<<dp[new_coord-1]<<'\n';


    return 0;
}

// we just compressed the coordinates so that we can make the dp length feasible
// and thus we can find our max money