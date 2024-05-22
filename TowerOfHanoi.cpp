// We've three towers 

// Using these towers we'll play the game

// SRC , SUPPORT , DEST

// when n=1, trivial case , source->dest direct

// when n=2, 

// SRC  | SUPP  | DEST
// 1,2  | non   | non
// 2    | 1     | non
//      | 1     | 2
//      |       | 1,2

// done

// for n=3
// just replace SUPP AND DESTINATION till the tower till 2, is formed at
// support, so that we can then move 3 from source to dest

// which just means, switching source and destination for the game till n-1
// then shifting the bottom plate then playing the reverse thing


// SRC    | SUPP  | DEST
// 1,2,3  | non   | non
// 2,3    | non   | 1
// 3      | 2     | 1
// 3      | 1,2   |
//        | 1,2   | 3
// 1      | 2     | 3
// 1      |       | 2,3
//        |       | 1,2,3

// so as we assembled the tower till n=2 on support and moves n=3 on dest
// we can then move the whole tower from support to dest using source

// RECURSION 


#include <bits/stdc++.h>
using namespace std;

#define ll long long

void tower_of_hanoi(int source,int support,int destination,int n){
    if (n==1){
        cout<<source<<" "<<destination<<'\n';
        return;
    }

    // move the tower till n-1 to support
    tower_of_hanoi(source,destination,support,n-1);
    // move the bottom plate (n-th plate)
    cout<<source<<" "<<destination<<'\n';
    // move the tower of n-1 from support to destination 
    tower_of_hanoi(support,source,destination,n-1);

    return;
}

int main(){

    ll n; cin>>n;

    // steps needed are twice + 1 the steps needed 
    // to move (n-1)th tower,

    // n=1 -> 1
    // n=2 -> 3
    // n=3 -> 7
    // n=n -> 2^n - 1
    cout<< (1<<n)-1<<'\n'; // 1<<n implies 2^n
    tower_of_hanoi(1,2,3,n);
    return 0;
}