// in this problem we don't actually need the subsequence that's the longest increasing one
// if we do it with DP it'll have complexity of n**2, then indeed we can find the subsequence as well
// but we're just concerned about the length of the subsequence here 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    // we'll keep a set and then maintain the subsequence there
    // for an example to work on 
    // 8
    // 7 3 5 3 6 2 9 8
    // // we'll go from left to right
    // got 7 -> take 7 -> {7}
    // got 3, replace 7 by 3 -> {3}
    // got 5, add 5 to the set -> {3,5}
    // got 3, we already have it -> continue
    // got 6, add 6 to the set -> {3,5,6}
    // got 2, replace 3 by 2 -> {2,5,6}
    // got 9, add 9 to the set -> {2,5,6,9}
    // got 8, replace 9 by 8 -> {2,5,6,8}

    // now you can see that the actual required subsequence is not this but this is indeed the actual length we wanted
    // we have reached this length because earlier elements have increase the length of the set, means we indeed 
    // have the required elements earlier that are needed for this length

    set<int> s;

    for(int i=0;i<n;i++){
        // we append elem if we have a elem greater than all of the ones in our current set
        if (s.empty() or *(--s.end()) < arr[i]) s.insert(arr[i]);
        // the elem is not already in our set
        else if (s.find(arr[i])==s.end()){
            // replacing the curr index elem with the one greater than it in our set
            s.erase(s.upper_bound(arr[i]));
            s.insert(arr[i]);
        }
    }
    cout<<s.size()<<'\n';
    
    return 0;
}