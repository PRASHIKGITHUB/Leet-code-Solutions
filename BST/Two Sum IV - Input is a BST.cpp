void solve(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, v);
    v.push_back(root->data);
    solve(root->right, v);
}
bool twoSumInBST(BinaryTreeNode<int> *root, int target)
{
    vector<int> v;
    solve(root, v);
    int i = 0;
    int j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == target)
        {
            return true;
        }
        else if (v[i] + v[j] > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }
    return false;
}