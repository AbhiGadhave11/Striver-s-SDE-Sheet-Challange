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
    TreeNode *Construct(int ps,int pe,int is,int ie,vector<int>& postorder,vector<int>&inorder)
    {
        if(ps > pe || is > ie)
            return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);
        int idxin = FindIdx(inorder,postorder[pe]);
        int lft = idxin - is;
        root->left = Construct(ps,ps+lft-1,is,idxin-1,postorder,inorder);
        root->right = Construct(ps+lft,pe-1,idxin+1,ie,postorder,inorder);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        
        return Construct(0,postorder.size()-1,0,inorder.size()-1,postorder,inorder);
    }
};
