class Solution {
public:
    // int longestOnes(vector<int>& nums, int k) {
    //     //brute force 
    //     int n = nums.size();
    //     int maxlen = 0;
    //     for(int i =0;i<n;i++)
    //     {
    //         int len = 0;
    //         int zero =0;
    //         for(int j =i;j<n;j++)
    //         {
    //             if(nums[j]==0)
    //             {
    //                 zero++;
    //             }
    //             if(zero<=k)
    //             {
    //                 len = j-i+1;
    //                 maxlen = max(maxlen,len);

    //             }
    //         }
    //     }
    //     return maxlen;
    // }
    //  int longestOnes(vector<int>& nums, int k) {
    //     int n = nums.size();
    //     int left = 0;
    //     int right =0;
    //     int maxlen = 0;
    //     int zeros = 0;
    //     while(right<n)
    //     {
    //         if(nums[right]==0)
    //         {
    //             zeros++;
    //         }
    //         while(zeros>k)
    //         {
    //             if(nums[left]==0)
    //             {
    //                 zeros--;
    //             }
    //             left++;
    //         }
    //         if(zeros<=k)
    //         {
    //             int len = right-left+1;
    //             maxlen = max(len,maxlen);
    //         }
    //         right++;
    //     }
    //     return maxlen;
    //  }



        int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int right =0;
        int maxlen = 0;
        int zeros = 0;
        while(right<n)
        {
            if(nums[right]==0)
            {
                zeros++;
            }
            if(zeros>k)
            {
                if(nums[left]==0)
                {
                    zeros--;
                }
                left++;
            }
                if(zeros<=k)
                {
                    int len = right-left+1;
                    maxlen = max(maxlen,len);
                }
            
            right++;
        }
        return maxlen;
     }
};