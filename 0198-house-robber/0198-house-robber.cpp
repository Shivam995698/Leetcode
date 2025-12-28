class Solution {
public:
    int solve(int index,vector<int>nums,vector<int>&dp)
    {
        if(index>=nums.size())
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        int maxi1 = nums[index]+solve(index+2,nums,dp);
        int maxi2 = 0+solve(index+1,nums,dp);
        dp[index]=max(maxi1,maxi2);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1,-1);
        int index = 0;
        int ans = solve(index,nums,dp);
        return ans;
    }
};