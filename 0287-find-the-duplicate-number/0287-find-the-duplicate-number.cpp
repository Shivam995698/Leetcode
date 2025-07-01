class Solution {
public:
    int findDuplicate(vector<int>& nums) {
          unordered_set<int>st;
          int n = nums.size();
          for(int i =0;i<n;i++)
          {
            int ele = nums[i];
            if(st.find(ele)!=st.end())
            {
                return ele;
            }
            else{
                st.insert(ele);
            }
          }
          return -1;
    }
};