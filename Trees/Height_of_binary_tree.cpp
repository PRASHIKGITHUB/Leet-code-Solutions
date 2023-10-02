#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T val)
    {
        this->val = val;
        left = NULL;
        right = NULL;
    }
};
//with itereation
int maxDepth(TreeNode<int> *root)
{
    queue<TreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    int count = 0;
    while (!q.empty())
    {
        TreeNode<int> *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            count++;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return count-1;
}
//with recursion
//T.C-> O(nodes)
//S.C-> O(height)
int maxDepth(TreeNode<int> *root) {
    if(root==NULL){
        return 0;
    }
    if(root->right==NULL && root->left==NULL ){
        return 0;
    }
    int left=maxDepth(root->left);
    int right=maxDepth(root->right);
    int ans=max(left,right)+1;
    return ans;
}