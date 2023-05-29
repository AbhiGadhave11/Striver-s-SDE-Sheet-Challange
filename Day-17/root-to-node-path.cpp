bool fun(TreeNode *root,vector<int>&ans,int B)
{
    if(root == NULL)
        return false;
    ans.push_back(root->val);
    if(root->val == B)
        return true;
    
    
    if(fun(root->left,ans,B))
        return true;
    if(fun(root->right,ans,B))
        return true;
    ans.pop_back();
    return false;
}
vector<int> Solution::solve(TreeNode* A, int B) 
{
    vector<int>ans;
    bool b = fun(A,ans,B);
    return ans;
}
