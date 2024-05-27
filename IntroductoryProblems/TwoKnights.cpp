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


void phod(ll n){
    if (n==1){
        cout<<0<<"\n";
        return;
    }
    elif(n==2){
        cout<<6<<"\n";
        return;
    }
    elif(n==3){
        cout<<28<<"\n";
        return;
    }
    elif(n==4){
        cout<<96<<"\n";
        return;
    }
    elif(n==5){
        cout<<252<<"\n";
        return;
    }
    // 0 1 2 2 1 0
    // 1 3 4 4 3 1
    // 2 4 5 5 4 2
    // 2 4 5 5 4 2
    // 1 3 4 4 3 1
    // 0 1 2 2 1 0

    // all possibilities
    ll ans = (n*n*(n*n-1))/2;
    // 0
    ans -= (1*4*2)/2;
    // 1
    ans -= (2*4*3)/2;
    // 2
    ans -= (4*4)/2;
    // 3
    ans -= ((n-4)*4*4)/2;
    // 4
    ans -= ((n-4)*6*4)/2;
    // 5
    ans -= (8*(n-4)*(n-4))/2;

    print(ans);
    return;
}

int main(){
    ll t;
    cin>>t;
    repeat(_,1,t+1) phod(_);
    return 0;
}