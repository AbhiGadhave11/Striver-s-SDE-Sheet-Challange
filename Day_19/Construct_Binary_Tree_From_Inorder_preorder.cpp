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
    int FindIdx(vector<int>&inorder,int no)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder[i] == no)
                return i;
        }
        return -1;
    }
    TreeNode *Construct(int ps,int pe,int is,int ie,vector<int>& preorder,vector<int>&inorder)
    {
        if(ps > pe || is > ie)
            return NULL;
        TreeNode *root = new TreeNode(preorder[ps]);
        int idxin = FindIdx(inorder,preorder[ps]);
        int lft = idxin - is;
        root->left = Construct(ps+1,ps+lft,is,idxin-1,preorder,inorder);
        root->right = Construct(ps+lft+1,pe,idxin+1,ie,preorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return Construct(0,preorder.size()-1,0,inorder.size()-1,preorder,inorder);
        
    }
};
