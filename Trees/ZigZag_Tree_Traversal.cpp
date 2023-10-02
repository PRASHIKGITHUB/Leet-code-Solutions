#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *right;
    Node *left;
};
// T.C->O(nodes)
// S.C->O(number of nodes of ground level)
class Solution
{
public:
    // Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node *root)
    {
        vector<int> result;
        if (root == NULL)
        {
            return result;
        }

        queue<Node *> q;
        q.push(root);

        bool leftToright = true;

        while (!q.empty())
        {
            int size = q.size();
            vector<int> ans(size);

            // level process
            for (int i = 0; i < size; i++)
            {
                Node *frontNode = q.front();
                q.pop();

                int index = leftToright ? i : size - 1 - i;
                ans[index] = frontNode->data;

                if (frontNode->left != NULL)
                {
                    q.push(frontNode->left);
                }
                if (frontNode->right != NULL)
                {
                    q.push(frontNode->right);
                }
            }

            // direction change krni hai

            leftToright = !leftToright;

            for (auto i : ans)
            {
                result.push_back(i);
            }
        }
        return result;
    }
};