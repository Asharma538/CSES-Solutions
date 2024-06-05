#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    // we'll store the elem,pos in the arr
    pair<int,int> arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i;
    }
    // by this we'll get the elems in sorted order
    // for ex
    // 1 2 3 5 4 6
    // after considering pos and sorting
    // arr = {1,0} {2,1} {3,2} {4,4} {5,3} {6,5}
    // if the second index is > that of the prev elem we'll pick them in the same round
    // otherwise we'll pick them in next round
    sort(arr,arr+n);

    int rounds = 1;
    for(int i=1;i<n;i++){
        if (arr[i].second>arr[i-1].second){
            continue;
        }
        else{
            rounds++;
        }
    }
    cout<<rounds<<'\n';
    return 0;

}