#include <bits/stdc++.h>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode<int> *left;
    BinaryTreeNode<int> *right;

    BinaryTreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
void inorder(BinaryTreeNode<int> *root, int &k, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, k, ans);
    k--;
    if (k == 0)
    {
        ans = root->data;
        return;
    }
    inorder(root->right, k, ans);
}
int kthSmallest(BinaryTreeNode<int> *root, int k)
{
    // Write your code here.
    int ans = -1;

    inorder(root, k, ans);
    return ans;
}