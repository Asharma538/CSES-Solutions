#include <bits/stdc++.h>
using namespace std;


//Getting faster
#define repeat(i,s,e) for(long long i=s;i<e;i++)
#define reveat(i,s,e) for(long long i=s;i>e;i--)
#define elif else if
#define print(s) cout<<(s)<<endl
#define ll long long
#define append push_back
#define print_it(s) for(auto i : s) cout<<i<<" ";cout<<endl;


//Debugging functions
void print_2darr(auto n,auto m,auto **arr){ repeat(i,0,n){repeat(j,0,m) cout<<arr[i][j]<<' ';cout<<endl;}}
void print_1darr(auto n,auto arr[]){ repeat(i,0,n) cout<<arr[i]<<' ';cout<<endl;}


//Variables
string yes = "YES";
string no = "NO";

set<pair<int,int>> reserved_spots;
set<pair<int,int>> queen_spots;
int ans;

bool sq_is_free(int x,int y){
    
    if (reserved_spots.find({x,y})!=reserved_spots.end()) return false;

    for(auto sq: queen_spots)
        if (
            (sq.first+sq.second == x+y) or 
            (sq.first-sq.second==x-y) or 
            (sq.first==x) or 
            (sq.second==y)
        ) return false;
    
    return true;
}

void find_next_queen_spot(int r){
    if (queen_spots.size()==8){
        // for(auto i: queen_spots) cout<<i.first<<','<<i.second<<" | "; cout<<endl;
        ans++; return;
    }
    if (r==8) return;
    repeat(i,0,8){
        if (sq_is_free(r,i)){
            queen_spots.insert({r,i});
            find_next_queen_spot(r+1);
            queen_spots.erase({r,i});
        }
    }
}

int main(){
    reserved_spots.clear();
    ans = 0;
    queen_spots.clear();
    
    repeat(i,0,8) repeat(j,0,8){
        char c; cin>>c;
        if (c=='*') reserved_spots.insert({i,j});
    }

    find_next_queen_spot(0);
    cout<<ans<<'\n';
    return 0;
}