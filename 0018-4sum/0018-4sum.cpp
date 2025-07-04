class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])continue;
            // else{}
            for(int j =i+1;j<n;j++)
            {
                // int k = j+1;
                // int l = n-1;
                if(j>i+1 && nums[j]==nums[j-1])continue;
                
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    vector<int>ans1;
                    long long sum =1LL*nums[i]+nums[j]+nums[k]+nums[l];
                    if(sum==target)
                    {
                        ans1.push_back(nums[i]);
                        ans1.push_back(nums[j]);
                        ans1.push_back(nums[k]);
                        ans1.push_back(nums[l]);
                        ans.push_back(ans1);
                        k++;
                        l--;                        
                        while(k<l && nums[k]==nums[k-1]) k++;
                        while(k<l && nums[l]==nums[l+1]) l--;
                    

                    
                    }
                    else if(sum<target)
                    {
                        k++;
                    }
                    else if(sum>target){
                        l--;
                    }
                }

            }
        }
        return ans;
    }
};