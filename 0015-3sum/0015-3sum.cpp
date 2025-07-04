class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            continue;
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                vector<int>ans1;
                int sum = nums[i]+nums[j]+nums[k];
                if(sum==0 && i!=j && i!=k && j!=k)
                {
                    ans1.push_back(nums[i]);
                    ans1.push_back(nums[j]);
                    ans1.push_back(nums[k]);
                    ans.push_back(ans1);
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k]==nums[k+1]) k--;
                }
                else if(sum>0)
                {
                    k--;
                }
                else{
                    j++;
                }

            }
        }

        return ans;

    }
};