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
    ll n; cin>>n;

    ll arr[n]; repeat(i,0,n) cin>>arr[i];
    sort(arr,arr+n);

    ll s = 0;

    repeat(i,0,n){
        if (arr[i]>s and arr[i]!=s+1){
            cout<<s+1<<'\n';
            return 0;
        }
        s+=arr[i];
    }
    cout<<s+1<<'\n';
    return 0;

}