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
int sumK(node* t,int k){
    if(t==NULL) return -1;

    queue<node*> q;
    q.push(t);
    q.push(NULL);
    int le=1;
    int sum=0;
    while(!q.empty()){
        node*m=q.front();
        q.pop();
        if(m!=NULL){
           if(le==k){
               sum+=(m->data);
           }
           if(m->left)
           q.push(m->left);
           if(m->right)
           q.push(m->right);
        }
        else{
            if(!q.empty())
            {
                q.push(NULL);
                        le++;


            }
        }
    }
return sum;
}

int main(){
    struct node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<sumK(root,3)<<endl;

}