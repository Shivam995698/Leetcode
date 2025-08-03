class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxi = Integer.MIN_VALUE;
        int n = accounts.length;
        int m = accounts[0].length;
        for(int i =0;i<n;i++)
        {
            int sum =0;
            for(int j=0;j<m;j++)
            {
                sum+=accounts[i][j];
            }
            if(sum>maxi)
            {
                maxi = sum;
            }
        }
        return maxi;
    }
}