#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
};
//  It is guaranteed that the node exists in the tree.
Node *solve(Node *root, int &k, int node)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == node)
    {
        return root;
    }

    Node *leftAns = solve(root->left, k, node);
    Node *rightAns = solve(root->right, k, node);

    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k == 0)
        {

            return root;
        }
        return rightAns;
    }

    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k == 0)
        {

            return root;
        }
        return leftAns;
    }
    else
    {
        return NULL;
    }
}
int kthAncestor(Node *root, int k, int node)
{
    Node *ans = solve(root, k, node);
    if (root == NULL || ans->data == node) //           1
    {                                      //         2   3   node=4 and k=3 that's why ans->data==node is being is checked
        return -1;                         //       4
    }                                      //
    else
    {
        return ans->data;
    }
}