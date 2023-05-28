class solution {
  public :
  vector<int>GetInorder(TreeNode *root)
  {
    TreeNode *curr = root;
    while(curr != NULL)
    {
      if(curr->left == NULL)
      {
        ans.push_back(curr->val);
        curr = curr->right;
      }
      else
      {
        TreeNode *prev = curr->left;
        while(prev->right != NULL && prev->right != curr)
        {
          prev = prev->right;
        }
        if(prev->right == NULL)
        {
          prev->right = curr;
          ans.push_back(curr->val);
          curr = curr->left;
        }
        else
        {
          prev->right = NULL;
          curr = curr->right;
        }
      }
    }

  }
};
