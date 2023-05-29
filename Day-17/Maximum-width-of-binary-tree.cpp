class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        queue<pair<TreeNode *,int>>q;
        int ans = 0;
        q.push({root,0});
        while(q.size() != 0)
        {
            int size = q.size();
            int minnode = q.front().second;
            int firstnode = -1,lastnode = -1;
            for(int i=0;i<size;i++)
            {
                long long node = q.front().second - minnode;
                TreeNode *temp = q.front().first;
                q.pop();
                if(i == 0)
                    firstnode = node;
                if(i == size - 1)
                    lastnode = node;
                if(temp->left != NULL)
                    q.push({temp->left,node*2+1});
                if(temp->right != NULL)
                    q.push({temp->right,2*node+2});
            }
            ans = max(ans,lastnode-firstnode+1);
        }
        return ans;
        
    }
};
