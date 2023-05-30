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
    bool fun(TreeNode *lefttree,TreeNode *righttree)
    {
        if(lefttree == NULL && righttree ==NULL)
            return true;
        if(lefttree == NULL || righttree == NULL)
            return false;
        if(lefttree->val != righttree->val)
            return false;
        bool left = fun(lefttree->left,righttree->right);
        bool right = fun(lefttree->right,righttree->left);
        if(left && right)
            return true;
        return false;
    }
public:
    bool isSymmetric(TreeNode* root) 
    {
        if(root == NULL)
            return true;
        return fun(root->left,root->right);
        
    }
};
