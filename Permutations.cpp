#include <iostream>
using namespace std;

int main(){
    int n; cin>>n;
    // if n==1 => 1
    if (n==1){
        cout<<1;
    }

    // elif n==2 => NO SOLUTION 1 2 , 2 1
    // elif n==3 => NO SOLUTION 1 3 2, 1 2 3 ...
    else if (n==3 || n==2) cout<<"NO SOLUTION";

    // even inc, odd inc
    // for 4 => 2 4 1 3
    // for 5 => 2 4 1 3 5
    // for 6 => 2 4 6 1 3 5
    else{
        // even inc
        for(int i=2;i<=n;i+=2) cout<<i<<" ";

        // odd inc
        for(int i=1;i<=n;i+=2) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}