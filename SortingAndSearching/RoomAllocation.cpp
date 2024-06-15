// we'll keep a set representing a hotel
// hotel will contain pairs of < dept_time , room_number >
// we'll search if any key in the hotel is lesser than < arr_time , 0 >, this will give us the details
// if there's a key less than our key < arr_time , 0 > it'll imply that this key's room is empty
// we'll remove it from hotel and give our new guest this room

// if no key is less that'll imply that we need a new room so we'll add it
// ofc we'll do all of this after sorting 

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    // arr_time , dept_time , original_pos to be used as we'll sort the arr
    vector<pair<pair<int,int>,int>> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i].first.first>>arr[i].first.second;
    for(int i=0;i<n;i++) arr[i].second = i;
    
    sort(arr.begin(),arr.end());

    set<pair<int,int>> hotel;
    int room_allocation[n];
    int max_rooms = 0;

    

    for(int i=0;i<n;i++){
        auto it = hotel.lower_bound({ arr[i].first.first , 0 });
        if (it == hotel.begin()){ // no key is less
            room_allocation[arr[i].second] = hotel.size()+1;
            hotel.insert( {arr[i].first.second , hotel.size()+1} );
        } else {
            --it; // getting the lesser key
            room_allocation[arr[i].second] = (*it).second; // assigning that room of the key
            hotel.insert( { arr[i].first.second , (*it).second } );
            // removing the key
            hotel.erase( it );
        }
        max_rooms = max( max_rooms , (int) hotel.size() );
    }

    cout<<max_rooms<<'\n';
    for(int i=0;i<n;i++) cout<<room_allocation[i]<<' '; cout<<endl;

    return 0;
}