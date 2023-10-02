#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
};
// T.C->O(nodes)
// S.C->O(height of tree)
class Solution
{
    public:
    pair<bool,int> isSumFast(Node* root){
        if(root==NULL){
            pair<bool,int> p=make_pair(true,0);
            return p;
        }
        if(root->right==NULL && root->left==NULL){
            pair<bool,int> p=make_pair(true,root->data);
            return p;
        }
        
        pair<bool,int> Right=isSumFast(root->right);
        pair<bool,int> Left=isSumFast(root->left);
        
        bool isright=Right.first;
        bool isleft=Left.first;
        bool sum= root->data==Right.second+Left.second;
        
        pair<bool,int>ans;
        
        if(isright && isleft && sum){
            ans.first=true;
            ans.second=root->data+Right.second+Left.second;
        }
        else{
            ans.first=false;
            
        }
        return ans;
    }
    bool isSumTree(Node* root)
    {
        return isSumFast(root).first;
    }
};