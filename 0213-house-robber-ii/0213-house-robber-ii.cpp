class Solution {
public:
    int solve(vector<int>&nums,int index,int n,vector<int>&dp)
    {
        if(index>n)
        {
            return 0;
        }
        if(dp[index]!=-1)
        {
            return dp[index];
        }
        dp[index] = max(solve(nums,index+1,n,dp),nums[index]+solve(nums,index+2,n,dp));
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int index = 0;
        int n = nums.size();
        vector<int>dp1(n+1,-1);
        vector<int>dp2(n+1,-1);
        if(n==1)
        {
            return nums[0];
        }
        int ans = max(solve(nums,0,n-2,dp1),solve(nums,1,n-1,dp2));
        return ans;
    }
};