#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
    // we'll not use LL here since it'll complicate the solution and maybe not even work
    // we'll use find_by_order method of the ordered sets which can find the i-th elem by order
    // for which we need ordered sets from the pbds lib
    int n,k; cin>>n>>k;
    ordered_set<int> s;

    for (int i = 0; i < n; i++) s.insert(i+1);

    int i=0;
    while(s.size()){ // the circle exists
        i += k; // moving ahead by k children
        i %= s.size(); // finding the child in circle

        auto it = s.find_by_order(i);
        cout<<*it<<' ';
        s.erase(it);
    }
    cout<<endl;
    return 0;
    

}