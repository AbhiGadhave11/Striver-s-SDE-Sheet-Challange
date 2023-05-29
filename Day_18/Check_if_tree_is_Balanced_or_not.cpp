class Solution {
    private:
    int lh = 0,rh = 0;
    int height(TreeNode *root,bool &flag)
    {
        if(root == NULL)
            return 0;
        int lh = height(root->left,flag);
        int rh = height(root->right,flag);
        this->lh = lh;
        this->rh = rh;
        if(abs(lh-rh) > 1)
            flag = false;
        return max(lh,rh)+1;
        
    }
public:
    bool isBalanced(TreeNode* root) 
    {
        bool flag = true;
        int ans = height(root,flag);
        if(abs(lh-rh) <= 1 && flag == true )
            return true;
        return false;
        
    }
};
