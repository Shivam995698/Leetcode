class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int index = -1;
        //finding the breaking point 
        for(int i = n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index = i;
                break;
            }
        }
        if(index==-1)
        {
            sort(nums.begin(),nums.end());
        }
        else{
                //finding the next greater element breakPoint 
                for(int i = n-1;i>index;i--)
                {
                    if(nums[i]>nums[index])
                    {
                        swap(nums[index],nums[i]);
                        break;
                    }
                }
                //sort the remaing array 
                sort(nums.begin()+index+1,nums.end());
            }
    }
};