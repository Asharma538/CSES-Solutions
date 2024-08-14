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
    // input 
    ll n,q; cin>>n>>q;

    // teleporters that we've got already 
    vector<ll> teleporters(n);

    // to track back the distance we need the reverse graph as well 
    vector<vector<ll>> rev_teleporters(n);
    repeat(i,0,n){
        // making everything 0-indexed 
        cin>>teleporters[i]; teleporters[i]--;
        
        // making reverse graph 
        rev_teleporters[teleporters[i]].push_back(i);
    }
    
    // giving a number to each node's cycle, if it is not a part of the cycle it'll have -1 otherwise the id of cycle 
    // -2 means it is not yet alloted anything 
    vector<ll> cycle_num(n,-2);

    // this will contain all the cycles, every cycle is a map, which contains in what order the cyclic nodes are visited 
    // means for a cycle 
    // a -> 0
    // b -> 1
    // c -> 2 
    // this gives us a graph with cycle: 
    // a->b->c->a 
    vector<map<ll,ll>> cycles;

    // finding cycle for each node 
    repeat(planet,0,n){
        if (cycle_num[planet]!=-2) continue;

        // path from the node to the cycle which eventually will stop once we reach the start of the cycle again 
        // or the same node again 

        vector<ll> path;
        path.push_back(planet);

        ll curr_planet = planet;
        while(cycle_num[teleporters[curr_planet]]==-2){
            curr_planet = teleporters[curr_planet];

            // -3 marks that we've visited this planet in our path once 
            // so that we can break our loop 
            cycle_num[curr_planet]=-3;

            path.push_back(curr_planet);
        }
        

        map<ll,ll> cycle;

        // this variable represents whether we are in cycle or not 
        bool in_cycle = false;

        for(auto i : path){
            // if we are at the start of a cycle of we're already in a cycle 
            if (i==teleporters[curr_planet]) in_cycle = true;
            
            // cycle.size will give the order to the nodes in cycle 
            if (in_cycle) cycle[i] = cycle.size();
            // if the node is in cycle it will get the id for the cycle otherwise -1
            cycle_num[i] = in_cycle ? (ll)cycles.size() : -1 ;
        }
        // adding our new cycle 
        cycles.push_back(cycle);
    }

    // dis of a node from the cycle it'll lead to 
    vector<ll> cyc_dis(n,0);

    repeat(planet,0,n){
        // if it is in a cycle the cyc_dis remains 0 
        // just see the condition, it only leaves all nodes that are on the border of the cycle 
        // i.e. if the cycle is like 
        // s -> x -> y -> z -> w -> y 
        // then s,y,z,w will not be left 
        // only x will survive because we only know the distance of x from the cycle and it is 1
        // so from x we can go back in our reverse graph and give the distance to nodes like s 
        if (cycle_num[teleporters[planet]]==-1 or cycle_num[planet]!=-1) continue;

        // giving distances by just traversing the set of nodes which go to the cycle, in reverse order 
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

    // making the heirarchy 
    ll LOGN = ceil(log2(n));
    ll heirarchy[n][LOGN+1];
    repeat(i,0,n) heirarchy[i][0] = teleporters[i];

    repeat(j,1,LOGN+1) repeat(i,0,n) heirarchy[i][j] = heirarchy[ heirarchy[i][j-1] ][j-1];


    ll a,b; 
    repeat(qu,0,q){
        // taking the query 
        cin>>a>>b; --a,--b;

        // if both a and b are in disjoint components
        if (cycle_num[ heirarchy[a][LOGN] ] != cycle_num[ heirarchy[b][LOGN] ] ){
            print(-1); continue;
        }
        // if a is in a cycle but b is outside the cycle 
        if (cycle_num[b]==-1 and cycle_num[a]!=-1){
            print(-1); continue;
        }
        // if "a is leading to the same cycle" and "b is in cycle" and ofc they're in same because we'll then only reach this condition 
        if (cycle_num[a]!=-1 or cycle_num[b]!=-1){
            
            // reaching the cycle from a
            ll dis = cyc_dis[a];
            repeat(i,0,LOGN+1) if (dis & (1<<i)) a = heirarchy[a][i];

            // then reaching b from the point where a's path joins the cycle 
            map<ll,ll> &cyc = cycles[cycle_num[a]];
            ll ai = cyc[a],bi = cyc[b];

            // just substract the distance order and print it 
            print( ((bi-ai+cyc.size())%(cyc.size())) + dis );

        } else {
            // else 
            // when both are not in cycles but they can be in a path leading to the same cycle 
            // if a finds b along the way it is fine 
            // but if b is at a greater distance from the cycle than a -> -1
            if (cyc_dis[b]>cyc_dis[a]){
                print(-1); continue;
            }
            // that means b can be found in the way 
            // travelling the distance between and checking if we've reached b
            ll dis = cyc_dis[a] - cyc_dis[b];
            repeat(i,0,LOGN+1) if (dis & (1<<i)) a = heirarchy[a][i];
            if (a==b) print(dis);
            else print(-1);
        }

    }
    return 0;
}