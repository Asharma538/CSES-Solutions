// so what we need here is to maintain that which node will lead to which node 
// but doing this for each k from 0 to 1e9 is too much 

// so we know that we can represent k in binary with 30 character 

// so why not think on that line?

// if we've a planet to start and we've the next planet we'll go to 
// then by knowing the next->next planet is same as knowing our ans for k=2
// for knowing our ans for k=2 and ans for k=2 for next->next node will serve as a ans for k=4 for current planet 

// so this will get clear with code more lezzgo 

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
    // using fast io 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; cin>>n>>q;
    
    // maintaining the track of our planets that we'll reach 
    int heirarchy[n][30];
    repeat(i,0,n){
        // we're just having our next planet for 0 case 
        cin>>heirarchy[i][0];
        // making it 0-based indexing 
        heirarchy[i][0]--;
    }

    // making the remaining heirarchy 
    repeat(j,1,30){
        repeat(i,0,n){
            // making our 2^(i+1)th ans using our 2^i ans and 2^i ans's 2^i ans 
            heirarchy[i][j] = heirarchy[ heirarchy[i][j-1] ][j-1];
        }
    }

    repeat(i,0,q){
        int x,k; cin>>x>>k;
        int ans = --x;
        repeat(p,0,30){
            if ( (1<<p) & k ){ //if we've a 1 in p-th position let's move to our that result
                ans = heirarchy[ans][p];
            }
        }
        cout<<++ans<<'\n';
    }

    return 0;
}