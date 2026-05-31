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
 
void build_Zarr(string s,int n,int *z){
    int l=0,r=0,k;
    z[0]=0;
    repeat(i,1,n){
        if (i>r){
            l = r = i;
            while(r<n and s[r-l]==s[r]) r++;
            z[i] = r-l;
            r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1){
                z[i]=z[k];
            }
            else{
                l=i;
                while(r<n and s[r-l]==s[r]) r++;
                z[i]=r-l;
                r--;
            }
        }
    }
}
 
void build_Piarr(string s,int n,int *pi){
    pi[0] = 0;
    int j = 0;
    for(int i = 1; i< n; i++){
        while(j>0 and s[i]!=s[j]){
            j = pi[j-1];
        }
        if (s[i]==s[j]) j++;
        pi[i] = j;
    }
}

int main(){
    string s; cin>>s;
    int n = (int)s.length();
    int z[n],pi[n];
    build_Zarr(s,n,z);
    build_Piarr(s,n,pi);
    print_it(z);
    print_it(pi);
    return 0;
}