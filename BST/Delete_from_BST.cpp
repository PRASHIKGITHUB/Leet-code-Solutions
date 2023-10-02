#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
//**********************************************************************
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
void takeInput(Node *&root)
{
    int data;
    cin >> data;
    while (data != -1)
    {
        root = insertInBST(root, data);
        cin >> data;
    }
}
//**********************************************************************
void levelOrderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {

            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
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

    return;
}
//**********************************************************************
Node *minright(Node *root)
{
    if (root == NULL)
    {
        return root;
    }
    else
    {
        root = root->left;
        minright(root);
    }
    return root;
}
Node *deleteFromBST(Node *root, int val)
{
    if (root == NULL)
    {
        return root;
    }

    if (root->data == val)
    {
        // 0 child
        if (root->right == NULL && root->left == NULL)
        {
            delete root;
            return NULL;
        }

        // 1 child

        // right child is present
        if (root->right != NULL && root->left == NULL)
        {
        }
        // left child is present
        if (root->left != NULL && root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        // right child
        if (root->right != NULL && root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // 2 child
        if (root->left != NULL && root->right != NULL)
        {
            int minval = minright(root->right)->data;
            root->data = minval;
            root->right = deleteFromBST(root->right, minval);
            return root;
        }
    }

    else if (root->data > val)
    {
        root->left = deleteFromBST(root->left, val);
        return root;
    }
    else
    {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
//*********************************************************************
int main()
{
    Node *root = NULL;
    takeInput(root);
    levelOrderTraversal(root);
    root = deleteFromBST(root, 30);
    cout << endl;
    levelOrderTraversal(root);
    return 0;
}