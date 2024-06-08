#include <bits/stdc++.h>
using namespace std;

#define repeat(i,s,e) for(int i=s;i<e;i++)

int main(){
    int n; cin>>n;
    int arr[n]; repeat(i,0,n) cin>>arr[i];

    set<int> s;
    multiset<int> m;

    // we'll check the size of multiset and set if they're same then we've unique songs otherwise we'll remove the prev songs until we get 
    // their sizes same again
    // we'll maintain a left pointer for checking the left song to be removed in case the sizes don't come out to be same

    // start pointer
    int s_i = 0;

    int ans = 0;

    // end pointer will proceed ahead as usual
    repeat(e_i,0,n){
        s.insert(arr[e_i]);
        m.insert(arr[e_i]);

        if (s.size()==m.size()){
            ans = max(ans,(int)s.size());
        }
        else{
            // while we don't remove the same songs
            // we'll contract out sets
            while(arr[s_i]!=arr[e_i]){
                s.erase(arr[s_i]);
                m.erase(arr[s_i]);
                s_i++;
            }
            // for removing just one elem
            // otherwise if we give value to be removed from a multiset
            // it removes all the same values
            m.erase(m.find(arr[s_i++]));
        }
    }

    cout<<ans<<'\n';

    return 0;
}