// we need to fill column by column, as it'll be easier to calculate all possible ways of filling a column than a row
// since m > n 
// so we'll start filling a column , in which we will go row by row down

// for every cell either it'll be occupied by a tile from a previous column
// otherwise it'll be empty 

// in the later case of it being empty we can place a horizontal / vertical tile there 

// if we want to place a horizontal tile we can place it and keep a track of the cells we're filling in the next column
// for which we will have a mask ( next_mask => denoting the cells which are pre filled by current col in the next col )
// the mask will be an integer representation of the cells
// and when converted to binary will have 1 at the positions of cells that are filled 

// if we want to place a vertical tile then we need to ensure that the below cell is not pre filled 

// that's it let's goo!

#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll n,m;

// dp table will store all the possible masks for a column
const ll max_columns = 1000;
ll dp[max_columns+1LL][(1<<10)];


const ll mod = 1e9 + 7;

void fill_column(ll row,ll col,ll curr_mask,ll next_mask){
    if (row==n){
        // adding the number of ways we've to make current mask in the ways we have to make the next mask in next col
        dp[col+1][next_mask] = (dp[col+1][next_mask]+dp[col][curr_mask])%mod;
        return;
    }
    // if the cell is not pre-filled
    if ( !(curr_mask & (1<<row)) ){
        // horizontal tile
        fill_column( row+1 , col , curr_mask , next_mask | (1<<row) );
        // vertical tile if the next cell is not filled
        if ( (row <n-1) and  !(curr_mask & (1<<(row+1)))){
            fill_column(row+2,col,curr_mask,next_mask);
        }
    }
    else{
        fill_column( row + 1 , col , curr_mask , next_mask ) ;
    }
}

int main(){
    cin>>n>>m;

    // init the dp state 0,0
    dp[0][0] = 1;

    for(ll col=0;col<m;col++){
        for(ll mask=0;mask<(1<<n);mask++){
            // for all possible masks we'll get the possibilities of filling the col
            // we'll go down in rows => rows = 0
            fill_column(0,col,mask,0); // no cells in next col are filled right now -> next_mask = 0
        }
    }
    cout<<dp[m][0]<<'\n';
    return 0;
}