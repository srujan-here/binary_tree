#include<bits/stdc++.h>
using namespace std;
struct node{
int data;
struct node* left;
struct node* right;

node(int val){
    data=val;
    left=NULL;
    right=NULL;
}

};

int search(int ino[],int s,int e,int cur){
for(int i=s;i<=e;i++)
{
      if(ino[i]==cur){
           return i;
          }
          }
return -1;
}
node* build(int pre[],int ino[],int s,int e){
    static int id=0;
    if(s>e){
        return NULL;

    }
    int cur=pre[id];
    id++;
    node* main=new node(cur);
    if(s==e){
        return main;
    }
    int pos=search(ino,s,e,cur);
    main->left=build(pre,ino,s,pos-1);
    main->right=build(pre,ino,pos+1,e);

return main;

}


void inprin(node* t){
    if(t==NULL){
        return;
    }
    inprin(t->left);
    cout<<t->data<<" ";
    inprin(t->right);
}


int main(){

int pre[]={1,2,4,3,5};
int ino[]={4,2,1,5,3};

node* f=build(pre,ino,0,4);
inprin(f);

return 0;

}
