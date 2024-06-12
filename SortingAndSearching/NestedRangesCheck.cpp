// for checking if the range lies in some other range

    // we'll arrange the ranges in inc order

    // i.e. earlier the start , closer it remains to the start of the arr

    // let's take an example to solve

    // pair<int,int> arr
    // first second
    // 1 2
    // 2 5
    // 2 4
    // 3 3

    // ans should be
    // contains another range?
    // 0 1 1 0

    // contained in a range?
    // 0 0 1 1


    // sorting ranges
    // 1 2
    // 2 4
    // 2 5
    // 3 3

    // we'll keep a right pointer which will represent the max distance a range has covered to the right

    // for this case we can see 
    // if i=0, right_ptr = 2
    // if i=1, right_ptr = 4
    // if i=2, right_ptr = 5
    // if i=3, right_ptr = 5,  here if the right pointer remains greater than arr[i].second then we'll say an upper range contains it

    // but since 2 5 , can cover 2 4, it needs to be before 2 4, as it can cover 2 4

    // implies we'll arrange ranges in inc order of start( or first ) and if first is equal, then dec order of end (or second)

    // but after sorting we need to re arrange the answers with respect to the original positions
    // for this we'll keep a third index which will tell the position

// for checking if a range contains another range

    // we'll come from last index to first index
    // and keep a minimum pointer indicating the minimum point at which a range has ended

    // this will tell if the ranges towards 0-th index can contain any range ahead of'em


#include <bits/stdc++.h>
using namespace std;

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
    if (a.v1==b.v1) return a.v2 > b.v2; // dec of end
    return a.v1 < b.v1; // inc of start
}

int main(){
    int n; cin>>n;
    vector<trint> arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i].v1>>arr[i].v2;
        arr[i].v3 = i;
    }

    sort(arr.begin(),arr.end(),trint_sort);

    vector<pair<int,int>> ans(n);


    // ans[arr[i].v3], will update the ans at the original position
    
    int right_ptr = 0;
    for(int i=0;i<n;i++){
        if (arr[i].v2 <= right_ptr ) // if is contained
            ans[arr[i].v3].first = 1;
        else
            ans[arr[i].v3].first = 0;
        right_ptr = max(right_ptr,arr[i].v2);
    }

    int min_ptr = 1e9+1;
    for(int i=n-1;i>=0;i--){
        if (arr[i].v2 >= min_ptr) // if can contain a range
            ans[arr[i].v3].second = 1;
        else
            ans[arr[i].v3].second = 0;
        min_ptr = min(min_ptr , arr[i].v2);
    }

    for(int i=0;i<n;i++) cout<<ans[i].second<<' '; cout<<'\n';
    for(int i=0;i<n;i++) cout<<ans[i].first<<' '; cout<<'\n';

    return 0;
}