#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;
    node(int val){
        data=val;
        right=NULL;
        left=NULL;
    }
};
void preorder(struct node * &t){      //passing address by reference so that we can reduce time complexity
    if(t==NULL)
    return;
    cout<<t->data<<" ";
    preorder(t->left);
    preorder(t->right);
}
void inorder(struct node * &m){
    if(m==NULL)
    return;
    inorder(m->left);
    cout<<m->data<<" ";
    inorder(m->right);
}
void postorder(struct node* &n){
    if(n==NULL)
    return;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
}
int main(){
struct node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);


}