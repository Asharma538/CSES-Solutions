#include <bits/stdc++.h>
using namespace std;
 
int main(){
    string s;
    cin>>s;
    int mx = 1;
    for(int i=0;i<s.length();i++){
        int c=1;
        while( i+1<s.length() and s[i]==s[i+1]){
            c++,i++;
        }
        mx = max(mx,c);
    }
    cout<<mx;
}