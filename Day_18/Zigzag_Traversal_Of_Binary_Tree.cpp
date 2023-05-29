class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode *>q;
        q.push(root);
       
        bool flag = true;
        while(q.size() != 0)
        {
            int size = q.size();
            vector<int>v;
            while(size-- != 0)
            {
                TreeNode *temp = q.front();
                q.pop();
                v.push_back(temp->val);
                if(temp->left != NULL)
                    q.push(temp->left);
                if(temp->right != NULL)
                    q.push(temp->right);
            }
            if(flag == true)
            {
                ans.push_back(v);
                flag = false;
            }
            else if(flag == false)
            {
                flag = true;
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
        }
        return ans;
        
    }
};
