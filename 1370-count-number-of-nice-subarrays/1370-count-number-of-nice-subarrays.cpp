class Solution {
public:
    int func1(vector<int>&nums,int k)
    {
        int n = nums.size();
        int right = 0;
        int left =0;
        int count = 0;
        int countodd = 0;
        while(right<n)
        {
            if(nums[right]%2!=0)
            {
                count++;
            }
            while(count>k)
            {
                if(nums[left]%2!=0)
                {
                    count--;
                }
                left++;
            }
            if(count<=k)
            {
                countodd+=right-left+1;
            }
            right++;
        }
        return countodd;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n1 = func1(nums,k-1);
        int n2 = func1(nums,k);
        return n2-n1;
    }

};