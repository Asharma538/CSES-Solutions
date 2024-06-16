// we'll see if the maximum time taking book (max_elem) 
// can be read in a time less than the time it takes to read all the other ones

// i.e. if (sum of all books - max_elem) >= max_elem: then it is possible to read all of the books in 
// sum of all books amount of time

// it is because by the time one finished the max_elme it is clearly possible that the other guy will
// complete atleast 1 book then the reader of the max_elem can read than, indeed the readers will be able to read
// all the books in the sum of all books time

// else: it'll take 2*max_elem time obviously

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){
    ll n; cin>>n;
    ll arr[n]; for(int i=0;i<n;i++) cin>>arr[i];

    ll max_elem = -1;
    ll sum = 0;
    for(int i=0;i<n;i++){
        sum += arr[i];
        max_elem = max(max_elem , arr[i]);
    }

    if (sum-max_elem >= max_elem){
        cout<<sum<<'\n';
    }
    else{
        cout<<max_elem*2<<'\n';
    }

    return 0;
}