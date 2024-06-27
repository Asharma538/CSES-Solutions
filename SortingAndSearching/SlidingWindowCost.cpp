// so we'll essentially keep two sets
// one for the elems having val <= median
// other one for the ones with val > median

// we'll just slide the window and do the adjustments accordingly, and maintain two sums, left & right

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n,k; cin>>n>>k;
    ll arr[n]; for(ll i=0;i<n;i++) cin>>arr[i];

    set<pair<ll,ll>> left_set,right_set;
    ll left_sum=0,right_sum=0;

    // using index just for distinguishing between elems, you can use multiset too but make acc changes
    for(ll i=0;i<k;i++){
        right_sum += arr[i];
        right_set.insert({arr[i],i});
    }

    // adding the elems <= median to left set
    for(ll i=0;i<(k+1)/2;i++){
        left_sum += (*right_set.begin()).first;
        right_sum -= (*right_set.begin()).first;
        left_set.insert(*right_set.begin());
        right_set.erase(right_set.begin());
    }
    
    // for(auto i : left_set) cout<<i.first<<' '; cout<<'\n';
    // for(auto i : right_set) cout<<i.first<<' '; cout<<'\n';
    // cout<<left_sum<<'\n';
    // cout<<right_sum<<'\n';

    // cost = ( size(left_set)*median - sum(left_set) ) + ( sum(right_set) - size(right_set)*median )
    // on simplifying
    ll median = (*--left_set.end()).first; // median will be the elem in between, for even k you can take any
    cout<< right_sum - left_sum + median*( left_set.size() - right_set.size())<<' ';

    for(int i=0;i<n-k;i++){
        // removing old left pointer
        if (!left_set.empty() and left_set.find({arr[i],i})!=left_set.end()){
            left_set.erase({arr[i],i});
            left_sum -= arr[i];
        }
        else{
            right_set.erase({arr[i],i});
            right_sum -= arr[i];
        }

        // adding new right pointer
        if (left_set.size() <= right_set.size()){
            left_sum += arr[i+k];
            left_set.insert({arr[i+k],i+k});
        } else {
            right_sum += arr[i+k];
            right_set.insert({arr[i+k],i+k});
        }

        // for adjustment if left set becomes {1,3} and right becomes {2}
        // we need to make left {1,2} and right {3}

        if (  (*--left_set.end()).first > (*right_set.begin()).first  ){
            // remove the last elem of left_set from left_set and add that to the right
            // consider the order of operations, if you first remove it from left set mind it that you will add some garbage in right set
            right_set.insert(*--left_set.end());
            right_sum += (*--left_set.end()).first;
            left_sum -= (*--left_set.end()).first;
            left_set.erase(*--left_set.end());

            // remove the beginning elem of right_set from right_set and add it to left
            left_set.insert(*right_set.begin());
            left_sum += (*right_set.begin()).first;
            right_sum -= (*right_set.begin()).first;
            right_set.erase(right_set.begin());
        }
        median = (*--left_set.end()).first;
        cout<< right_sum - left_sum + median*( left_set.size() - right_set.size())<<' ';        
    }

    cout<<'\n';
    return 0;
}