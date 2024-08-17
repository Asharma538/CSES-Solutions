// what we need here is kruskal algorithm again 
// and we'll keep 2 variables 

// one for number of components
// and one for keeping the max size 
// since the par array contains the size of the component we're in, in negated value 
// thus we will use this info 

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

vector<int> par(100001,-1);

int find(int i){
    if (par[i]>=0) return find(par[i]);
    return i;
}

int main(){
    int n,m; cin>>n>>m;
    int a,b;

    int components = n;
    int mx_size_component = 1;

    repeat(i,0,m){
        cin>>a>>b;
        int pa = find(a);
        int pb = find(b);

        if (pa==pb){
            // if we've again made a road b/w same components 
            cout<<components<<' '<<mx_size_component<<'\n';
            continue;
        }
        if (pa < pb){
            par[pa] += par[pb];
            par[pb] = pa;
            mx_size_component = max(mx_size_component,-par[pa]);
        } else {
            par[pb] += par[pa];
            par[pa] = pb;
            mx_size_component = max(mx_size_component,-par[pb]);
        }
        // since we've connected different components
        components--;
        cout<<components<<' '<<mx_size_component<<'\n';
    }

    return 0;
}