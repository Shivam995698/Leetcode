class Solution {
public:
    int usingRecurr(vector<int>&nums,int index,vector<int>&dp)
    {
        int n = nums.size();
        if(index>=n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int include = nums[index]+usingRecurr(nums,index+2,dp);
        int exclude = 0+ usingRecurr(nums,index+1,dp);
        dp[index]=max(include,exclude);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index =0;
        int n = nums.size();
        vector<int>dp(n,-1);
        int ans = usingRecurr(nums,index,dp);
        return ans;
        
    }
};