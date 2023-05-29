class Solution {
    private:
    TreeNode *LCA(TreeNode *root,TreeNode *p,TreeNode *q)
    {
        if(root == NULL)
            return NULL;
        TreeNode *self = NULL;
        if(root->val==p->val || root->val==q->val)
            self = root;
        TreeNode *left = LCA(root->left,p,q);
        TreeNode *right = LCA(root->right,p,q);
        if(left!=NULL&&self!=NULL || left!=NULL&&right!=NULL || right!=NULL&&self!=NULL)
        {
            return root;
        }
        if(left != NULL)
            return left;
        if(right != NULL)
            return right;
        if(self != NULL)
            return self;
        
        return NULL;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        return LCA(root,p,q);
    }
};
