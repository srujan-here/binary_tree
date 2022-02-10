#include<bits/stdc++.h>
using namespace std;
struct node{
    int data;
    struct node *left;
    struct node *right;

    node(int val){
        data = val;
        left =NULL;
        right=NULL;
    }
};
void prin(node*t){
    if(t==NULL) return;
    prin(t->left);
    cout<<t->data<<" ";
    prin(t->right);
}

void prinlevelor(node *t){
    if(t==NULL) return;

    queue<node*> q1;
    q1.push(t);q1.push(NULL);

    while(!q1.empty()){
        node* m=q1.front();
        q1.pop();
        if(m!=NULL){
            cout<<m->data<<" ";
            if(m->left)
            q1.push(m->left);
            if(m->right)
            q1.push(m->right);

        }
        else if(!q1.empty()){
            q1.push(NULL);
        }
    }
}
int main(){
    struct node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    prinlevelor(root);

}