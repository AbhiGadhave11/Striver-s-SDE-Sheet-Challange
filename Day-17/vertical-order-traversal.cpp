class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>ans;
        map<int,map<int,multiset<int>>>mp; //{order,level->numbers}
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(q.size() != 0)
        {
            auto p = q.front();
            q.pop();
            TreeNode *temp = p.first;
            int order = p.second.first;
            int level = p.second.second;
            mp[order][level].insert(temp->val);
            if(temp->left != NULL)
                q.push({temp->left,{order-1,level+1}});
            if(temp->right != NULL)
                q.push({temp->right,{order+1,level+1}});
        }
        for(auto &it : mp)
        {
            vector<int>v;
            for(auto &jt : it.second)
            {
                for(auto &no : jt.second)
                {
                    v.push_back(no);
                }
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};
