#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* right;
    Node* left;
};
// T.C->O(n)
int noOfLeafNodes(BinaryTreeNode<int> *root)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    int count = 0;
    while (!q.empty())
    {
        BinaryTreeNode<int> *temp = q.front();
        q.pop();
        if (temp->right == NULL && temp->left == NULL)
        {
            count++;
        }
        if (temp->right != NULL)
        {
            q.push(temp->right);
        }
        if (temp->left != NULL)
        {
            q.push(temp->left);
        }
    }
    return count;
}