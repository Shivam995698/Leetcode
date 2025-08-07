class Solution {
    int solve(int n,int[] dp)
    {
        if(n==0)
        {
            return 1;
        }
        if(n==1)
        {
            return 1;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        int ans1 = solve(n-2,dp);
        int ans2 = solve(n-1,dp);
        dp[n] = ans1+ans2;
        return dp[n];
    }
    public int climbStairs(int n) {
      
        int[] arr = new int[n+1];
        Arrays.fill(arr,-1);
        int ans = solve(n,arr);
        return ans;
    }
}