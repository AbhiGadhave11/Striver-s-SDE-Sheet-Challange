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
    void fun(TreeNode *root)
    {
        if(root == NULL )
            return;
        if(root->left == NULL && root->right == NULL)
            return;
        fun(root->left);
        fun(root->right);
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode *curr = root;
        while(curr->right != NULL)
            curr  = curr->right;
        curr->right = temp;
    }
public:
    void flatten(TreeNode* root) {
        fun(root);
    }
};
