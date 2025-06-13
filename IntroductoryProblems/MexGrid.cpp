// there is a pattern 

// for ex n = 8

// 0 +1  1 +2  2 3 _ +4   4 5 6 7
// +1
// 1     0     3 2        5 4 7 6
// +2
// 2 3    0 1        6 7 4 5
// 3 2    1 0        7 6 5 4
// |
// +4
// 4 5 6 7     =   0 1 2 3
// 5 4 7 6         1 0 3 2
// 6 7 4 5         2 3 0 1
// 7 6 5 4         3 2 1 0

// +8

// observe the blocks of 2x2 
// this will show you the pattern


// alternate diagnoal halves are symmetrical (symmetry of matrix)
// also 
// the main diagonal halves are symmetric.

// 0 1 2 3 4 5 6 7 8 9 
// 1 0 3 2 5 4 7 6 9 8 
// 2 3 0 1 6 7 4 5 10 11 
// 3 2 1 0 7 6 5 4 11 10 
// 4 5 6 7 0 1 2 3 12 13 
// 5 4 7 6 1 0 3 2 13 12 
// 6 7 4 5 2 3 0 1 14 15 
// 7 6 5 4 3 2 1 0 15 14 
// 8 9 10 11 12 13 14 15 0 1 
// 9 8 11 10 13 12 15 14 1 0 


#include <bits/stdc++.h>
using namespace std;


//Getting faster
#define repeat(i,s,e) for(long long i=s;i<e;i++)
#define reveat(i,s,e) for(long long i=s;i>e;i--)
#define elif else if
#define print(s) cout<<(s)<<endl
#define ll long long
#define append push_back
#define print_it(s) for(auto i : s) cout<<i<<" ";cout<<endl;


//Debugging functions
void print_2darr(auto n,auto m,auto **arr){ repeat(i,0,n){repeat(j,0,m) cout<<arr[i][j]<<' ';cout<<endl;}}
void print_1darr(auto n,auto arr[]){ repeat(i,0,n) cout<<arr[i]<<' ';cout<<endl;}


//Variables
string yes = "YES";
string no = "NO";

vector<vector<int>> mex_grid(100,vector<int>(100,0));
vector<int> pow2 = { 0, 1, 2, 4, 8, 16, 32, 64, 128 };

void build(int r, int c){
    int i=0,j=0; // the value which can refer to in the matrix that has already been filled
    while(pow2[i] <= r) i++;
    while(pow2[j] <= c) j++;
    i--,j--;

    // diagnoal half
    if (pow2[i] == pow2[j]){
        mex_grid[r][c] = mex_grid[r - pow2[i]][c - pow2[j]];
    }
    else if (pow2[i] > pow2[j]){
        // increment the other halves
        mex_grid[r][c] = mex_grid[r - pow2[i]][c] + pow2[i];
    }
    else {
        mex_grid[r][c] = mex_grid[r][c - pow2[j]] + pow2[j];
    }
}


int main(){
    int n;
    cin>>n;

    repeat(i,0,n){
        repeat(j,0,n){
            build(i,j);
            cout<<mex_grid[i][j]<<' ';
        }
        cout<<endl;
    }

    return 0;
}