// for n numbers to split up into two eq sum groups
// sum needs to be even

// lets check for n%4=1
// 1*(1+1)/2 -> odd

// lets check for n%4=2
// 2*(2+1)/2 -> odd

// lets check for n%4=3
// 3*(3+1)/2 -> even

// lets check for n%4=4
// 4*(4+1)/2 -> even

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main(){

    ll n; cin>>n;

    ll sum = n*(n+1)/2;

    if (sum%2==0){
        cout<<"YES"<<endl;

        set<ll> s1;
        set<ll> s2;

        if (n%4 == 0){
            // n is a multiple of 4
            // we'll have two sets
            // with equal no. of elems
            // 8
            // 1 2 3 4 5 6 7 8
            // take one from start one from last,
            // put in s1
            // take one from start one from last,
            // put in s2
            // so on...
            for(int i=0;i<n/2;i++){
                if(s1.size()==s2.size()){
                    s1.insert(i+1);
                    s1.insert(n-i);
                }
                else{
                    s2.insert(i+1);
                    s2.insert(n-i);
                }
            }
        }
        else{
            // n is 3 % 4...
            // 7
            // 1 2 3 4 5 6 7
            // leave n, consider last elem as n-1
            // with the same strategy...
            // 1 6 3 4 , 2 5 7...
            // put 7 in s2 -> balanced
            n-=1;
            for(int i=0;i<n/2;i++){
                if(s1.size()==s2.size()){
                    s1.insert(i+1);
                    s1.insert(n-i);
                }
                else{
                    s2.insert(i+1);
                    s2.insert(n-i);
                }
            }
            n+=1;
            s2.insert(n);
        }
        cout<<s1.size()<<endl;
        for(auto i: s1) cout<<i<<" "; cout<<endl;
        cout<<s2.size()<<endl;
        for(auto i: s2) cout<<i<<" "; cout<<endl;
    }
    else{ // odd
        cout<<"NO"<<endl;
    }

    return 0;
}