class Solution {
    public int findNumbers(int[] nums) {
        int n = nums.length;
        int count = 0;
        for(int i = 0 ;i<n;i++)
        {
            int number = nums[i];
            // int n1 = String.valueOf(number).length();
            int n1 = 0;
            while(number!=0)
            {
                n1++;
                number = number/10;
            }
            if(n1!=0  && n1%2==0)
            {
                count++;
            }
        }
        return count;
    }
}