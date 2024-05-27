// 123456789 10111213141516171819202122232425   99
// ,       , ,                             ..... ,
 
// for every number with x-digits
// there are 9*( 10^(x-1) ) numbers with x-digits

// 1-digit -> 9
// 2-digit -> 90
// 3-digit -> 900

// number of digits when we're reaching place
// for 1 digit -> 1 digit each number
// for 2 digit -> 2 digits each number
// ..
// ..
// for n digit -> n digits each number

// so when finding digit at place p, we need to know how many digits have already passed
// then we'll find place p, lies under which number's digits, then we'll find that digit

#include <bits/stdc++.h>
using namespace std;

#define ll long long

// function for a single test case
void phod(){
    ll n; cin>>n;

    // if n is < 10 then n is the digit itself
    if (n<10){
        cout<<n<<endl; return;
    }
    ll digits = 0;
    // knowing which pow of 10 we're in by i
    int i=0;
    for(i=1;i<20;i++){
        digits += lround(9*i*(pow(10,i-1)));
        // if we've reached 9+2*90=189 , and n < 189 means we've n between 9 and 189, thus n is 2 digit number, thus substracting the digits just added
        // to get to the starting number
        if (digits > n){
            digits -= lround(9*i*(pow(10,i-1)));
            break;
        }
    }

    // knowing the number we've to find in whose digits we'll find n
    ll num = lround(pow(10,i-1)) + (n-digits)/i; // starting of the number in which n-th place is
    ll rem = (n-digits)%i; // rem is the number of shifts we need to make to get to n-th place
    
    // if rem == 0, implies we've reached that number of digits already, thus printing the last digit of the number before num

    if (rem==0){    
        string s = to_string(num - 1);
        cout<<s[s.length()-1];
    }
    else{
        string s = to_string(num);
        cout<<s[rem - 1];
    }
    cout<<endl;

}

int main(){
    ll t; cin>>t;
    for(ll _=0;_<t;_++) phod();
}