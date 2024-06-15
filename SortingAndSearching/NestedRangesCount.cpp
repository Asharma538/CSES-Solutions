#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class trint{
    public:
    int v1,v2,v3;
    trint(int val1=0,int val2=0,int val3=0){
        v1=val1;
        v2=val2;
        v3=val3;
    }
};

bool trint_sort(trint a,trint b){
    if (a.v1==b.v1) return a.v2>b.v2;
    return a.v1<b.v1;
}

int main(){
    int n; cin>>n;
    vector<trint> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i].v1>>arr[i].v2;
        arr[i].v3 = i;
    }

    sort(arr.begin(),arr.end(),trint_sort);

    // till here we've done the same thing sorted the ranges
    // but now we'll need to count the ranges within, the no.s in which a range is contained
    // for this we'll use ordered_set's order_of_key function
    // and since end points of a range can be same, we'll use pair as keys
    // ordered_set<key, -pos>
    // but if 
    // 3 6, has occured and 4 6 is coming we need to make sure the 6 before lies ahead in the set
    // for this we'll use - of position

    // let's try it
    ordered_set<pair<int,int>> os;
    vector<pair<int,int>> ans(n);

    // ans[arr[i].v3] for updating on the orig pos
    for(int i=0;i<n;i++){
        // since set keeps things in inc order, we'll have to substract the size to get the ranges bigger than the 
        // one we're considering
        ans[arr[i].v3].first = os.size() - os.order_of_key({arr[i].v2,-i});
        os.insert({arr[i].v2,-i});
    }

    os.clear();

    for(int i=n-1;i>=0;i--){
        // since set keeps things in inc order, we'll have to substract the size to get the ranges bigger than the 
        // one we're considering
        ans[arr[i].v3].second = os.order_of_key({arr[i].v2,-i});
        os.insert({arr[i].v2,-i});
    }

    // like last qn
    for(int i=0;i<n;i++) cout<<ans[i].second<<' '; cout<<endl;
    for(int i=0;i<n;i++) cout<<ans[i].first<<' '; cout<<endl;

    return 0;
}