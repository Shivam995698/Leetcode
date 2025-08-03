class Solution {
    static char solveCeil(char[] arr,char target)
   {
        int n = arr.length;
        int start = 0;
        int end = n-1;
        char finalans =' ';
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            // if(arr[mid]==target)
            // {
            //     finalans = arr[mid];
            //     break;
            // }
             if(arr[mid]>target)
            {
                finalans = arr[mid];
                end = mid-1;
            } 
            else{
                start = mid+1;
            }
        }
        if(finalans ==' ')
        {
            finalans = arr[0];
        }
        return finalans;
   }
    public char nextGreatestLetter(char[] letters, char target) {
        char ans = solveCeil(letters,target);
        return ans;
    }
}