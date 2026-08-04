#include<bits/stdc++.h>
using namespace std;
const int N=15;
struct Node{
    int val,right=-1,left=-1;
};
Node tree[N];
int nodecount=0,root=-1;
int creatNode(int x){
    int id=nodecount++;
    tree[id].val=x;
    tree[id].right=-1;
    tree[id].left=-1;
    return id;
}
void Creattree(int x){
    int new_node=creatNode(x);
    if(root==-1){
        root=new_node;
        return;
    }
    int cur=root;
    while(1){
        if(tree[cur].val<x){
            if(tree[cur].left==-1){
                tree[cur].left=new_node;
                return;
            }
            cur=tree[cur].left;
        }
        else{
            if(tree[cur].right==-1){
                tree[cur].right=new_node;
                return;
            }
            cur=tree[cur].right;
        }
    }
}
void print(){
    queue<int>qe;
    qe.push(root);
    int flag=0;
    while(!qe.empty()){
        int p=qe.front();
        qe.pop();
        if(flag)cout<<" ";
        flag=1;
        cout<<tree[p].val;
        if(tree[p].left!=-1){
            qe.push(tree[p].left);
        }
        if(tree[p].right!=-1){
            qe.push(tree[p].right);
        }
    }
}
bool check(){
    queue<int>qe;
    qe.push(root);
    int flag=0;
    while(!qe.empty()){
        int p=qe.front();
        qe.pop();
        if(p==-1){
            flag=1;
            continue;
        }
        if(flag)return false;
        qe.push(tree[p].left);
        qe.push(tree[p].right);
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        Creattree(x);
    }
    print();
    cout<<endl;
    cout<<(check()?"YES":"NO");
    return 0;
}