class Solution {
public:
    int gcd(int a,int b)
    {
        if(a==0)
        {
            return b;
        }
        if(b==0)
        {
            return a;
        }
        if(a==b)
        {
            return a;
        }
        if(a>b)
        {
            return gcd(a-b,b);
        }
        return gcd(a,b-a);
    }
    int findGCD(vector<int>& nums) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            mini = min(mini,nums[i]);
            maxi = max(maxi,nums[i]);
        }
        int ans = gcd(mini,maxi);
        return ans;
    }
};