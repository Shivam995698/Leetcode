class Solution {
    public int myAtoi(String s) {
        
        long num = 0;
        //first we trim the spaces
        int i = 0;
        s = s.trim();
        int n = s.length();
        if(n==0)
        {
            return 0;
        }
        long sign = 1;
        if(s.charAt(i)=='-')
        {
            sign = -1;
            i++;
        }
        else if(s.charAt(i)=='+')
        {
            i++;
        }
        while(i<n && s.charAt(i)=='0')
        {
            i++;
        }
        while(i<n){
            if(s.charAt(i)>='0' && s.charAt(i)<='9')
            {
                long number = s.charAt(i)-'0';
                num = num*10+number;
                if(sign== 1 && num>=Integer.MAX_VALUE)
                {
                    return Integer.MAX_VALUE;
                }
                else if(sign== -1 &&  -num<=Integer.MIN_VALUE){
                    return Integer.MIN_VALUE;
                }
            }
            else{
                break;
            }
            i++;
          }
        return (int)(num*sign);
    }
}