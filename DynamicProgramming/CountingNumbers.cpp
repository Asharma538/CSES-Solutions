// this is a digit dp question
// here we normally have 4 dimensions in dp

// DP table:
// digits , last_digit ( can change in other questions here we need last_digit) , leading_zeros , tight

// digits: number of digits in our number
// last_digit: the digit to the left of curr_digit
// leading_zeros: whther or not we're still having leading zeros
// tight: are we on the bound by our number

// we'll break the ans in two parts as ans[b,a] = ans[b,0] - ans[a-1,0]

// so we will solve first for b,0 then subtract a-1,0 from it

#include <bits/stdc++.h>
using namespace std;

#define ll long long

// we need 20 digit numbers at max (19 though), (0-9 -> 10), leading_zeros and tight as bool 0-1
ll dp[20][10][2][2];

ll phod( string n , ll digits , ll prev_digit , bool leading_zeros , bool tight ){
    // we've followed all constraints and reached the end
    if (digits==0) return 1;
    // if we're not tight that means we've already had a number which makes us free
    // example n = 12356
    // and we've got till now 122_,_ so the remaining two numbers aren't tight they are free
    // if we've got till now 123_,_ so the next number is tight
    ll max_digit = tight ? ( n[ n.length() - digits ] - '0')  : 9;

    ll ans = 0;

    if (dp[digits][prev_digit][leading_zeros][tight]!=-1) return dp[digits][prev_digit][leading_zeros][tight];

    // we can choose any digit from 0 to max_digit
    for(ll d = 0;d<=max_digit;d++){
        // we should not have leading zeros and prev digit == d
        if ( (d==prev_digit) and !leading_zeros ) continue;
        ans += phod(
            n, // number remains the same
            digits-1, // less digits to choose
            d, // we've got d at this position
            leading_zeros & (d==0), // if we already haven't this started number and again putting 0
            tight & (d == max_digit) // if d==max_digit it'll again make the next digit tight, but only if we're already tight
        );
    }
    return dp[digits][prev_digit][leading_zeros][tight] = ans;
}

int main(){
    ll a,b; cin>>a>>b;
    string a_s = to_string(a-1) , b_s = to_string(b);

    for(ll i=0;i<20;i++) for(ll j=0;j<10;j++) for(ll k=0;k<2;k++) for(ll l=0;l<2;l++) dp[i][j][k][l] = -1;    
    ll ans = phod(b_s,b_s.length(),-1,1,1);

    for(ll i=0;i<20;i++) for(ll j=0;j<10;j++) for(ll k=0;k<2;k++) for(ll l=0;l<2;l++) dp[i][j][k][l] = -1;
    ans -= phod(a_s,a_s.length(),-1,1,1);
    cout<<ans<<'\n';

    return 0;
}