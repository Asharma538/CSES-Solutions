#include <bits/stdc++.h>
using namespace std;

int main(){
    // input
    int n,m; cin>>n>>m;

    // 2 for borders around the array
    vector<int> arr(n+2);
    arr[0]=0; arr[n+1]=n+1;

    // input
    for(int i=1;i<n+1;i++) cin>>arr[i];
    

    // swapping queries
    vector<pair<int,int>> qrs(m);

    // input
    for(int i=0;i<m;i++) cin>>qrs[i].first>>qrs[i].second;
    
    // making a sorted arr which keeps the numbers in order
    // each elem is {i,pos_i}
    vector<pair<int,int>> sorted_arr(n+2);

    for(int i=0;i<n+2;i++){
        sorted_arr[i]={arr[i],i};
    }
    
    // sorting the arr gives us the way to calculate the rounds needed
    sort(sorted_arr.begin(),sorted_arr.end());

    // solution of collecting numbers 1, ans contains the no. of rounds needed
    int ans=1;
    for(int i=1;i<n+2;i++) if (sorted_arr[i-1].second>sorted_arr[i].second) ans++;

    // for all swapping queries    
    for(int j=0;j<m;j++){
        // no.s whose positions need to be changed
        int x = arr[qrs[j].first];
        int y = arr[qrs[j].second];

        // swapping elems of the original arr
        swap(arr[qrs[j].first],arr[qrs[j].second]);

        // the only things we need to check before swapping
        // is x-1,x,x+1 and y-1,y,y+1

        // pairs of inversions can be (x-1,x),(x,x+1),(y-1,y),(y,y+1)
        // if x and y are adjacent, then we'll have even lesser pairs to consider

        // thus we'll remove the effect of these pairs on the ans
        // then we'll swap the elements' positions
        // then we'll add the effect (if any) of these pairs on the ans

        
        // if x,y are adjacent
        if (abs(x-y)==1){
            if (x>y){
                swap(x,y);
            }

            // removing contribution of old positions
            if (sorted_arr[x-1].second > sorted_arr[x].second) ans--;
            if (sorted_arr[y].second > sorted_arr[y+1].second) ans--;

            // considering the effect of the (x,y) pair
            if (sorted_arr[x].second < sorted_arr[y].second) ans++;
            else ans--;

            // swapping the elements' positions
            int temp = sorted_arr[x].second;
            sorted_arr[x].second = sorted_arr[y].second;
            sorted_arr[y].second = temp;

            // counting contribution of new positions
            if (sorted_arr[x-1].second > sorted_arr[x].second) ans++;
            if (sorted_arr[y].second > sorted_arr[y+1].second) ans++;

        }
        else{
            // removing contribution of old positions
            if (sorted_arr[x-1].second>sorted_arr[x].second) ans--;
            if (sorted_arr[x].second>sorted_arr[x+1].second) ans--;
            
            if (sorted_arr[y-1].second>sorted_arr[y].second) ans--;
            if (sorted_arr[y].second>sorted_arr[y+1].second) ans--;

            // swapping the elements' positions
            int temp = sorted_arr[x].second;
            sorted_arr[x].second = sorted_arr[y].second;
            sorted_arr[y].second = temp;

            // counting contribution of new positions
            if (sorted_arr[x-1].second>sorted_arr[x].second) ans++;
            if (sorted_arr[x].second>sorted_arr[x+1].second) ans++;

            if (sorted_arr[y-1].second>sorted_arr[y].second) ans++;
            if (sorted_arr[y].second>sorted_arr[y+1].second) ans++;

        }
        cout<<ans<<'\n';
    }
    return 0;

}