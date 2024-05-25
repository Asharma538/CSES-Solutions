// two queens can attack each other if
// their rows are same
// their cols are same
// row+col , of both queens is same
// row-col , of both queens is same

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define repeat(i,s,e) for(int i=s;i<e;i++)

int ans;
set<pair<int,int>> reserved_spots;
set<pair<int,int>> queen_spots;

bool check_sq(int x,int y){

    // if the sq is reserved
    if (reserved_spots.find({x,y})!=reserved_spots.end()) return false;

    // checking if this sq is safe
    for(auto sq: queen_spots){
        if (sq.first==x or sq.second==y or sq.first+sq.second==x+y or sq.first-sq.second==x-y) return false;
    }
    return true;
}

void find_safe_arrangement(int r){
    // r==7 would be the last queen's placement row (since we started with 0)
    if (r==8){
        ans++;
        return;
    }
    
    repeat(c,0,8){
        if (check_sq(r,c)){
            queen_spots.insert({r,c});
            find_safe_arrangement(r+1);
            // removing queen from here, coz we already discovered all possibilities above
            // removing this queen will let us go with this queen on other cols
            queen_spots.erase({r,c});
        }
    }
}

int main(){

    repeat(i,0,8) repeat(j,0,8){
        char c; cin>>c;
        if (c=='*') reserved_spots.insert({i,j}); // adding reserved spot
    }

    // as every row will have only one queen
    // we'll go row by row and then check columns
    find_safe_arrangement(0);
    cout<<ans<<'\n';
    return 0;
}