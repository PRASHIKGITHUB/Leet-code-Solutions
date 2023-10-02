TreeNode<int> *inorderToBST(int s, int e, vector<int> &v)
{
    if (s > e)
    {
        return NULL;
    }
    int mid = (s + e) / 2;
    TreeNode<int> *root = new TreeNode<int>(v[mid]);
    root->left = inorderToBST(s, mid - 1, v);
    root->right = inorderToBST(mid + 1, e, v);
    return root;
}
void inorder(TreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, v);
    v.push_back(root->data);
    inorder(root->right, v);
}
TreeNode<int> *balancedBst(TreeNode<int> *root)
{
    vector<int> v;
    inorder(root, v);
    int n = v.size();
    return inorderToBST(0, n - 1, v);
}