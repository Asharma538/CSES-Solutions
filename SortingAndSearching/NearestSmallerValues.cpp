// we'll go left to right finding ans

// so for any index i if we need an answer
// we'll see all the elems present in left of i

// if in the left we've two comparable elems say a and b
// index(b) > index(a)
// b<=a, then we can say for sure that a can't be an answer as b is near to i and b<=a too
// so for elems going ahead after i too we've only b in our consideration

// thus we'll keep only b and drop all such a(s)

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n; cin>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    // i'll use stack for storing b(s) and removing a(s)
    // pair { b , index(b) }
    stack<pair<int,int>> s;

    // ans array
    int ans[n];

    for(int i=0;i<n;i++){
        // if we get a new b, comparing it to old b(s)
        while( s.size() and s.top().first >= arr[i] ) s.pop();

        if (s.empty()) ans[i] = 0;
        else ans[i] = s.top().second;

        // since all elements now are lesser than our new-b we need to push our new-b too if in case that can be an answer for elems ahead
        s.push({arr[i],i+1});
    }

    for(int i=0;i<n;i++) cout<<ans[i]<<' '; cout<<'\n';
    return 0;
}