// to complete this problem again we need to do the euler's tour of the graph and check if we can 
// travel through all the teleporters

// also we need to check if all the middle levels have equal in and out degree
// and 1 and n should have 1 more outdeg and 1 more indeg respectively

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


int main(){
    int n,m; cin>>n>>m;
    vector<set<int>> v(n+1);
    vector<int> indeg(n+1,0);
    vector<int> outdeg(n+1,0);
    repeat(i,0,m){
        int a,b; cin>>a>>b;
        v[a].insert(b);
        outdeg[a]++;
        indeg[b]++;
    }

    // checking degrees 
    repeat(i,2,n){
        if (indeg[i]!=outdeg[i]){
            print("IMPOSSIBLE"); return 0;
        }
    }

    // outdegree of 1 should be 1 more than indegree
    if (indeg[1]!=outdeg[1]-1){
        print("IMPOSSIBLE"); return 0;
    }

    if (indeg[n]-1!=outdeg[n]){
        print("IMPOSSIBLE"); return 0;
    }

    vector<int> ans;

    // euler's tour 
    stack<int> s;
    s.push(1);
    while(s.size()){
        int i = s.top();
        if (v[i].size()){
            int to = *(v[i].begin());
            v[i].erase(v[i].begin());
            s.push(to);
        }
        else {
            ans.push_back(i);
            s.pop();
        }
    }

    // in a directed graph we need to reverse the path 

    // lastly if the size of ans is not m+1 we've not used all teleporters 
    if (ans.size()!=m+1){
        print("IMPOSSIBLE"); return 0;
    }

    reverse(ans.begin(),ans.end());
    print_it(ans);

    
    return 0;
}