/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    bool FindLCA(TreeNode *root,TreeNode *p,TreeNode *q,TreeNode * &ans)
    {
        if(root == NULL)
            return false;
        bool left  = FindLCA(root->left,p,q,ans);
        bool right = FindLCA(root->right,p,q,ans);
        bool itself = false;
        if(root == p || root == q)
        {
            itself = true;
        }
        if(left + right + itself >= 2) 
        {
            ans = root;
            return false;
        }
        return left || right || itself;  
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode *ans =  NULL;
        FindLCA(root,p,q,ans);
        return ans;
        
    }
};
