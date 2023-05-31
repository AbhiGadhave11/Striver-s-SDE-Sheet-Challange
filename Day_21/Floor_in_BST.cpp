
int floorInBST(TreeNode<int> * root, int x)
{
    int ans = 0;
    TreeNode<int>*curr = root;
    while(curr != NULL)
    {
        if(curr->val > x)
        {
            curr = curr->left;
        }
        else if(curr->val <= x)
        {
            ans = curr->val;
            curr = curr->right;
        }
    }
    return ans;
}
