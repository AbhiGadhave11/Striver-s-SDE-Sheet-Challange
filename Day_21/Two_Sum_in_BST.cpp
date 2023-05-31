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
class BSTIterator
{
    stack<TreeNode *>st;
    //reverse->true->before
    //reverse->false->next
    bool reverse = true;
    public :
    BSTIterator(TreeNode *root,bool isreverse)
    {
        reverse = isreverse;
        pushAll(root);
    }
    bool hasNext()
    {
        if(st.size() == 0)
            return false;
        return true;
    }
    int next()
    {
        TreeNode *temp = st.top();
        st.pop();
        if(reverse == false)
        {
            
            pushAll(temp->right);
        }
        else
            
            pushAll(temp->left);
        return temp->val;
    }
    private:
    void pushAll(TreeNode *root)
    {
        while(root != NULL)
        {
            if(reverse == true)
            {
                st.push(root);
                root = root->right;
            }
            else
            {
                st.push(root);
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k)
    {
        if(root == NULL)
            return false;
        BSTIterator l(root,false);
        BSTIterator r(root,true);
        int i = l.next();
        int j = r.next();
        
        while(i<j)
        {
            if(i+j == k)
                return true;
            if(i+j < k)
            {
                i = l.next();
            }
            else
            {
                j = r.next();
            }
            
        }
        return false;
    }
};
