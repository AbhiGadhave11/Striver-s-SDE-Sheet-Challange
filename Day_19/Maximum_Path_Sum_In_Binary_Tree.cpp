/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    int findmaxpath(TreeNode *root,int &maxi)
    {
        if(root == NULL)
            return 0;
        int leftsum = findmaxpath(root->left,maxi);
        int rightsum = findmaxpath(root->right,maxi);
        leftsum = max(0,leftsum);
        rightsum = max(0,rightsum);
        maxi = max(maxi,root->val+leftsum+rightsum);
        return max(leftsum,rightsum)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int ans = findmaxpath(root,maxi);
        return maxi;
    }
};
