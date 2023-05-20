class Solution {
    private:
    void findsubset(int ind,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans,int n)
    {
        ans.push_back(ds);
        for(int i=ind;i<n;i++)
        {
            if(i!=ind && nums[i] == nums[i-1])continue;
            
            ds.push_back(nums[i]);
            findsubset(i+1,nums,ds,ans,n);
            ds.pop_back();
        
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        findsubset(0,nums,ds,ans,n);
        return ans;
    }
};
