// we'll go with greedy 
// will arrange the array in asc order

// give the size-k value's nearby apartment in order, (following greed)
// this works because now or later the benefit will always be of 1

// i.e. if we give the apartment then we add 1 to ans
// if we save it then too the best we can do later is to add 1 to ans

// hence greed works here

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m,k; cin>>n>>m>>k;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    sort(arr,arr+n); // asc order

    multiset<int> apartments;
    for(int i=0;i<m;i++){
        int a; cin>>a; apartments.insert(a);
    }

    int allocated_apartments = 0;
    for(auto i : arr){
        auto it = apartments.lower_bound(i-k);
        if (it==apartments.end()) continue;
        if (i-k<=*it and *it<=i+k){
            allocated_apartments++;
            // removing that appartment after alloc
            apartments.erase(it);
        }
    }

    cout<<allocated_apartments<<'\n';


    return 0;
}