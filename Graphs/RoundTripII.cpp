// there's a small change in round trip 2 from 1 i.e. there's just one way connectivity through flights 
// that was roads previously 

// but here too we need to follow almost the same approach as we did for 1 
// but as there's one way connectivity there can be some issues when a node is already visited and then it is visited again 

// for ex 

// n = 3 , m = 3
// 1 2
// 2 3
// 1 3


// here if we visit 3 using 1->2->3 
// and then we visit three again using 1->3 we can't say there's a cycle as we said in round trip one 
// instead we need to see our dfs stack and tell if the node we're suspecting our cycle on is actually present in the stack or not 

// boilerplate in comments 

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
int vis[100001];
bool inStack[100001];

// we'll print the cycle using dfs itself so let's prepare a bool if we've already given the ans
bool answered = false;

void dfs(int i){
    for(auto j : v[i]){
        if (answered) return;

        if (vis[j]==-1){
            inStack[j] = true;
            vis[j] = i;
            dfs(j);
            inStack[j] = false;
        }
        // else there can be a cycle but let's check stack
        elif (inStack[j]){
            // so the node is visited again in the same dfs path -> cycle
            answered = true;
            stack<int> path;
            path.push(j);
            path.push(i);
            int curr = i;
            while(curr!=j){
                curr = vis[curr];
                path.push(curr);
            }
            print(path.size());
            while(path.size()){
                cout<<path.top()<<' '; path.pop();
            }
            cout<<endl;
            return;
        }
    }
}

int main(){
    int n,m,a,b; cin>>n>>m;

    repeat(i,0,m){
        cin>>a>>b;
        v[a].push_back(b);
    }

    repeat(i,0,n+1) vis[i] = -1;

    // if the node is not visited yet perform a dfs through it 
    repeat(i,1,n+1){
        if (vis[i]==-1){
            inStack[i]=true;
            vis[i] = i;
            dfs(i);
            if (answered) break;
            inStack[i]=false;
        }
    }

    if (!answered) print("IMPOSSIBLE");
    return 0;
}