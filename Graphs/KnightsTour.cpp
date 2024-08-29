// The knight's tour is a chess problem 

// we need to use Warnsdorff's rule here but as this rule fails for some starting positions

// we need to modify this a lil bit, as done my Ira Pohl 

// we'll define the rules of movement of knight

// and then check how many moves are possible from the position we're aiming our knight at,
// and if there're multiple such cases we'll need to go to the next level for comparision, link to the paper of Ira Pohl is attatched 

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

map<int,pair<int,int>>  moves;
vector<vector<int>> chessboard(8,vector<int>(8,0));

void init(){
    moves[0] = {-2,-1};
    moves[1] = {-2, 1};
    
    moves[2] = { 2,-1};
    moves[3] = { 2, 1};
    
    moves[4] = {-1, 2};
    moves[5] = {-1,-2};

    moves[6] = { 1, 2};
    moves[7] = { 1,-2};
}

int find_next_poss_moves(int x,int y){
    if (chessboard[x][y]) return 0;

    int poss_moves = 0;
    repeat(i,0,8){
        int a = x+moves[i].first, b = y+moves[i].second;
        if (a<0 or b<0 or a>=8 or b>=8 or chessboard[a][b]) continue;
        poss_moves++;
    }
    return poss_moves;
}

pair<int,int> find_poss_moves(int x,int y){
    if (x<0 or y<0 or x>=8 or y>=8 or chessboard[x][y]) return {10,-1}; // this is occupied or out of limits
    

    int poss_moves = 0;
    int next_poss_moves=0; // moves for breaking the tie in min_poss_moves

    repeat(i,0,8){
        int a = x+moves[i].first, b = y+moves[i].second;
        
        if (a<0 or b<0 or a>=8 or b>=8 or chessboard[a][b]) continue;

        poss_moves++;
        next_poss_moves += find_next_poss_moves(a,b);
    }

    return {poss_moves,next_poss_moves};

}

int main(){
    init();

    int x,y; cin>>y>>x; // they're given reverse for our use
    x--,y--;
    int moves_taken = 1;

    while(1){
        // we need to find the min poss moves from all the possible one's we can visit from x,y 
        
        chessboard[x][y] = moves_taken++;
        
        int new_x = -1,new_y = -1; // the next square we're aiming at 
        
        int min_poss_moves = 9;
        int max_poss_next_moves = -1;
        
        // cout<<x<<' '<<y<<'\n';

        repeat(i,0,8){
            pair<int,int> next_moves = find_poss_moves(x+moves[i].first,y+moves[i].second);
            // cout<<next_moves.first<<' '<<next_moves.second<<'\n';
            if (next_moves.first < min_poss_moves){
                min_poss_moves = next_moves.first;
                max_poss_next_moves = next_moves.second;
                new_x = x+moves[i].first;
                new_y = y+moves[i].second;
            } elif ((next_moves.first == min_poss_moves) and 
                    (next_moves.second > max_poss_next_moves)){
                max_poss_next_moves = next_moves.second;
                new_x = x+moves[i].first;
                new_y = y+moves[i].second;
            }
        }
        // cout<<new_x<<' '<<new_y<<'\n';
        if (new_x==-1 or new_y==-1) break;
        x = new_x; y = new_y;
    }

    repeat(i,0,8){
        repeat(j,0,8) cout<<chessboard[i][j]<<' '; cout<<endl;
    }

    return 0;
}