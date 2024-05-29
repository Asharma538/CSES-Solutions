#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;

    multiset<int> tickets;

    for(int i=0;i<n;i++){
        int a; cin>>a;
        tickets.insert(a);
    }

    int arr[m]; for(int i=0;i<m;i++) cin>>arr[i];


    // in order customers arrive
    for(auto i: arr){
        // less than or equal to the price announced;
        // lower bound of a set gives elem >= the key
        // --lower bound will definitely be < key

        // upper bound gives elem > key
        // --upper bound gives elem <= key

        auto it = tickets.upper_bound(i);
        if (it==tickets.begin()){
            cout<<-1<<'\n';
        }
        else{
            --it;
            cout<<*(it)<<'\n';
            tickets.erase(it);
        }
    }



    return 0;
}