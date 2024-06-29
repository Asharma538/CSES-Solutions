// we'll keep a track of all the free members of the group (who are not watching any movie)
// we will assign them to any movie if they are free (ans+1)

// we'll sort the movies in pair<start,end> then traverse them

// if none of the members are free then we'll check if the present movie's end is lesser than 
// any movie's end which the members are watching
// if this is the case then we'll tell that member to switch the movie to the present one (ans remains same)

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,k; cin>>n>>k;
    vector<pair<ll,ll>> arr(n); for(ll i=0;i<n;i++) cin>>arr[i].first>>arr[i].second;
    sort(arr.begin(),arr.end());

    ll free_members = k,ans = 0;
    // for keeping track of the movies endings that the members are watching
    // movie's_end
    multiset<ll> s;

    for(ll i=0;i<n;i++){
        // checking the movies being watched are ended now
        // cout<<free_members<<'\n';
        // for(auto i : s) cout<<i<<' '; cout<<endl;
        // cout<<"========\n";
        while ( s.size() and (*s.begin()) <= arr[i].first ){
            s.erase(s.begin());
            free_members++;
        }
        if (free_members){
            // end time inserted
            ans++;
            s.insert(arr[i].second);
            free_members--;
        } else if ((*--s.end()) > arr[i].second ) { // the present movie is ending early
            s.insert(arr[i].second);
            s.erase(--s.end());
        }
    }
    cout<<ans<<endl;
    return 0;
}