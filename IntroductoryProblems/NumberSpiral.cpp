#include <iostream>
using namespace std;

#define ll long long

void phod(){
    ll y,x; cin>>y>>x;
    // can we make the whole matrix?
    // even once?
    // if x and y can be of 10**9 at max
    // size required is 10**18
    // not possible. 

    // so we need to find something else
    // can we devise a formula?
    // lets check

    // we know every square is completed once that 
    // row and column is filled completely
    // implies, if x=3 and y=3 are completed,
    // we're done with 9 numbers
    // if x=4 and y=4 are completed,
    // we're done with 16 numbers

    // so we need to just find the number in between
    // the last square and the present square..
    // but if x!=y ?
    // we can just consider the max(x,y); this
    // will tell us which square is being filled

    if (x>y){
        // x > y
        // column > row
        // 1 2 9 10 25....
        // if col is odd, square is the start then decrease
        // else prev square+1 is the start....

        if (x%2){ // odd
            cout<<(x*x - (y-1)); // start should be a square
            // y-1 because 1st row has to be that square
        }
        else{
            cout<<( (x-1)*(x-1) + y ); // prev sq + 1,
            // y because we need to inc
        }
    }
    // same for the other way round... just 
    // conditions are swapped
    else{
        // row >= col
        if (y%2){ // odd
            cout<< ( (y-1)*(y-1) + x );
        }
        else{
            cout<< (y*y - (x-1));
        }
    }
    cout<<endl;
}

int main(){
    ll t; cin>>t;
    for(ll i=0;i<t;i++) phod();
}

// problem was of overflow...
// thank you :)