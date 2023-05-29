#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
bool isLeaf(TreeNode<int>*root)
{
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL)
        return true;
    return false;
}

void LeftBoundry(TreeNode<int> *root, vector<int> &ans) 
{
    TreeNode<int>*temp = root;
    temp = temp->left;
    while(temp !=NULL)
    {
        if(isLeaf(temp)== false)
            ans.push_back(temp->data);
        if(temp->left != NULL)
            temp = temp->left;
        else
            temp = temp->right;
    }

}
void RightBoundry(TreeNode<int>*root,vector<int>&ans)
{
    stack<int>st;
    TreeNode<int>*temp = root;
    temp = temp->right;
    while(temp !=NULL)
    {
        if(isLeaf(temp)== false)
            st.push(temp->data);
        if(temp->right != NULL)
            temp = temp->right;
        else
            temp = temp->left;
    }
    while(st.size()!= 0)
    {
        ans.push_back(st.top());
        st.pop();
    }

}

void MidBoundry(TreeNode<int>*root,vector<int>&ans)
{
    if(root == NULL)
        return;
    
    MidBoundry(root->left, ans);
    if(root->left==NULL && root->right==NULL)
        ans.push_back(root->data);
    MidBoundry(root->right, ans);
}

vector<int> traverseBoundary(TreeNode<int>* root)
{
    vector<int>ans;
    if(isLeaf(root) == false)
        ans.push_back(root->data);
    
    LeftBoundry(root,ans);
    MidBoundry(root,ans);
    RightBoundry(root,ans);
    return ans;
    
}
