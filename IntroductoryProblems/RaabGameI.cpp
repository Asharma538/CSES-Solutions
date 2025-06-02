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


void phod(){
    ll n,a,b;
    cin>>n>>a>>b;

    int equal_opportunities = n - a - b;
    if (equal_opportunities < 0){
        print(no); return;
    }

    vector<int> seqa(n),seqb(n);
    repeat(i,0,n){
        seqa[i] = n-i;
    }

    int bcard = n;
    repeat(i,0,equal_opportunities){
        seqb[i] = bcard--;
    }
    repeat(i,n-b,n){
        seqb[i] = bcard--;
        if ( seqa[i] >= seqb[i]){
            print(no);
            return;
        }
    }
    repeat(i,equal_opportunities,equal_opportunities+a){
        seqb[i] = bcard--;
        if ( seqa[i] <= seqb[i]){
            print(no);
            return;
        }
    }

    print(yes);
    print_it(seqa)
    print_it(seqb);
    return;
}

int main(){
    ll t;
    cin>>t;
    repeat(_,0,t) phod();
    return 0;
}