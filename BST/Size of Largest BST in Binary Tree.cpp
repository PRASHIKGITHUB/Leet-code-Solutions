class info
{
public:
    int maxi;
    int mini;
    bool isBST;
    int size;
};

info solve(TreeNode<int> *root, int &ans)
{
    if (root == NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);
    currNode.size = right.size + left.size + 1;

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini))
    {
        currNode.isBST = true;
    }
    else
    {
        currNode.isBST = false;
    }

    // answer updata
    if (currNode.isBST)
    {
        ans = max(ans, currNode.size);
    }

    return currNode;
}
int largestBST(TreeNode<int> *root)
{
    int ans = 0;
    info temp = solve(root, ans);
    return ans;
}