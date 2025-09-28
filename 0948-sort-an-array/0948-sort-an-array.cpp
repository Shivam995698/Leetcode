class Solution {
public:
    int partition(int low, int high,vector<int>&nums)
    {
        int n = nums.size();
        int randomPivot = low + rand() % (high - low + 1);
        swap(nums[randomPivot], nums[high]);
        int pivot = high;
        int i = low-1;
        for(int j = low;j<high;j++)
        {
            if(nums[j]<nums[pivot])
            {
                i++;
                swap(nums[j],nums[i]);
            }
        }
        swap(nums[i+1],nums[pivot]);
        return i+1;
    }
    void quickSort(int low, int high,vector<int>&nums)
    {
        if(low<high)
        {
            int pi = partition(low,high,nums);
            quickSort(low,pi-1,nums);
            quickSort(pi+1,high,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // for(int i=0;i<n;i++)
        // {
        //     int mini = i;
        //     for(int j =i+1;j<n;j++)
        //     {
        //         if(nums[j]<nums[mini])
        //         {
        //             mini = j;
        //         }
        //     }
        //     swap(nums[i],nums[mini]);
        // }
        // return nums;
        int low = 0;
        int high = n-1;
        quickSort(low,high,nums);
        return nums;
    }
};