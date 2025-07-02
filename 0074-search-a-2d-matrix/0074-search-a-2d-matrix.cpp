class Solution {
public:
    bool search(vector<int>&nums,int target)
    {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        while(i<=j)
        {
            int mid = i+(j-i)/2;
            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[mid]<target)
            {
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool ans1 = false;
        for(int i =0;i<n;i++)
        {
            int start = matrix[i][0];
            int end =   matrix[i][m-1];
            if(start<=target && target<=end)
            {
                ans1 = search(matrix[i],target);
            }
        }
        return ans1;
    }
};