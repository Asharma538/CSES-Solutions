// let the number of one type moves be x
// & let the number of one type moves be y

// so total coins in left pile i.e.
// a = 2*x + y, and
// b = x + 2*y

// thus x = (2a - b)/3
// and y = (2a - b)/3

// soln exists if both x nd y are ints and non-negative

#include <iostream>
using namespace std;

#define ll long long

void phod(){
    ll a,b; cin>>a>>b;

    if ((2*a-b)%3==0 and (2*b-a)%3==0 and (2*a-b)>=0 and (2*b-a)>=0)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}

int main(){
    ll t; cin>>t;
    for(ll _=0;_<t;_++) phod();
}