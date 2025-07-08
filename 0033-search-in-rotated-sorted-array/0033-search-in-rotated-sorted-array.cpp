class Solution {
public:
    int solve(vector<int>&nums,int left,int right,int target)
    {
        int ans = -1;
        while(left<=right)
        {
            int mid = left+(right-left)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                break;
            }
            else if(nums[mid]>target)
            {
                right = mid-1;
            }
            else
            {
                left = mid+1;
            }
        }
        return ans;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        //finding the break point
        int index = 0;
        for(int i =0;i<n;i++)
        {
            if(i!=0 && nums[i]<nums[i-1])
            {
                index = i;
                break;
            }
        }
        // int ans1 =0;
        // if(index ==0 && nums[index]==target)
        // {
        //     return index;
        // }
        // if(index-1>=0)
        int ans1 = solve(nums,0,index-1,target);
        int ans2 = solve(nums,index,n-1,target);
        if(ans1 == -1 && ans2 ==-1)
        {
            return -1;
        }
        return (ans1!=-1?ans1:ans2);

    }
};