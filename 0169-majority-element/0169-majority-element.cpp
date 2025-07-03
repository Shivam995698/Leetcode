class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i =0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int maxi = INT_MIN;
        int number = 0;
        for(auto i:mp)
        {
            if(i.second>maxi)
            {
                number = i.first;
                maxi = i.second;
            }
        }
        return number;
    }
};