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
int diameter(node* t){       //O(n*n)
    if(t==NULL) 
    return 0;
    int lt=height(t->left);
    int rt=height(t->right);
    int curdia=lt+rt+1;
    int ltdia=diameter(t->left);
    int rtdia=diameter(t->right);

    return max(curdia,max(ltdia,rtdia));


}

//finding diameter in  O(n)

int diameter2(node *t,int* h){
if(t==NULL) {
    *h=0;
    return 0;
}
int lh=0,rh=0;
int ld=diameter2(t->left,&lh);
int rd=diameter2(t->right,&rh);
int curd=lh+rh+1;
*h=max(lh,rh)+1;



return max(curd,max(ld,rd));

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
    int heig=0;
    cout<<diameter2(root,&heig)<<endl;

}