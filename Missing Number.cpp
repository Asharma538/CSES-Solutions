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
    // sum of all n numbers 
    ll n;
    cin>>n;
    ll sum = (n*(n+1))/2;
    ll sum_provided = 0;
    for(int i=0;i<n-1;i++){
        int a; cin>>a;
        sum_provided += a;
    }
    cout<<sum - sum_provided;
    return 0;
}