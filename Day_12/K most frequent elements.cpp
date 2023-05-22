class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int>uobj;
        for(auto &it : nums)
            uobj[it]++;
        if(k> uobj.size())
            return {-1};
        
        priority_queue<pair<int,int>>pq;
        for(auto &it : uobj)
        {
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k-- != 0)
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};
