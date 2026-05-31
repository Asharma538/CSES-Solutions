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
    ll arr[n];
    repeat(i,0,n) cin>>arr[i];
    
    multiset<ll> ms;
    vector<ll> parts, sparts;

    ll j = 0;
    ll prev_i = -1;
    for(ll i=0; i<n; i++){
        if (ms.find(arr[i]) != ms.end()){
            parts.push_back(i-j);
            // cout<<"j="<<j<<" prev_i="<<prev_i-1<<" i="<<i-1<<'\n';
            // cout<<"------------->"<<arr[j]<<' '<<arr[prev_i-1]<<' '<<arr[i-1]<<'\n';
            if (prev_i > j){
                sparts.push_back(prev_i-j);
            }
            prev_i = i;

            while (ms.find(arr[i]) != ms.end()){
                ms.erase(ms.find(arr[j]));
                j++;
            }
        }
        ms.insert(arr[i]);
        // cout<<"multiset: ";
        // print_it(ms);
    }
    // cout<<"j="<<j<<" prev_i="<<prev_i-1<<" i="<<n-1<<'\n';
    // cout<<"-->"<<arr[j]<<' '<<arr[prev_i-1]<<' '<<arr[n-1]<<'\n';
    if (prev_i > j) sparts.push_back(prev_i - j);
    parts.push_back(n-j);

    // print("parts:");
    // print_it(parts);
    ll sm = 0;
    for(ll i : parts){
        sm += (i*(i-1))/2;
    }
    // print("sparts:");
    // print_it(sparts);
    for(ll j : sparts){
        sm -= (j*(j-1))/2;
    }
    // print("sum:");
    print(sm+n);
    return 0;
}