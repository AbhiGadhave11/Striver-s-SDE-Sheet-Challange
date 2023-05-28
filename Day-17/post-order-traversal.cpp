class Solution {
public:
    
    void inorder(TreeNode *root,vector<int>&v)
    {
        if(root == NULL)
            return ;
        
        inorder(root->left,v);
        inorder(root->right,v);
        v.push_back(root->val);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>vobj;
        inorder(root,vobj);
        
        return vobj;
        
    }
    
};
