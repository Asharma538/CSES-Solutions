// making a freq map
// if all the chars have even freq,
// with at most one char as odd -> POSSIBLE
// else no

#include <bits/stdc++.h>
using namespace std;

int main(){
    string s; cin>>s;

    map<char,int> m;

    for(auto i : s) m[i]++;

    string ans,ans_rev,mid_char="-";

    for(auto i: m){
        if (i.second%2){
            if (mid_char!="-"){
                cout<<"NO SOLUTION\n";
                return 0;
            }
            mid_char = i.first;
        }
        for(int j=0;j<i.second/2;j++){
            ans += i.first;
            ans_rev += i.first;
        }
    }

    reverse(ans_rev.begin(),ans_rev.end());

    if (mid_char=="-"){
        cout<<ans<<ans_rev;
    }
    else{
        cout<<ans<<mid_char<<ans_rev;
    }

    return 0;

}