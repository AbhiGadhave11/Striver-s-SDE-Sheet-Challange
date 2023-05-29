class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* node) 
    {
       
        vector<vector<int>>ans;
        if(node == NULL)
            return ans;
        queue<TreeNode *>q;
     
      q.push(node);
      while(q.empty()!=true)
      {
          int size = q.size();
          vector<int>v;
          while(size-- != 0)
          {
              TreeNode *temp = q.front();
              v.push_back(temp->val);
              q.pop();
              if(temp->left != NULL)
              {
                  q.push(temp->left);
              }
              if(temp->right != NULL)
              {
                  q.push(temp->right);
              }
          }
          ans.push_back(v);
          v.clear();
      }
      return ans;
        
    }
};
