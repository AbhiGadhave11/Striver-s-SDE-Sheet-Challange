class Solution {
    bool fun(TreeNode *root1,TreeNode *root2)
    {
        if(root1==NULL && root2==NULL)
            return true;
        if(root1==NULL&&root2!= NULL || root1!= NULL && root2== NULL)
            return false;
        if(root1->val != root2->val)
            return false;
        if(fun(root1->left,root2->left) == false)
            return false;
        if(fun(root1->right,root2->right) == false)
            return false;
        return true;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return fun(p,q);
    }
};
