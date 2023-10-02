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
    // create mapping
    // return target node
    Node *createParentMapping(Node *root, int target, map<Node *, Node *> &nodeToParent)
    {
        Node *result = NULL;

        queue<Node *> q;
        q.push(root);
        nodeToParent[root] = NULL;
        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();
            if (front->data == target)
            {
                result = front;
            }
            if (front->left != NULL)
            {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right != NULL)
            {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return result;
    }

    void burnTree(Node *root, map<Node *, Node *> nodeToparent, int &ans)
    {
        map<Node *, bool> visited;
        queue<Node *> q;

        q.push(root);
        visited[root] = 1;

        while (!q.empty())
        {
            bool flag = 0;
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *front = q.front();
                q.pop();

                if (front->left != NULL && !visited[front->left])
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if (front->right != NULL && !visited[front->right])
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if (nodeToparent[front] && !visited[nodeToparent[front]])
                {
                    flag = 1;
                    q.push(nodeToparent[front]);
                    visited[nodeToparent[front]] = 1;
                }
            }
            if (flag == 1)
            {
                ans++;
            }
        }
    }
    int minTime(Node *root, int target)
    {
        // step-1 create node to parent mapping
        // sete-2 find target node
        // step-3 burn the tree in minimum time

        int ans = 0;
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createParentMapping(root, target, nodeToParent);

        burnTree(targetNode, nodeToParent, ans);
        return ans;
    }
};