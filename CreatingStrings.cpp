// creating all possible strings...

// requires going recursively to each possible string


// we'll use a freq map

#include <bits/stdc++.h>
using namespace std;

map<char,int> freq;
string ALPHA = "abcdefghijklmnopqrstuvwxyz";

vector<string> ans;

// phod will go to next possible strings
void phod(string prev_s){

    bool all_chars_used = true;

    for(int i=0;i<26;i++){
        if (freq[ALPHA[i]]){
            all_chars_used = false;

            // using the char
            freq[ALPHA[i]]--;

            // using the found available char
            phod(prev_s+ALPHA[i]);

            // restoring the char back
            freq[ALPHA[i]]++;
        }
    }
    if (all_chars_used){
        ans.push_back(prev_s);
    }
    return;
}

int main(){
    string s; cin>>s;

    // making the freq map
    for(auto i : s) freq[i]++;

    // the empty string goes for the start
    // all possible chars occupy the first seat
    // then the other chars follow ..
    // so on we reach all outcomes
    

    phod("");

    cout<<ans.size()<<'\n';
    for(auto i : ans) cout<<i<<'\n';

    return 0;
}