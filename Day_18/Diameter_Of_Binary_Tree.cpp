class Solution {
public:
    int ans = INT_MIN;
    int height(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        ans = max(ans,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        
        int a = height(root);
        return ans;
    }
};
