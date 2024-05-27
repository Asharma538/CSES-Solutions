#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll n;

string int_to_bin(ll i){
    string bin_i="";
    while(i){
        if (i&1) bin_i+="1";
        else bin_i+="0";
        i/=2;
    }
    reverse(bin_i.begin(),bin_i.end());
    string padding = "";
    for(int i=0;i<n-bin_i.length();i++) padding+='0';

    return padding+bin_i;
}

string bin_to_gray(string b){
    string res = "";
    res += b[0];
    for(int i=1;i<b.length();i++){
        if (b[i] != b[i-1]) res+='1';
        else res+='0';
    }
    return res;
}

int main(){
    cin>>n;
    for(ll i=0;i<pow(2,n);i++) cout<<bin_to_gray(int_to_bin(i))<<'\n';
    return 0;
}