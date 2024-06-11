// classic application problem for linked list

// there exist other solution but this is straight forward application of LL here

#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node(int v=0,node* p=NULL){
        val = v; next = p;
    }
};

int main(){
    int n; cin>>n;
    node* head = new node(1);
    node* itr = head;
    for(int i=2;i<=n;i++){
        itr->next = new node(i);
        itr = itr->next;
    }
    // forming the circle
    itr->next = head;
    itr = itr->next;

    while(true){
        // if only one person is left
        if (itr->next == itr){
            cout<<itr->val<<'\n';
            break;
        }
        
        // removing the next person
        cout<<itr->next->val<<' ';
        itr->next = itr->next->next;
        itr = itr->next;
    }
    return 0;
}