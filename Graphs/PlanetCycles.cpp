// what we should first ask is that is it always possible? NOPE 

// because some planets can be in completely disjoint components

// 1. there can be a case when we're going like from c->b->d->a->e
//                                                             ^  |
//                                                             |  |
//                                                             ____ cycle is a->e->a so b cannot be reached 
// so here in this type of case we can never reach b from a 


// 2.we can also have a case like                     c->b->d->f->e<-g<-a
//                                                             ^  |
//                                                             |  |
//                                                             ____
// so in this case too we cannot reach b becuase we will be trapped in a cycle in between a and b


// 3. there can be a case when a->b->c->d->e<-f<-g
//                                      ^  |
//                                      |  |
//                                      ____
// so here we can reach b from a

// so we need to find basically 3 things

// ->DISTANCE OF EACH NODE FROM THE CYCLE
// ->THE CYCLE EACH NODE LEADS TO (OR IT DOES NOT LEAD TO ANY) AND WHAT IS THE SIZE OF THE CYCLE
// ->THE TRAVEL DISTANCE IT TAKES TO REACH FROM A TO B USING BINARY HEIRARCHY LIKE WE DID IN LAST Qn

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


int main(){
    ll n,q; cin>>n;

    vector<ll> teleporters(n);

    vector<vector<ll>> rev_teleporters(n);
    repeat(i,0,n){
        cin>>teleporters[i]; teleporters[i]--;

        rev_teleporters[teleporters[i]].push_back(i);
    }

    vector<ll> cycle_num(n,-2);

    vector<map<ll,ll>> cycles;
    repeat(planet,0,n){
        if (cycle_num[planet]!=-2) continue;

        vector<ll> path;
        path.push_back(planet);

        ll curr_planet = planet;
        while(cycle_num[teleporters[curr_planet]]==-2){
            curr_planet = teleporters[curr_planet];
            cycle_num[curr_planet]=-3;

            path.push_back(curr_planet);
        }

        map<ll,ll> cycle;
        bool in_cycle = false;

        for(auto i : path){
            if (i==teleporters[curr_planet]) in_cycle = true;
            if (in_cycle) cycle[i] = cycle.size();
            cycle_num[i] = in_cycle ? (ll)cycles.size() : -1 ;
        }
        // adding our new cycle 
        cycles.push_back(cycle);
    }


    vector<ll> cyc_dis(n,0);

    repeat(planet,0,n){
        if (cycle_num[teleporters[planet]]==-1 or cycle_num[planet]!=-1) continue;
        stack<pair<ll,ll>> dfs;
        // <planet , cyc_dis_planet>
        dfs.push({planet,1});

        while(dfs.size()){
            ll pl = dfs.top().first;
            ll dis = dfs.top().second;
            cyc_dis[pl] = dis;
            dfs.pop();
            for(auto i : rev_teleporters[pl]) dfs.push({i,dis+1});
        }
    }


    ll LOGN = ceil(log2(n));
    ll heirarchy[n][LOGN+1];
    repeat(i,0,n) heirarchy[i][0] = teleporters[i];

    repeat(j,1,LOGN+1) repeat(i,0,n) heirarchy[i][j] = heirarchy[ heirarchy[i][j-1] ][j-1];

    // now we just need to see if the node is in a cycle 
    // if it is then just print the size of that cycle 
    // otherwise print the size_of_cyle + cyc_dis of that node 

    repeat(p,0,n){
        if (cycle_num[p]!=-1){
            cout<< (ll) cycles[cycle_num[p]].size() <<' ';
        }
        else{
            ll a = p;
            repeat(i,0,LOGN+1) if ( (1<<i) & cyc_dis[p] ) a = heirarchy[a][i];

            cout<<cyc_dis[p] + ( (ll) cycles[cycle_num[a]].size())<<' ';
        }
    }

    

    return 0;
}