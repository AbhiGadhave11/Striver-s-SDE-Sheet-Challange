class Solution {
    private:
    int fun(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int lh = fun(root->left);
        int rh = fun(root->right);
        return max(lh,rh)+1;
    }
public:
    int maxDepth(TreeNode* root) {
        return fun(root);
    }
};
