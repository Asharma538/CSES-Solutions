// we'll use an ordered set in this qn to get to know the key with the (k-1)/2 th order (median)
// as there can be multiple elems with same val
// we'll use pair<elem,index> in our set

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    int n,k; cin>>n>>k;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    ordered_set<pair<int,int>> s;

    // for building up the set
    for(int i=0;i<k;i++) s.insert({arr[i],i});

    // printing the first median
    cout<<(*s.find_by_order((k-1)/2)).first<<' ';

    for(int i=0;i<n-k;i++){
        // remove the left pointer
        s.erase(s.find({arr[i],i}));

        // insert new right pointer
        s.insert({arr[i+k],i+k});

        cout<<(*s.find_by_order((k-1)/2)).first<<' ';
    }

    cout<<'\n';
    return 0;
}