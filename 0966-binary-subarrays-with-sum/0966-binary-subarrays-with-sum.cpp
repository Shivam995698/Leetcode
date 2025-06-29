class Solution {
public:
    int func1(vector<int>nums,int goal)
    {
        if(goal<0)
        {
            return 0;
        }
        int left =0;
        int right = 0;
        int n = nums.size();
        int sum = 0;
        int count = 0;
        while(right<nums.size())
        {
            sum+=nums[right];
            while(sum>goal)
            {
                sum-=nums[left];
                left++; 
            }
            if(sum<=goal)
            {
                count += right-left+1;
            }
            right++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n1 = func1(nums,goal);
        int n2 = func1(nums,goal-1);
        return n1-n2;
    }
};