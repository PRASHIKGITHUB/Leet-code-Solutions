vector<int> mergeArrays(vector<int> &bst1, vector<int> &bst2)
{
    int n1 = bst1.size();
    int n2 = bst2.size();
    vector<int> ans;
    int i = 0, j = 0;
    while (i < n1 && j < n2)
    {
        if (bst1[i] < bst2[j])
        {
            ans.push_back(bst1[i++]);
        }
        else
        {
            ans.push_back(bst2[j++]);
        }
    }

    while (i < n1)
    {
        ans.push_back(bst1[i++]);
    }
    while (j < n2)
    {
        ans.push_back(bst2[j++]);
    }
    return ans;
}
void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}
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
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    // step 1: store inorder
    vector<int> bst1;
    vector<int> bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);
    // step 2:merge both sorted array
    vector<int> mergeArray = mergeArrays(bst1, bst2);
    // step 3:inorder to bst
    TreeNode<int> *ans = inorderToBST(0, mergeArray.size() - 1, mergeArray);
    return ans;
}
//############################################################@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//approach 2
int countNodez(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}
void convertIntosortedDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    // base case
    if (root == NULL)
    {
        return;
    }

    convertIntosortedDLL(root->right, head);

    root->right = head;

    if (head != NULL)
    {
        head->left = root;
    }
    head = root;
    convertIntosortedDLL(root->left, head);
}
TreeNode<int> *mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head;
                head2 = head2->right;
            }
        }
    }
    while (head1 != NULL)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head;
        head1 = head1->right;
    }
    while (head2 != NULL)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head;
        head1 = head2->right;
    }
    return head;
}
TreeNode<int> *sortedLLToBST(TreeNode<int> *&head, int n)
{
    // base case
    if (n <= 0 || root == NULL)
    {
        return NULL;
    }
    TreeNode<int> *left = sortedLLToBST(head, n / 2);
    TreeNode<int> *root = head;
    root->left = left;

    head = head->next;

    root->right = sortedLLToBST(head, n - n / 2 - 1);
    return root;
}
TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int> *head1 = NULL;
    convertIntosortedDLL(root1, head1);
    head1->left = NULL;

    TreeNode<int> *head2 = NULL;
    convertIntosortedDLL(root2, head2);
    head2->left = NULL;

    TreeNode<int> *head = mergeLinkedList(head1, head2);

    return sortedLLToBST(head, countNodez(head));
}