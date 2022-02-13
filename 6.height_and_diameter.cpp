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
int height(node* t){
    if(t==NULL) 
    return 0;
    int lt=height(t->left);
    int rt=height(t->right);

    return max(lt,rt)+1;

}
int diameter(node* t){
    if(t==NULL) 
    return 0;
    int lt=height(t->left);
    int rt=height(t->right);
    int curdia=lt+rt+1;
    int ltdia=diameter(t->left);
    int rtdia=diameter(t->right);

    return max(curdia,max(ltdia,rtdia));


}
int main(){
    struct node *root=new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    cout<<height(root)<<endl;
    cout<<diameter(root)<<endl;

}