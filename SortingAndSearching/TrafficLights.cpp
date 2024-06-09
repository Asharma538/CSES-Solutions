// we'll maintain a set, in which we'll keep all the positions of the street lights (including borders i.e. 0 and x)

// we'll maintain a multiset for keeping the distances between the street lights

// for any new street light, we'll get the ones before and ahead of it, then we'll get the distance between them
// remove this distance from the multiset
// insert two new distances made by adding this street light
// and add the position of the street light to our set

// everytime we'll print the max elem of the multiset

#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,n; cin>>x>>n;
    int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    set<int> s; // for positions
    s.insert(0);
    s.insert(x);

    multiset<int> m; // for distances
    m.insert(x);

    for(int i=0;i<n;i++){
        auto bef_it = (--s.lower_bound(arr[i])); // for getting elem before the key
        auto ahead_it = (s.upper_bound(arr[i])); // for getting elem ahead of the key

        m.erase(m.find((*ahead_it)-(*bef_it))); // removing the bigger distance in which the light is added

        m.insert((*ahead_it) - arr[i]); // adding dist 1
        m.insert(arr[i] - (*bef_it)); // adding dist 2

        s.insert(arr[i]); // adding pos of street light

        cout<<*(--m.end())<<' '; // 
    }
    cout<<endl;

    return 0;
}