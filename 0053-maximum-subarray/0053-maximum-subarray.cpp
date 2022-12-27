class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN,sum = 0;
        
        for(auto &it : nums)
        {
            sum = sum + it;
            ans = max(ans,sum);
            if(sum<0)
                sum = 0;
            
        }
        return ans;
        
    }
};