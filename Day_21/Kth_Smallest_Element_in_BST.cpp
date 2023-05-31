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
    int ans = 0;
    void inorder(TreeNode *root ,int &cnt,int k)
    {
        if(root == NULL)
            return ;
        inorder(root->left,cnt,k);
        cnt++;
        if(k == cnt)
        {
            ans = root->val;
        }
        
        inorder(root->right,cnt,k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        inorder(root,cnt,k);
        return ans;
    }
};
