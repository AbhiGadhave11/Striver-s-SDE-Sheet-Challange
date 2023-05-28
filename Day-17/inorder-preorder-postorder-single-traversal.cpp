void fun(BinaryTreeNode<int>*root,vector<vector<int>>&ans)
{
    if(root == NULL)
        return;
    ans[1].push_back(root->data);
    fun(root->left,ans);
    ans[0].push_back(root->data);
    fun(root->right,ans);
    ans[2].push_back(root->data);
}

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root)
{
   vector<vector<int>>ans(3);
   fun(root,ans); 
   return ans;
}
