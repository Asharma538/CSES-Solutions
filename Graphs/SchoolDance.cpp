// we need to find and make the maximum number of pairs possible 

// for this we can match a boy to the girl which falls earlier in his adjacency list 

// and if during this matching if any boy is unable to find a girl, we can backtrack our matching and 
// check if the boy who's currently matched to some girl, can find another girl 

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

vector<vector<int>> v(501);

// checks if we've matched the i-th girl to some boy or not 
vector<bool> vis(501,false);

// keeps the matching for the i-th girl as matching[i]-th boy 
vector<int> matching(501,0);

bool match_possible(int boy){
    for(auto girl : v[boy]){
        // if any girl is unmatched 
        if (!matching[girl]){
            matching[girl] = boy;
            return true;
        }
        
        elif (!vis[girl]){
            // but since we've to mark this girl as visited because it'll be reserved for current boy 
            vis[girl] = true;
            
            // we need to find some other matching 
            // if we can assign the current partner of this girl to some other girl 
            if (match_possible(matching[girl])){
                matching[girl] = boy;
                return true;
            }
        }
    }
    return false;
}

int main(){
    int n,m,p,a,b; cin>>n>>m>>p;
    repeat(i,0,p){
        cin>>a>>b;
        v[a].push_back(b);
    }

    int ans = 0;
    repeat(boy,1,n+1){
        // for each traversal we need to re-init our vis 
        repeat(_,0,501) vis[_] = false;
        if (match_possible(boy)){
            ans++;
        }
    }

    print(ans);
    repeat(i,1,m+1) if (matching[i]) cout<<matching[i]<<' '<<i<<'\n';

    return 0;
}