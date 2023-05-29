class Solution {
  public:
    vector <int> bottomView(Node *root) 
    {
        vector<int>ans;
        map<int,int>mp; //{line,value}
        queue<pair<Node*,int>>q;
        q.push({root,0});
        while(q.size() != 0)
        {
            Node *temp = q.front().first;
            int line = q.front().second;
            q.pop();
            mp[line] = temp->data;
            if(temp->left != NULL)
            {
                q.push({temp->left,line-1});
            }
            if(temp->right != NULL)
                q.push({temp->right,line+1});
        }
        for(auto &it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
