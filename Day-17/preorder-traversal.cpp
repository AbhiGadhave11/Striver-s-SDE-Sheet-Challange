class Solution {
public:
    
    void inorder(TreeNode *root,vector<int>&v)
    {
        if(root == NULL)
            return ;
        v.push_back(root->val);
        inorder(root->left,v);
        
        inorder(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int>vobj;
        inorder(root,vobj);
        
        return vobj;
        
    }
    
};
