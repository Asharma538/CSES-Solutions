// so we'll use BELLMAN FORD for this 
// but yet to print the cycle it will not be enough 

// as if there are multiple cycles how will we ensure we're in one cycle only 

// and also the changes that the cycle brings to the graph will propagate its effects 

// so even if one node if it is not a part of the cycle its distance can change 


// so to tackel this we'll use parent array (the par node will be the one who is sending changes)
// then we'll run bellman ford again to find all the parents 

// then we'll backtrack our path then print the cycle 

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

class edge{
    public:
    ll src,dst,weight;
    edge(ll a=0,ll b=0,ll c=0){
        src = a; dst = b; weight = c;
    }
};

int main(){
    ll n,m,a,b,c;
    cin>>n>>m;

    vector<edge> edges(m);

    repeat(i,0,m){
        cin>>a>>b>>c;
        --a,--b;
        edges[i].src = a; edges[i].dst = b; edges[i].weight = c;
    }

    // for bellman ford
    vector<ll> dis(n,1e18);
    dis[0] = 0;
    repeat(i,0,n-1){
        for(auto e : edges){
            if ( dis[e.dst] > dis[e.src]+e.weight ){
                dis[e.dst] = dis[e.src]+e.weight;
            }
        }
    }

    // if the "if" block runs after n-1 times, there's a cycle 
    bool cycle_exists = false;
    for(auto e : edges){
        if ( dis[e.dst] > dis[e.src]+e.weight ){
            cycle_exists = true;
            break;
        }
    }

    if (!cycle_exists){
        print(no);
    }
    else{
        print(yes);
        // making the par array 
        vector<ll> par(n,-1);
        ll st = -1;

        // we need to get all the propagation done 
        repeat(i,0,n){
            for(auto e : edges){
                if ( dis[e.dst] > dis[e.src]+e.weight ){
                    dis[e.dst] = dis[e.src]+e.weight;
                    par[e.dst] = e.src;
                    st = e.dst;
                }
            }
        }

        // it can be a case that e.dst is not in cycle, so to bring the "st" var back in cycle 
        // we'll go back n times, in the par array 
        repeat(i,0,n) st = par[st];


        ll curr = st;
        // tracking the cycle
        stack<ll> cycle;
        do
        {
            cycle.push(curr+1); // making it one indexed
            curr = par[curr];
        } while (st!=curr);
        cycle.push(curr+1);
        while(cycle.size()){
            cout<<cycle.top()<<' ';
            cycle.pop();
        }
    }

    return 0;
}