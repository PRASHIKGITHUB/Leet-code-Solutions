#include <bits/stdc++.h>
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
bool isBST(BinaryTreeNode<int>* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data<max && root->data>min){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left&& right;
    }
    else{
        return false;
    }
}
bool validateBST(BinaryTreeNode<int>* root) 
{
    // Write your code here
    return isBST(root,INT_MIN,INT_MAX);
}