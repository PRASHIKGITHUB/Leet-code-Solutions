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
//recursive 
bool searchInBST(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->data == x)
    {
        return true;
    }
    else if (root->data > x)
    {
        searchInBST(root->left, x);
    }
    else
    {
        searchInBST(root->right, x);
    }
}

//iterative
bool searchInBST(BinaryTreeNode<int> *root, int x) {
            BinaryTreeNode<int> *temp=root;
    while(temp!=NULL){
        if(temp->data==x){
            return true;
        }
        else if(temp->data>x){

        temp=temp->left;
        }
        else{
            temp=temp->right;
        }
        
    }
    return false;
}