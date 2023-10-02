#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* left;
    Node* right;
};

//TC->O(Nodes)
//SC->O(height)
class Solution
{
public:
    int findsize(struct Node *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int ans = 1 + findsize(root->left) + findsize(root->right);
        return ans;
    }

    bool isCBT(struct Node *root, int index, int size)
    {
        if (root == NULL)
        {
            return true;
        }
        if (index >= size)
        {
            return false;
        }
        else
        {
            bool left = isCBT(root->left, 2 * index + 1, size);
            bool right = isCBT(root->right, 2 * index + 2, size);
            return (left && right);
        }
    }

    bool ismaxOrder(struct Node *root)
    {
        if (root->right == NULL && root->left == NULL)
        {
            return true;
        }
        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left = ismaxOrder(root->left);
            bool right = ismaxOrder(root->right);
            return (left && right && (root->data > root->right->data) && (root->data > root->left->data));
        }
    }
    bool isHeap(struct Node *tree)
    {
        int index = 0;
        int size = findsize(tree);
        return (isCBT(tree, index, size) && ismaxOrder(tree));
    }
};