class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) 
    {
        vector<int>ans;
        deque<int>dq;
        int i=0;
        while(i<nums.size())
        {
            if(dq.size()!= 0 && dq.front() == i-k)
            {
                dq.pop_front();
            }
            while(dq.size()!= 0 && nums[dq.back()]<nums[i])
                dq.pop_back();
            dq.push_back(i);
            if(i>=k-1)
                ans.push_back(nums[dq.front()]);
            i++;
        }
        return ans;
        
    }
};
