// simple edit strings problem of DP
// dp[i][j] = dp[i-1][j-1], if string_1[i]==string_2[j]
// dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1), otherwise

#include <bits/stdc++.h>
using namespace std;

#define repeat(i,s,e) for(int i=s;i<e;i++)

int main(){
    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();

    int dp[n+1][m+1];

    repeat(i,0,n+1) repeat(j,0,m+1) dp[i][j] = 0;
    

    repeat(i,0,n+1){
        repeat(j,0,m+1){
            if (i==0 or j==0){
                // we just have to add all chars to the empty string
                dp[i][j] = max(i,j);
                continue;
            }
            // a[i-1] because we're ahead by 1 index
            if (a[i-1]==b[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                // min costly option from add 1 char to a, add 1 char to b, replace 1 char of any 1 of them
                dp[i][j] = min({dp[i-1][j]+1,dp[i][j-1]+1,dp[i-1][j-1]+1});
            }
        }
    }

    cout<<dp[n][m]<<'\n';
    return 0;
}