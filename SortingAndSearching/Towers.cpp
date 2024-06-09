// we'll find the cube already kept
// which has minimum diff to our present cube we're going to keep
// implies a greedy strategy

// if no cube is bigger than ours
// we'll make a new tower


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    // for maintaining the towers
    // we'll keep just the top cube's dimensions
    multiset<int> m;

    for(int i=0;i<n;i++){
        auto it = m.upper_bound(arr[i]);
        if (it!=m.end()){
            // we've a tower's cube bigger than our cube
            // we'll keep our cube on top of that tower
            m.erase(it);
        }
        // either on the new tower or in the new tower
        m.insert(arr[i]);
    }

    cout<<m.size()<<'\n';
    return 0;
}