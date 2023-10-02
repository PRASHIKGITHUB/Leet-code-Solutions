#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
};
class Solution
{
public:
    void Lefttraversal(Node *root, vector<int> &ans)
    {
        if (root == NULL || (root->right == NULL && root->left == NULL))
        {
            return;
        }
        ans.push_back(root->data);
        if (root->left != NULL)
        {
            Lefttraversal(root->left, ans);
        }
        else
        {
            Lefttraversal(root->right, ans);
        }
    }

    void Leaftraversal(Node* root,vector<int>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            ans.push_back(root->data);
        }
        Leaftraversal(root->left,ans);
        Leaftraversal(root->right,ans);
    }

    void Righttraversal(Node* root,vector<int>&ans){
        if (root == NULL || (root->right == NULL && root->left == NULL))
        {
            return;
        }
        if (root->right != NULL)
        {
            Righttraversal(root->right, ans);
        }
        else
        {
            Righttraversal(root->left, ans);
        }
        ans.push_back(root->data);
    }
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if (root == NULL)
        {
            return ans;
        }
        ans.push_back(root->data);

        // left traversal
        Lefttraversal(root->left, ans);

        //Leaf traversal
        Leaftraversal(root->left,ans);
        Leaftraversal(root->right,ans);

        //Right traversal
        Righttraversal(root->right,ans);

        return ans;
    }
};