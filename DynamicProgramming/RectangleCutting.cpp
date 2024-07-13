// this will be a n*m*max(n/2,m/2) complexity solution, worst case 500**3 < 1s time needed so works

// basically the fact here is to realise that we just need to find the cost minimum for a cut keeping one dimension same
// i.e. either we'll cut alongside length of breadth, never both
// so we can just check previous stages till l/2 and b/2 to get the min cost as after that the states will repeat 


// if l%b!=0 or b%l!=0: dp[i][j] = min(dp[i-k][j]+dp[k][j]+1,dp[i][j-k]+dp[i][k]+1), for all possible k(s)

// if l%b == 0 then ans = l/b - 1 and similar if b%l==0

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m; cin>>n>>m;
    // all possible contraints
    int dp[501][501];

    for(int i=0;i<501;i++) dp[i][0] = 0;
    for(int i=0;i<501;i++) dp[0][i] = 0;
    for(int i=0;i<501;i++) dp[i][i] = 0;

    for(int i=1;i<501;i++){
        for(int j=1;j<501;j++){
            if (i%j==0) dp[i][j] = (i/j)-1;
            else if (j%i==0) dp[i][j] = (j/i)-1;
            else{
                int min_cost = 1e9+7; // can keep it above 2500 too any val above 2500 will work
                for(int k=1;k<=(i+1)/2;k++){
                    min_cost = min(min_cost , dp[i-k][j]+dp[k][j]+1);
                }
                for(int k=1;k<=(j+1)/2;k++){
                    min_cost = min(min_cost , dp[i][j-k]+dp[i][k]+1);
                }
                dp[i][j] = min_cost;
            }
        }
    }
    
    cout<<dp[n][m]<<'\n'; return 0;
}
