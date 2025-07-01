class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int slow = nums[0];
        int fast = nums[0];
        while(true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(nums[slow] == nums[fast])
            {
                break;
            }
        }
        int slow2 = nums[0];
        while(slow != slow2)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        }
        return slow;
    }
};