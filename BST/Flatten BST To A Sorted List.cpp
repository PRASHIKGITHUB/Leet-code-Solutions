void solve(TreeNode<int>* root,vector<int>&v){
    if(root==NULL){
        return ;
    }
    solve(root->left,v);
    v.push_back(root->data);
    solve(root->right,v);

}
TreeNode<int>* flatten(TreeNode<int>* root)
{
    vector<int>v;
    solve(root,v);
    int n=v.size();
    TreeNode<int>* newRoot=new TreeNode<int>(v[0]);
    TreeNode<int>*curr=newRoot;

    for(int i=1;i<n;i++){
        TreeNode<int>* temp=new TreeNode<int>(v[i]);
        curr->left=NULL;
        curr->right=temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;
    return newRoot;
}