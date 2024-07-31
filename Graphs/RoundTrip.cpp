// we just need a dfs and then we'll check that we're able to see a visited node again 
// being in a dfs it should be clear that we'll always arrive to the head of the cycle if we're seeing that node again

// we'll use vis array to keep the parent of the current node for tracking down the cycle path 

// boilerplate is in comments

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

vector<vector<int>> v(100001);
int vis[100001]; // for keeping node's parent
bool cycle = false; // init of checking if we've got a cycle
int st_of_cycle = -1;

void dfs(int i,int par){
    vis[i] = par;
    for(auto neighbour : v[i]){
        if (!cycle and neighbour!=par){ // if we don't have a cycle yet
            if (vis[neighbour]==-1){
                dfs(neighbour,i);
            } else {
                vis[neighbour] = i; // making the cyclic loop
                cycle = true;
                st_of_cycle = neighbour;
                return;
            }
        }
    }
}

int main(){
    int n,m,a,b; cin>>n>>m;
    repeat(i,0,n+1) vis[i]=-1;
    repeat(i,0,m){
        cin>>a>>b;
        v[a].push_back(b); v[b].push_back(a);
    }

    repeat(i,1,n+1){
        if (vis[i]==-1){
            dfs(i,i); // that node itself is the start so until we find a cycle let this be the init
        }
    }

    if (cycle){
        queue<int> path; // you can use stack as well we just need the cycle
        int curr = st_of_cycle;
        path.push(curr);
        do
        {
            curr = vis[curr];
            path.push(curr);
        } while (curr!=st_of_cycle);

        print(path.size());
        while(path.size()){
            cout<<path.front()<<' ';
            path.pop();
        }
    }
    else{
        print("IMPOSSIBLE");
    }

    return 0;
}