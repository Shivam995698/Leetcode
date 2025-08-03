class Solution {
    static int findfirstOcc(int[] nums,int target)
    {
        int start = 0;
        int end = nums.length-1;
        int ans = -1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                end = mid -1;
            }
            else if(nums[mid]>target)
            {
                
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    static int findLastOcc(int[] nums,int target)
    {
        int start = 0;
        int end = nums.length-1;
        int ans = -1;
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            if(nums[mid]==target)
            {
                ans = mid;
                start = mid+1;
            }
            else if(nums[mid]>target)
            {
               
                end = mid-1;
            }
            else if(nums[mid]<target){
                
                start = mid+1;
            }
        }
        return ans;
    }
    public int[] searchRange(int[] nums, int target) {
        int n = nums.length;
        int[] ans =new int[2];
        int a = findfirstOcc(nums,target);
        int b = findLastOcc(nums,target);
        ans[0]=a;
        ans[1]=b;
        return ans;
    }
}