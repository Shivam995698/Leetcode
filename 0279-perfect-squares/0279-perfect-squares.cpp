class Solution {
public:
    int solve(int n,vector<int>&dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(n<0)
        {
            return 0; 
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans = INT_MAX;
        int i =1;
        int end = sqrt(n);
        while(i<=end){
            int perfectsq = i*i;
            int number = 1+solve(n-perfectsq,dp);
            ans = min(ans,number);
            i++;
        }
        dp[n]=ans;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp)-1;
    }
};