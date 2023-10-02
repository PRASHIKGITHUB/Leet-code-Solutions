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

//Alternate approach
/*
find that element first
for predecessor traverse left till u find NULL
for successor traverse right till u find NULL
*/
using namespace std;
Node *insertInBST(Node *root, int d)
{
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if (d > root->data)
    {
        root->right = insertInBST(root->right, d);
    }
    else
    {
        root->left = insertInBST(root->left, d);
    }
    return root;
}
Node *inorderSuccesor(Node *root, int val)
{
    Node *succesor = NULL;
    while (root != NULL)
    {
        if (root->data > val)
        {
            succesor = root;
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return succesor;
}

Node *inorderpredecessor(Node *root, Node *val)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (root->data < val->data)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return predecessor;
}

Node *inorderpredecessor(Node *root, int val)
{
    Node *predecessor = NULL;
    while (root != NULL)
    {
        if (root->data < val)
        {
            predecessor = root;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    return predecessor;
}
void inorderprint(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorderprint(root->left);
    cout << root->data << " ";
    inorderprint(root->right);
}
int main()
{
    return 0;
}